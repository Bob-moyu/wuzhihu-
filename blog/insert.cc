//#include<cstdio>
//#include<cstdlib>
//#include<mysql/mysql.h>
//int main()
//{
//  //1.创建一个数据库连接句柄
//  MYSQL* connect_fd=mysql_init(NULL);
//  //2.和数据库建立连接（和TCP有区别的，这是在应用层建立连接）
//  //连接需要一些必要的信息
//  //1）连接句柄
//  //2）服务器的IP地址
//  //3）用户名
//  //4）密码
//  //5）数据库名bolg_system
//  //6）服务器的端口号
//  //7）unix_sock NULL 
//  //8)client_flag
//  if(mysql_real_connect(connect_fd,"127.0.0.1","root","52emmmmWZH",
//        "blog_system",3306,NULL,0)==0)
//  {
//    printf("连接失败%s\n",mysql_error(connect_fd));
//  }
//  printf("连接成功\n");
//  //3.设置编码方式
//  //mysql sever部分初始安装时已经设置为utf8了，所以客户端部分也要设置为utf8
//  mysql_set_character_set(connect_fd,"utf8");
//  //4.拼接sql语句
//  printf("成功");
//  char sql[1024*4] = {0};
//  char title[] = "立一个flag";
//  char content[] = "拿30万年薪";
//  int tag_id = 1;
//  char create_time[] = "2019/08/03 19:00";
//  printf("成功");
//  sprintf(sql,"insert into blog_table values(null,'%s','%s',%d,'%s')",
//      title,content,tag_id,create_time);
//  //5.数据库执行sql语句
//  printf("成功");
//  int ret = mysql_query(connect_fd,sql);
//  if(ret < 0){
//    printf("执行sql语句失败%s\n",mysql_error(connect_fd));
//  mysql_close(connect_fd);
//  return -1;
//  }
//  mysql_close(connect_fd);
//  printf("执行成功\n");
//  return 0;
//}
 #include<cstdio>                                                                     
 #include<cstdlib>                                                       
 #include<mysql/mysql.h>              
  int main()             
    {                                       
        MYSQL* connect_fd=mysql_init(NULL);                     
        if(mysql_real_connect(connect_fd,"127.0.0.1","root","52emmmmWZH",                       
                        "blog_system",3306,NULL,0)==0)
        {
                printf("连接失败%s\n",mysql_error(connect_fd));
                    
        }
        printf("连接成功\n");
        mysql_set_character_set(connect_fd,"utf8");
        char sql[1024*4] = {0};
        char title[] = "立一个flag";                                                       
        char content[] = "拿30万年薪";
        int tag_id = 1;
        char datatime[] = "2019/08/03 19:00";
        sprintf(sql,"insert into blog_table values(null,'%s','%s','%d','%s')",
                    title,content,tag_id,datatime);
        int ret = mysql_query(connect_fd,sql);
        if(ret < 0){
                printf("执行sql语句失败%s\n",mysql_error(connect_fd));
                    mysql_close(connect_fd);
                        return -1;
                            
        }
        mysql_close(connect_fd);
        return 0;
      }  
