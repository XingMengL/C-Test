#include <cstdio>
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include <mysql/mysql.h>


#define MYSQL_HOST "127.0.0.1"
#define MYSQL_USER "root"
#define MYSQL_PASS NULL
#define MYSQL_DB_NAME "video_system"

namespace vod_system{

  static MYSQL * MysqlInit()// 初始化
  {
    MYSQL * mysql = mysql_init(NULL);
    if(mysql == NULL)
    {
      printf("mysql init error\n");
      return NULL;
    }
    if(mysql_real_connect(mysql,MYSQL_HOST,MYSQL_USER,MYSQL_PASS,MYSQL_DB_NAME,0,NULL,0) == 0)
    {
      printf("连接失败\n");
      mysql_close(mysql);
      return NULL;
    }
    mysql_set_character_set(mysql,"utf8");
    return mysql;
  }
  static void MysqlRelease(MYSQL * mysql)// 释放资源
  {
    if(mysql)
    {
      mysql_close(mysql);
    }
    return;
  }
  static bool MysqlQuery(MYSQL * mysql,std::string &sql) // 执行语句
  {
    int ret = mysql_query(mysql,sql.c_str());
    if(ret!=0)
      return false;
    return true;
  }
  class TableVod
  {
    public:
      TableVod(MYSQL * mysql)
        :_mysql(mysql)
      {}
      bool Insert( Json::Value & video)
      {
#define INSERT_VOD "insert table_vod values(NULL,'%s','%s',%ld,'%s',now());"
        char temp[4096];
        sprintf(temp,INSERT_VOD,video["name"].asCString(),
            video["vdesc"].asCString(),
            video["vsize"].asInt64(),
            video["vurl"].asCString(),video["purl"].asCString());
        MysqlQuery(_mysql,temp);
          return true;
      }
      bool Delete(int video_id)
      {
#define DELETE_VOD "delete from table_vod where id = %d;"
        char temp[256];
        sprintf(temp,DELETE_VOD,video_id);
        MysqlQuery(_mysql,temp);
      }
      bool Update(int video_id,Json::Value & video)
      {
#define UPDATE_VOD "update table_vod set name ='%s',vdesc='%s';"
      char temp [1024];
      sprintf(temp,UPDATE_VOD,video["name"].asCString(),video["desc"].asCString());
      MysqlQuery(_mysql,temp);
        return true;
      }
      bool GetAll(Json::Value *videos);
      bool GetOne(int video_id,Json::Value *videos);
    private:
      MYSQL *_mysql;
  };
}
