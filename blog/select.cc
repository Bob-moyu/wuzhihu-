#include<cstdio>
#include<stdlib.h>
#include<mysql/mysql.h>
int main()
{
  //1.创建一个数据库连接句柄
  MYSQL* connect_fd = mysql_init(NULL);
      //2.和数据库建立连接（和tcp的区分开，这是在应用层建立连接）
      //连接过程需要指定一些必要信息
      //1）链接句柄
      //2）服务器的IP地址
      //3）用户名
      //4）密码
      //5）数据库名（blog_system)
      //6）服务器的端口号
      //7）unix_sock NULL
      //8) client_flag
  if(mysql_real_connect(connect_fd,"127.0.0.1","root","52emmmmWZH",
        "blog_system",3306,NULL,0)==NULL){
    printf("连接失败%s\n",mysql_error(connect_fd));
  }
  printf("连接成功\n");
  //3.设置编码方式
  mysql_set_character_set(connect_fd,"utf8");
  //4.拼装sql语句
  char sql[1024*4] = "select * from blog_table";
  //5.执行sql语句
  int ret = mysql_query(connect_fd,sql);
  if(ret < 0)
  {
    printf("执行sql语句失败%s\n",mysql_error(connect_fd));
    mysql_close(connect_fd);
    return 1;
  }
  //6.遍历结果集和，MYSQL_RES select得到的结果集合
  MYSQL_RES* result = mysql_store_result(connect_fd);
  // 1)获取集合结果中的行数和列数
  int rows = mysql_num_rows(result);
  int fields = mysql_num_fields(result);
  //2)根据行数和列数来遍历结果
  for(int i = 0;i < rows; ++i)
  {
    //一次获取一行数据
    MYSQL_ROW row = mysql_fetch_row(result);
    for(int j = 0; j < fields; ++j)
    {
      printf("%s\t",row[j]);
    }
    printf("\n");
  }
  //释放结果集合,比较容易释放
  mysql_free_result(result);
  mysql_close(connect_fd);
  return 0;
}
