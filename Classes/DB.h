#include "cocos2d.h"
#include "sqlite3.h"
#include "Tollgate.h"
#include "TollgateBody.h"

USING_NS_CC;

class  DB
{
public: 

	DB(); 
	~DB();

	static DB* sharedDB();
#include "Tollgate.h"

	sqlite3 *pDB;//���ݿ�ָ��         
	std::string sqlstr;//SQLָ��    
	char * errMsg;//������Ϣ   
	int results;//sqlite3_exec����ֵ   

	bool OpenDBWithFileName(char *dbName);
	bool CreateTableWithContent(std::string dbExec); 
	bool IsTableExistedWithTableName(std::string dbExec);
	bool GetTableDataWithContent(std::string dbExec);
	bool InsertTableDataWithContent(std::string dbExec); 
	bool DeleteTableDataWithContent(std::string dbExec); 
	bool UpdateTableDataWithContent(std::string dbExec); 
	bool DropTableWithTableName(std::string dbExec);
	bool ClearTableData(std::string dbExec);
	Tollgate* GetOneTableAllInfo(std::string dbExec,int ID);
    void CloseDB();
};
