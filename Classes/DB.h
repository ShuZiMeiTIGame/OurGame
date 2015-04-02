#include "cocos2d.h"
#include "sqlite3.h"

USING_NS_CC;

class  DB
{
 public: 

      DB(); 
     ~DB();

     static DB* sharedDB();

     sqlite3 *pDB;//数据库指针         
     std::string sqlstr;//SQL指令    
     char * errMsg;//错误信息   
     int results;//sqlite3_exec返回值   
 
     bool OpenDBWithFileName(char *dbName);
     bool CreateTableWithContent(char *dbExec); 
     bool IsTableExistedWithTableName(std::string dbExec);
     bool GetTableDataWithContent(std::string dbExec);
     bool InsertTableDataWithContent(std::string dbExec); 
     bool DeleteTableDataWithContent(std::string dbExec); 
     bool UpdateTableDataWithContent(std::string dbExec); 
     bool ClearTableData(std::string dbExec);
     void CloseDB();

 
 
     int GetPlayerInfoScores(std::string dbExec);   
     bool GetPassInfoIsUnlockedWithIndex(std::string dbExec);
     int GetPassInfoStartsWithIndex(std::string dbExec);  

};
