///////////////////////////////////
//使用类来封装数据库操作
//////////////////////////////////
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<memory>
#include<mysql/mysql.h>
#include<jsoncpp/json/json.h>
namespace blog_system{
  static MYSQL* MySQLInit(){
    //初始化一个MySQL句柄并建立连接
    //1.创建一个句柄
    MYSQL* connect_fd = mysql_init(NULL);
    //2.和数据库建立连接
    if(mysql_real_connect(connect_fd,"127.0.0.1","root","",
          "blog_system",3306,NULL,0)==NULL){
      printf("连接失败!%s\n",mysql_error(connect_fd));
      return NULL;
    }
    printf("连接成功！\n");
    //3.设置字符编码
    mysql_set_character_set(connect_fd,"utf8");
    return connect_fd;
  }
  static void MySQLRelease(MYSQL* mysql){
    //释放句柄并断开连接
    mysql_close(mysql);
  }
  //创建一个类，用于操作博客表
  class BlogTable{
  public:
    BlogTable(MYSQL* mysql):mysql_(mysql){}
      //通过这个构造函数获取一个数据库的操作句柄
    //以下操作相关的参数都统一使用JSON的方式
    //Json::Value jsoncpp中最核心的类
    //Json::Value 就表示一个具体的json对象
    //形如
    //{
    //    title:"博客标题",
    //    connect:"博客内容",
    //    create_time:"创建时间",
    //    tag_id:"标签"
    //}
    //最大的好处是方便扩展
    bool Insert(const Json::Value& blog){
      //核心就是拼装sql语句
      const std::string& content = blog["content"].asString();
      //为什么to 的长度 size*2+1，根据文档的要求
      //char* to = new char[conten.size()*2 + 1];
      std::unique_ptr<char> to(new char[content.size() *2 + 1]);
      mysql_real_escape_string(mysql_,to.get(),content.c_str(),content.size());
      //为啥加4096，给其他内容留下4095的空间
      std::unique_ptr<char> sql(new char[content.size() *2 + 4096]);
      sprintf(sql.get(),"insert into blog_table values(null,'%s','%s',%d,'%s')",
        blog["title"].asCString(),
        to.get(),
        blog["tag_id"].asInt(),
        blog["create_time"].asCString());
      int ret = mysql_query(mysql_,sql.get());
      if(ret != 0){
        printf("执行插入博客失败！%s\n",mysql_error(mysql_));
        return false;
      }
      printf("执行插入博客成功\n");
      return true;
    }
  /*  bool Insert(const Json::Value& blog) {
      const std::string& content = blog["content"].asString();
      std::unique_ptr<char> content_escape(new char[content.size() * 2 + 1]);
      mysql_real_escape_string(mysql_, content_escape.get(), content.c_str(), content.size());
      std::unique_ptr<char> sql(new char[content.size() * 2 + 4096]);
      sprintf(sql.get(), "insert into blog_table values(null, '%s', '%s', %d,'%s')",
          blog["title"].asCString(), content_escape.get(),
          blog["tag_id"].asInt(), blog["create_time"].asCString());
      int ret = mysql_query(mysql_, sql.get());
      if (ret != 0) {
        printf("执行 sql 失败! sql=%s, %s\n", sql.get(), mysql_error(mysql_));
        return false;

      }
      return true;

    }*/
    //blogs作为一个输出型参数
    bool SelectAll(Json::Value* blogs,const std::string& tag_id = ""){
      //查找不需要很长的sql语句，所以固定长度
      char sql[1024*4] = {0};
      if(tag_id.empty()){
        //此时不需要按照tag来筛选
        sprintf(sql,"select blog_id,title,tag_id,create_time from blog_table");
      }
      else{
        //此时需要按照tag来筛选
        sprintf(sql,"select blog_id,title,tag_id,create_time from blog_table where tag_id = '%s'",tag_id.c_str());
      }
      int ret = mysql_query(mysql_,sql);
      if(ret !=0){
        printf("执行查找所有博客失败！%s\n",mysql_error(mysql_));
        return false;
      }
      printf("执行查找所有博客成功\n");
      MYSQL_RES* result = mysql_store_result(mysql_);
      if(result==NULL){
        printf("获取结果失败！%s\n",mysql_error(mysql_));
        return false;
      }
      int rows = mysql_num_rows(result);
      //遍历结果集合，把结果写到blogs参数中，返回给调用者
      for(int i = 0;i < rows; ++i)
      {
        MYSQL_ROW row = mysql_fetch_row(result);
        Json::Value blog;
        //row[]中的下标和上边select语句中的列的顺序是相关联的
        blog["blog_id"] = atoi(row[0]);
        blog["title"] = row[1];
        blog["tag_id"] = atoi(row[2]);
        blog["create_time"] = row[3];
        blogs->append(blog);
      }
      //MySQL查询的结果集合要及时释放
      mysql_free_result(result);
      printf("查找所有博客成功！共有%d条博客\n",rows);
      return true;
    }
    //blog同样是输出型参数，根据当前的blog_id在数据库中找到具体的结果
    //博客内容通过 blog 参数返回给调用者
    bool SelectOne(int32_t blog_id,Json::Value* blog){
      char sql[1024 * 4] = {0};
      sprintf(sql,"select * from blog_table where blog_id = %d",blog_id);
      int ret = mysql_query(mysql_,sql);
      if(ret != 0){
        printf("执行查找博客失败%s\n",mysql_error(mysql_));
        return false;
      }
      MYSQL_RES* result = mysql_store_result(mysql_);
      if(result == NULL){
        printf("获取结果失败！%s\n",mysql_error(mysql_));
        return false;
      }
      int rows = mysql_num_rows(result);
      if(rows != 1)
      {
        printf("查找到的博客不止一条！查找到%d 条博客\n",rows);
        return false;
      }
      MYSQL_ROW row = mysql_fetch_row(result);
      (*blog)["blog_id"] = atoi(row[0]);
      (*blog)["title"] = row[1];
      (*blog)["content"] = row[2];
      (*blog)["tag_id"] = atoi(row[3]);
      (*blog)["create_time"] = row[4];
      return true;
    }
    bool Update(const Json::Value& blog){

      //核心就是拼装sql语句
      const std::string& content = blog["content"].asString();
      //为什么to 的长度 size*2+1，根据文档的要求
      //char* to = new char[conten.size()*2 + 1];
      std::unique_ptr<char> to(new char[content.size() *2 + 1]);
      mysql_real_escape_string(mysql_,to.get(),content.c_str(),content.size());
      //为啥加4096，给其他内容留下4095的空间
      std::unique_ptr<char> sql(new char[content.size() *2 + 4096]);
      sprintf(sql.get(),"update blog_table SET title='%s',content='%s',tag_id=%d where blog_id=%d",
          blog["title"].asCString(),
          to.get(),
          blog["tag_id"].asInt(),
          blog["blog_id"].asInt());
      int ret = mysql_query(mysql_,sql.get());
      if(ret != 0){
        printf("更新博客失败!%s\n",mysql_error(mysql_));
        return false;
      }
      printf("更新博客成功！\n");
      return true;
    }
    bool Delete(int32_t blog_id){
      char sql[1024 * 4] = {0};
      sprintf(sql,"delete from blog_table where blog_id = %d",blog_id);
      int ret = mysql_query(mysql_,sql);
      if(ret != 0){
        printf("删除博客失败!%s\n",mysql_error(mysql_));
        return false;
      }
      printf("删除博客成功\n");
      return true;
    }
private:
   MYSQL* mysql_;
  };
  class TagTable{
  public:
    TagTable(MYSQL* mysql):mysql_(mysql){}
    bool Insert(const Json::Value& tag){
      char sql[1024 * 4] = {0};
      sprintf(sql,"insert into tag_table values(null,'%s')",tag["tag_name"].asCString());
      int ret = mysql_query(mysql_,sql);
      if(ret != 0){
        printf("执行插入标签失败!%s\n",mysql_error(mysql_));
        return false;
      }
      printf("执行插入标签成功\n");
      return true;
    }
    bool Delete(int32_t tag_id){
      char sql[1024 * 4] = {0};
      sprintf(sql,"delete from tag_table where tag_id = %d",tag_id); 
      int ret = mysql_query(mysql_,sql);
      if(ret != 0){
        printf("执行删除标签失败%s\n",mysql_error(mysql_));
        return false;
      }
      printf("执行删除标签成功");
      return true;
    }
    bool SelectAll(Json::Value* tags){
      char sql[1024 * 4] = {0};
      sprintf(sql,"select * from tag_table");
      int ret = mysql_query(mysql_,sql);
      if(ret != 0){
        printf("执行查找标签失败%s\n",mysql_error(mysql_));
        return false;
      }
      MYSQL_RES* result = mysql_store_result(mysql_);
      if(result == NULL){
        printf("获取结果失败！%s\n",mysql_error(mysql_));
        return false;
      }
      int rows = mysql_num_rows(result);
      //遍历结果集合，把结果写到blogs参数中，返回给调用者
      for(int i = 0;i < rows; ++i)
      {
        MYSQL_ROW row = mysql_fetch_row(result);
        Json::Value tag;
        //row[]中的下标和上边select语句中的列的顺序是相关联的
        tag["tag_id"] = atoi(row[0]);
        tag["tag_name"] = row[1];
        tags->append(tag);
      }
      mysql_free_result(result);
      return true;
    }
  private:
    MYSQL* mysql_;
};
}
