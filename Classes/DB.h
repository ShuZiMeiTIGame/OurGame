#include "cocos2d.h"
#include "sqlite3.h"

USING_NS_CC;

class  DB
{
 public: 

      DB(); //数据库构造函数
     ~DB();	//数据库析构函数

     static DB* sharedDB();	//静态函数用于返回一个静态数据库类实例

     sqlite3 *pDB;//数据库指针         
     std::string sqlstr;//SQL指令    
     char * errMsg;//错误信息   
     int results;//sqlite3_exec返回值（判定数据库操作成功与否）
 
     bool OpenDBWithFileName(char *dbName);	   //打开数据库，没有此数据库就新建
     bool CreateTableWithContent(char *dbExec); 		 //新建一个相应内容的表
     bool IsTableExistedWithTableName(std::string dbExec);	   //判定表是否存在
     bool GetTableDataWithContent(std::string dbExec);			//获取一个表
     bool InsertTableDataWithContent(std::string dbExec); 		 //插入
     bool DeleteTableDataWithContent(std::string dbExec); 		  //删除
     bool UpdateTableDataWithContent(std::string dbExec); 		//刷新
     bool ClearTableData(std::string dbExec);					 //清除数据库
     void CloseDB();											  //关闭数据库

 
 
     int GetPlayerInfoScores(std::string dbExec);   
     bool GetPassInfoIsUnlockedWithIndex(std::string dbExec);
     int GetPassInfoStartsWithIndex(std::string dbExec);  
};
