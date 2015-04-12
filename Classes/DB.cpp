#include "DB.h"


DB::DB()
{
 
	//djfldshldshgfl
        pDB =NULL;//数据库指针         
        sqlstr="";//SQL指令    
        errMsg = NULL;//错误信息   
        results=-1;//sqlite3_exec返回值   
            
 
}

DB::~DB()
{
}

DB* DB::sharedDB()	   //获取数据库类实例静态函数
{
    static DB sharedDb;
    return &sharedDb;
}

bool  DB::OpenDBWithFileName(char *dbName)	   //打开数据库，没有就新建
 { 
        bool success=false;
 
        int result = sqlite3_open(dbName, &pDB);   
        if( result != SQLITE_OK )   
{
        CCLOG( "open db failed ，error :%d ，cause: %s " , result, errMsg );   
        success=false;
}
else
{
  CCLOG( "open db success  ");
  success=true;
}

     return success;
} 


bool  DB::CreateTableWithContent(char *dbExec)			 //新建一个含有参数内容的表
 { 
        bool success=false;

        int result=sqlite3_exec( pDB, dbExec , NULL, NULL, &errMsg );   
        if( result != SQLITE_OK )   
{
        CCLOG( "create table failed ，error :%d ，cause: %s " , result, errMsg );   
        success=false;  
}
else
{
        CCLOG( "create table success  ");
        success=true;
}
 
        return success;
 }


 bool  DB::IsTableExistedWithTableName(std::string dbExec)	  //判定此名字的表是否存在
 { 
       bool success=false;  

       std::string dbExecs=""; 
       dbExecs.append("select count(type) from sqlite_master where type='table' and name='");
       dbExecs.append(dbExec);
       dbExecs.append("'");

       int result=sqlite3_exec( pDB, dbExecs.c_str() , NULL, NULL, &errMsg );  
       if( result != SQLITE_OK )   
{
       CCLOG( "table not exist ");   
       success=false;  
}
else
{
       CCLOG( "table  is  existed ");
       success=true;
} 

       return success;
 } 

 
 
bool DB::GetTableDataWithContent(std::string dbExec)   //获取相应内容的表
{
        bool success=false;
  
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); //   loadRecord  
        if(result != SQLITE_OK )    
{
        CCLOG( "get GetTableDataWithContent failed，error :%d ，cause:%s " , result, errMsg );   
        success=false;   
}
else
{
        CCLOG( "get GetTableDataWithContent success ");
        success=true; 
}

        return success;
} 

bool DB::InsertTableDataWithContent(std::string dbExec)//插入相应内容的数据
{
        bool success=false;
 
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg );   
        if(result != SQLITE_OK )    
{
        CCLOG( "insert failed，error :%d ，cause:%s " , result, errMsg );   
        success=false;   
}
else
{
        CCLOG( "insert success  ");
        success=true;
}

        return success;
}


bool DB::DeleteTableDataWithContent(std::string dbExec)	 //删除数据
{
        bool success=false;
 
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
        if(result != SQLITE_OK )    
{
        CCLOG( "delete failed，error :%d ，cause:%s " , result, errMsg );   
        success=false;   
}
else
{
        CCLOG( "delete success  ");
        success=true;
}

        return success;
}




bool DB::UpdateTableDataWithContent(std::string dbExec)		  //更新数据
{   
        bool success=false;
 
        int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
        if(result != SQLITE_OK )    
{
        CCLOG( "update failed，error :%d ，cause:%s " , result, errMsg );   
        success=false;   
}
else
{
       CCLOG( "update success ");
       success=true;
}

       return success;
}


bool DB::ClearTableData(std::string dbExec)	 //清空数据
{
      bool success=false;
 
      std::string dbExecs=""; 
      dbExecs.append("delete from  ");
      dbExecs.append(dbExec);
      dbExecs.append(" ");

      int result = sqlite3_exec( pDB, dbExecs.c_str() , NULL, NULL, &errMsg ); 
      if(result != SQLITE_OK )    
{
      CCLOG( "clear failed，error:%d ，cause :%s " , result, errMsg );   
      success=false;   
}
else
{
      CCLOG( " clear db success   ");
      success=true;
}

return success;
}


void DB::CloseDB()	//关闭数据库
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
      CCLOG( "get GetPlayerInfo failed，error :%d ，cause:%s " , result, errMsg );   
      success=false;   
}
else 
{
      CCLOG( "get GetPlayerInfo success  "); 
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
       CCLOG( "get GetPlayerInfo failed，error :%d ，cause:%s " , result, errMsg );   
       success=false;   
}
else 
{
       CCLOG( "get GetPlayerInfo success  "); 
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
       CCLOG( "get GetPlayerInfo failed，error :%d ，cause:%s " , result, errMsg );   
       success=false;   
}
else 
{
       CCLOG( "get GetPlayerInfo success  "); 
       success=true;  

while(sqlite3_step(statement) == SQLITE_ROW) 
{  
       starts=sqlite3_column_int(statement, 2);  
 };  

}

return starts;
} 
