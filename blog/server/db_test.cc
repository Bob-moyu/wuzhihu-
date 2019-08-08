#include"db.hpp"
//使用这个程序来测试封装的MYSQL操作是否正确
void testBlogTable(){
  Json::StyledWriter writer;
  MYSQL* mysql = blog_system::MySQLInit();
 // bool ret = false;
  blog_system::BlogTable blog_table(mysql);
  Json::Value blog;
 //  blog["title"] = "你好啊"; 
 //  blog["content"] = "hello world";
 //  blog["tag_id"] = 2;
 //  blog["create_time"] = "2019/08/05";
//   Json::Value blog_out;
      blog["title"] = "初识 C 语言";
      std::string content;
     // FileUtil::ReadFile("./test_data/1.md", &content);
      blog["content"] = "nihaoa";
      blog["tag_id"] = 1;
      blog["create_time"] = "2019/05/14 12:00";
   bool ret = blog_table.Insert(blog); 
   printf("insert: %d\n",ret);
  // Json::Value blogs; 
  //  ret = blog_table.SelectAll(&blogs);
  //  printf("select all %d\n",ret);
  //  printf("%s\n",writer.write(blogs).c_str());
  //  ret =blog_table.SelectOne(1,&blog);
  //  printf("select one %d\n",ret);
  //  printf("blog: %s\n",writer.write(blog).c_str());
   // blog["blog_id"] = 1;
   // blog["title"] = "第一篇c语言博客";
   // blog["content"] = "1.变量和类型 \n是什么变量？创建一个'变量'就相当于创建一块空间";
   // blog["tag_id"] = 2;
   // blog["create_time"] = "2019/08/05";
   // Json::Value blog_out;
   // ret = blog_table.Update(blog);
   // printf("update %d\n",ret);
   // ret = blog_table.Delete(1);
 // printf("delete %d\n",ret);
  blog_system::MySQLRelease(mysql);
}
void testTagtable(){
  MYSQL* mysql = blog_system::MySQLInit();
  blog_system::TagTable tag_table(mysql);
  Json::StyledWriter writer; 
  Json::Value tag;
 // tag["tag_name"] = "C语言";
 // bool ret = tag_table.Insert(tag);
 // printf("insert %d\n",ret);
    Json::Value tags;
    bool ret = tag_table.SelectAll(&tags);
    printf("selectAll %d\n",ret);
    printf("%s\n",writer.write(tags).c_str());
 //     bool ret = tag_table.Delete(1);
 //     printf("delete %d\n",ret);
 // blog_system::MySQLRelease(mysql);
}
int main()
{
  testBlogTable();
  //testTagtable();
  return 0;
}
