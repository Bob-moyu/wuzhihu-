#include<signal.h>
#include"db.hpp"
#include"httplib.h"

MYSQL* mysql = NULL;

int main(){
  using namespace httplib;
  using namespace blog_system;
  Server server;
  //1.先和数据库建立好连接
  mysql = blog_system::MySQLInit();
  signal(SIGINT,[](int) {blog_system::MySQLRelease(mysql);exit(0);});
  //2.创建相关数据库处理对象
  BlogTable blog_table(mysql);
  TagTable tag_table(mysql);
  //3.创建服务器，并设置"路由"(HTTP协议中的路由，和IP协议的路由不一样)，此处的路由指的是把 方法 + path =>哪个处理函数 关联关系声明清楚  
  //新增博客
  server.Post("/blog",[&blog_table](const Request& req,Response& resp){
      printf("新增博客\n");
      //1.获取到请求中的body并解析成Json
      Json::Reader reader;
      Json::FastWriter writer;
      Json::Value req_json;
      Json::Value resp_json;
      bool ret = reader.parse(req.body,req_json);
      if(!ret){
      //解析出错，提示用户
      printf("解析请求失败！%s\n",req.body.c_str());
      //构造一个响应对象，告诉客户出错了
      resp_json["ok"] = false;
      resp_json["reason"] = "input data parse failed!";
      resp.status = 400;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      printf("解析成功!\n");
      //2.对参数进行校验
      if(req_json["title"].empty()|| req_json["content"].empty()||req_json["tag_id"].empty()||  req_json["create_time"].empty()){
      printf("请求的数据格式有错！%s\n",req.body.c_str());
      //构造一个响应对象，告诉客户出错了
      resp_json["ok"] = false;
      resp_json["reason"] = "input data format error!";
      resp.status = 400;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      printf("校验成功！\n");
      //3.真正的调用MYSQL语句的操作
      ret = blog_table.Insert(req_json);
      if(!ret){
        printf("插入博客失败！\n");
        resp_json["ok"] = false;
        resp_json["reason"] = "blog insert failed";
        resp.status = 500;
        resp.set_content(writer.write(resp_json),"application/json");
        return;
      }
      //4.构造一个真确的响应给客户端
      printf("插入博客成功！\n");
      resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      });
  //查看所有博客列表
  server.Get("/blog",[&blog_table](const Request& req,Response& resp){
      printf("查看所有博客!\n");
      Json::FastWriter writer;
      Json::Reader reader;
      //1.尝试获取tag_id,如果tag_id这个参数不存在，返回空字符串
      const std::string& tag_id =req.get_param_value("tag_id");
      //就不需要解析请求了，也就不需要合法性判断了
      //2.调用数据库操作获取所有博客结果
      Json::Value resp_json;
      Json::Value blogs;
      bool ret = blog_table.SelectAll(&blogs,tag_id);
      if(!ret){
      resp_json["ok"] = false;
      resp_json["reason"] = "select all failed";
      resp.status = 500;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //3.构造响应结果
      resp.set_content(writer.write(blogs),"application/json");
      return;
      });
  //查看某个博客
  server.Get(R"(/blog/(\d+))",[&blog_table](const Request& req,Response& resp){
      //1.解析获取到 blog_id
      Json::FastWriter writer;
      int32_t blog_id =std::stoi(req.matches[1]);
      printf("查看id为%d的博客！\n",blog_id);
      //2.直接调用数据库操作
      Json::Value resp_json;
      bool ret = blog_table.SelectOne(blog_id,&resp_json);
      if(!ret){
      resp_json["ok"] = false;
      resp_json["reason"] = "查看指定博客失败：" + std::to_string(blog_id);
      resp.status = 404;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //3.包装一个执行正确的响应
     // resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      });
  //修改某个博客
  server.Put(R"(/blog/(\d+))",[&blog_table](const Request& req,Response& resp){
      //1.先获取到博客id
      int32_t blog_id = std::stoi(req.matches[1]);
      printf("修改id为%d的博客！\n",blog_id);
      //2.获取请求并解析结果
      Json::Reader reader;
      Json::FastWriter writer;
      Json::Value req_json;
      Json::Value resp_json;
      bool ret = reader.parse(req.body,req_json);
      if(!ret){
      resp_json["ok"] = false;
      resp_json["reason"] = "update blog parse Request failed";
      resp.status = 400;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
   req_json["blog_id"] = blog_id;//从path>      中得到的id设置为json对象中  
      //3.校验参数是否符合预期
      if(req_json["title"].empty()|| req_json["content"].empty()|| req_json["tag_id"].empty()){
      resp_json["ok"] = false;
      resp_json["reason"] = "update blog parse Request format error";
      resp.status = 400;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //4.调用数据库操作来完成修改
      ret =blog_table.Update(req_json);
      if(!ret)
      {
      resp_json["ok"] = false;
      resp_json["reason"] = "update blog database failed";
      resp.status = 500;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //5.构造一个正确的返回结果
      resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      });
  //删除
  server.Delete(R"(/blog/(\d+))",[&blog_table](const Request& req,Response& resp){
      //1.先获取到blog_id
      Json::FastWriter writer;
      Json::Value resp_json;
      int32_t blog_id = std::stoi(req.matches[1]);
      printf("删除id为%d的博客\n",blog_id);
      //2.调用数据库操作
      bool ret = blog_table.Delete(blog_id);
      if(!ret){
      printf("执行删除失败！\n");
      resp_json["ok"] = false;
      resp_json["reason"] = "delete blog failed";
      resp.status = 500;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //3.构造一个正确的响应
      resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      });
  //新增标签
  server.Post("/tag",[&tag_table](const Request& req,Response& resp){
      Json::FastWriter writer;
      Json::Reader reader;
      Json::Value req_json;
      Json::Value resp_json;
      //1.解析请求
      bool ret = reader.parse(req.body,req_json);
      if(!ret){
      printf("插入标签失败！1\n");
      resp_json["ok"] = false;
      resp_json["reason"] = "insert tag req parse failed";
      resp.status = 400;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //2.对请求进行校验
      if(req_json["tag_name"].empty()){
      printf("插入标签失败！2\n");
      resp_json["ok"] = false;
      resp_json["reason"] = "Insert tag fomat error";
      resp.status = 400;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //3.调用数据库操作完成插入
      ret = tag_table.Insert(req_json);
      if(!ret){
      printf("插入标签失败！3\n");
      resp_json["ok"] = false;
      resp_json["reason"] = "insert tag database failed";
      resp.status = 500;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //4.返回正确的结果
      resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      });
  //删除标签
  server.Delete(R"(/tag/(\d+))",[&tag_table](const Request& req,Response& resp){
      Json::FastWriter writer;
      Json::Value resp_json;
      //1.解析出tag_id 
      int32_t tag_id = std::stoi(req.matches[1]);
      printf("删除id为%d的标签！\n",tag_id);
      //2.执行数据库操作
      bool ret = tag_table.Delete(tag_id);
      if(!ret){
      printf("删除标签失败！\n");
      resp_json["ok"] = false;
      resp_json["reason"] = "delete tag database failed";
      resp.status = 500;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //3.构造正确的响应
      resp_json["ok"] = true;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      });
  //查看所有表签
  server.Get("/tag",[&tag_table](const Request& req,Response& resp){
      //1.不需要解析参数，直接执行数据库操作
      Json::FastWriter writer;
      Json::Reader reader;
      Json::Value resp_json;
      Json::Value tags;
      bool ret = tag_table.SelectAll(&tags);
      if(!ret){
      printf("获取标签失败！\n");
      resp_json["ok"] = false;
      resp_json["reason"] = "Get tag database failed";
      resp.status = 500;
      resp.set_content(writer.write(resp_json),"application/json");
      return;
      }
      //2.构造正确的结果
      resp.set_content(writer.write(tags),"application/json");
      return;
      });
 /* server.Get("/", [](const Request& req, Response& resp) {
      (void)req;
      resp.set_content("<html>hello</html>", "text/html");

      });*/
  server.set_base_dir("./httproot");
  server.listen("0.0.0.0",9092);
  return 0;
}
