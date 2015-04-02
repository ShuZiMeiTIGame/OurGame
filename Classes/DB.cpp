#include "DB.h"


DB::DB()
{
 
//=================DB========================[
        pDB =NULL;//数据库指针         
        sqlstr="";//SQL指令    
        errMsg = NULL;//错误信息   
        results=-1;//sqlite3_exec返回值   
            
 
}

DB::~DB()
{
}

DB* DB::sharedDB()
{
    static DB sharedDb;
    return &sharedDb;
}

bool  DB::OpenDBWithFileName(char *dbName)
 { 
        bool success=false;
 
        int result = sqlite3_open(dbName, &pDB);   
        if( result != SQLITE_OK )   
{
        CCLog( "open db failed ，error :%d ，cause: %s " , result, errMsg );   
        success=false;
}
else
{
  CCLog( "open db success  ");
  success=true;
}

     return success;
 } 


bool  DB::CreateTableWithContent(char *dbExec)
 { 
 bool success=false;

        int result=sqlite3_exec( pDB, dbExec , NULL, NULL, &errMsg );   
        if( result != SQLITE_OK )   
{
CCLog( "create table failed ，error :%d ，cause: %s " , result, errMsg );   
success=false;  
}
else
{
  CCLog( "create table success  ");
  success=true;
}
 
return success;
 }


 bool  DB::IsTableExistedWithTableName(std::string dbExec)
 { 
     bool success=false;  

std::string dbExecs=""; 
dbExecs.append("select count(type) from sqlite_master where type='table' and name='");
dbExecs.append(dbExec);
dbExecs.append("'");

int result=sqlite3_exec( pDB, dbExecs.c_str() , NULL, NULL, &errMsg );  
        if( result != SQLITE_OK )   
{
CCLog( "table not exist ");   
success=false;  
}
else
{
  CCLog( "table  is  existed ");
  success=true;
} 

return success;
 } 
 
				  int isExisted( void * para, int n_column, char ** column_value, char ** column_name ) 
 { 
bool *isExisted_=(bool*)para; 	 
*isExisted_=(**column_value)!='0'; 
return 0;
 }  


				  bool DB::GetTableDataWithContent(std::string dbExec)
{
bool success=false;
  
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); //   loadRecord  
        if(result != SQLITE_OK )    
{
CCLog( "get GetTableDataWithContent failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else
{
CCLog( "get GetTableDataWithContent success ");
success=true; 
}

return success;
} 

bool DB::InsertTableDataWithContent(std::string dbExec)
{
bool success=false;
 
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg );   
        if(result != SQLITE_OK )    
{
CCLog( "insert failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else
{
CCLog( "insert success  ");
success=true;
}

return success;
}

//删除数据
bool DB::DeleteTableDataWithContent(std::string dbExec)
{
bool success=false;
 
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
        if(result != SQLITE_OK )    
{
CCLog( "delete failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else
{
CCLog( "delete success  ");
success=true;
}

return success;
}



//更新数据
bool DB::UpdateTableDataWithContent(std::string dbExec)
{   
bool success=false;
 
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
        if(result != SQLITE_OK )    
{
CCLog( "update failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else
{
CCLog( "update success ");
success=true;
}

return success;
}

// 清空数据
bool DB::ClearTableData(std::string dbExec)
{
 bool success=false;
 
std::string dbExecs=""; 
dbExecs.append("delete from  ");
dbExecs.append(dbExec);
dbExecs.append(" ");

        int result = sqlite3_exec( pDB, dbExecs.c_str() , NULL, NULL, &errMsg ); 
        if(result != SQLITE_OK )    
{
CCLog( "clear failed，error:%d ，cause :%s " , result, errMsg );   
success=false;   
}
else
{
CCLog( " clear db success   ");
success=true;
}

return success;
}

//关闭数据库  
void DB::CloseDB()
{ 
        sqlite3_close(pDB);  
}


int DB::GetPlayerInfoScores(std::string dbExec)
{
bool success=false;
int scores=0;

   sqlite3_stmt *statement=NULL;    
int result =  sqlite3_prepare(pDB, dbExec.c_str() , dbExec.length(), &statement, 0);  
        if(result != SQLITE_OK )    
{
CCLog( "get GetPlayerInfo failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else 
{
CCLog( "get GetPlayerInfo success  "); 
success=true;  

while(sqlite3_step(statement) == SQLITE_ROW) 
{  
scores=sqlite3_column_int(statement, 2);  
 };  

}

return scores;
}  
 
bool DB::GetPassInfoIsUnlockedWithIndex(std::string dbExec)
{
bool success=false;
bool isUnlocked=false;

   sqlite3_stmt *statement=NULL;    
int result =  sqlite3_prepare(pDB, dbExec.c_str() , dbExec.length(), &statement, 0);  
        if(result != SQLITE_OK )    
{
CCLog( "get GetPlayerInfo failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else 
{
CCLog( "get GetPlayerInfo success  "); 
success=true;  

while(sqlite3_step(statement) == SQLITE_ROW) 
{   
(sqlite3_column_int(statement, 3)==1)?(isUnlocked=true):(isUnlocked=false);
 };  

}

return isUnlocked;
}


int DB::GetPassInfoStartsWithIndex(std::string dbExec)
{
bool success=false;
int starts=0;

   sqlite3_stmt *statement=NULL;    
int result =  sqlite3_prepare(pDB, dbExec.c_str() , dbExec.length(), &statement, 0);  
        if(result != SQLITE_OK )    
{
CCLog( "get GetPlayerInfo failed，error :%d ，cause:%s " , result, errMsg );   
success=false;   
}
else 
{
CCLog( "get GetPlayerInfo success  "); 
success=true;  

while(sqlite3_step(statement) == SQLITE_ROW) 
{  
starts=sqlite3_column_int(statement, 3);  
 };  

}

return starts;
} 
