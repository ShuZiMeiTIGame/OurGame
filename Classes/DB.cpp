#include "DB.h"


DB::DB()
{

	//=================DB========================[
	pDB =NULL;//���ݿ�ָ��         
	sqlstr="";//SQLָ��    
	errMsg = NULL;//������Ϣ   
	results=-1;//sqlite3_exec����ֵ   


}

DB::~DB()
{
}

/*
��̬��������һ��
��̬����ʵ��
*/
DB* DB::sharedDB()
{
	static DB sharedDb;
	return &sharedDb;
}

/*
��һ�����ݿ�
û�о��½�
*/
bool  DB::OpenDBWithFileName(char *dbName)
{ 
	bool success=false;

	int result = sqlite3_open(dbName, &pDB);   
	if( result != SQLITE_OK )   
	{
		CCLOG( "open db failed ��error :%d ��cause: %s " , result, errMsg );   
		success=false;
	}
	else
	{
		CCLOG( "open db success  ");
		success=true;
	}

	return success;
} 


/*����һ��������˱���ھͷ���false*/
bool  DB::CreateTableWithContent(std::string dbExec)
{ 
	bool success=false;

	int result=sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg );   
	if( result != SQLITE_OK )   
	{
		CCLOG( "create table failed ��error :%d ��cause: %s " , result, errMsg );   
		success=false;  
	}
	else
	{
		CCLOG( "create table success  ");
		success=true;
	}

	return success;
}

/*������Ƿ����*/
bool  DB::IsTableExistedWithTableName(std::string dbExec)
{ 
	bool success=false;  

	std::string dbExecs=""; 
	dbExecs.append("select count(*) from sqlite_master where type='table' and name='");
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
		CCLOG( "get GetTableDataWithContent failed��error :%d ��cause:%s " , result, errMsg );   
		success=false;   
	}
	else
	{
		CCLOG( "get GetTableDataWithContent success ");
		success=true; 
	}

	return success;
} 

/*��������*/
bool DB::InsertTableDataWithContent(std::string dbExec)
{
	bool success=false;

	int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg );   
	if(result != SQLITE_OK )    
	{
		CCLOG( "insert failed��error :%d ��cause:%s " , result, errMsg );   
		success=false;   
	}
	else
	{
		CCLOG( "insert success  ");
		success=true;
	}

	return success;
}

//ɾ������
bool DB::DeleteTableDataWithContent(std::string dbExec)
{
	bool success=false;

	int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
	if(result != SQLITE_OK )    
	{
		CCLOG( "delete failed��error :%d ��cause:%s " , result, errMsg );   
		success=false;   
	}
	else
	{
		CCLOG( "delete success  ");
		success=true;
	}

	return success;
}

//ɾ��ĳһ����
bool DB::DropTableWithTableName(std::string dbExec)
{
	bool success=false;

	int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
	if(result != SQLITE_OK )    
	{
		CCLOG( "drop table failed��error :%d ��cause:%s " , result, errMsg );   
		success=false;   
	}
	else
	{
		CCLOG( "drop table  success  ");
		success=true;
	}

	return success;
}



//��������
bool DB::UpdateTableDataWithContent(std::string dbExec)
{   
	bool success=false;

	int result = sqlite3_exec( pDB, dbExec.c_str() , NULL, NULL, &errMsg ); 
	if(result != SQLITE_OK )    
	{
		CCLOG( "update failed��error :%d ��cause:%s " , result, errMsg );   
		success=false;   
	}
	else
	{
		CCLOG( "update success ");
		success=true;
	}

	return success;
}

// �������
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
		CCLOG( "clear failed��error:%d ��cause :%s " , result, errMsg );   
		success=false;   
	}
	else
	{
		CCLOG( " clear db success   ");
		success=true;
	}

	return success;
}

//��ȡ���ű����Ϣ
Tollgate* DB::GetOneTableAllInfo(std::string dbExec,int ID)
{

	char** table; // ��ѯ���
	int r, c;     // ����������
	int level=0;
	bool isPassed=false;
	Vec2 pos;
	float X=0.0;
	float Y=0.0;

    float temp=0;
	sqlite3_get_table(pDB, dbExec.c_str(), &table, &r, &c, nullptr); 
	

	for(int i=1;i<=r;i++)
	{
		for(int j =0; j < c; j++) 
		{ 
			if(j==0)
			{
				level= (float)atof(table[i*c+j]);
				
			};
			if(j==1)
			{
				if( (float)atof(table[i*c+j])==1.0);
				{ 
				  isPassed=true;
				  
				}


			};
			if(j==3)
			{
				X= (float)atof(table[i*c+j]);
				

			};

			if(j==4)
			{
				Y= (float)atof(table[i*c+j]);
				
			};

		}
	}

	pos.x=X;
	pos.y=Y;
	
	auto Tollgateptr=Tollgate::createTollgate(level,isPassed,pos);
	std::string dbExecs="select * from pointinfo";
	char i_str[10]={0};

	itoa(ID,i_str,10);
	dbExecs.append(i_str);

	sqlite3_stmt *statement=NULL;    
	int result =  sqlite3_prepare(pDB, dbExecs.c_str() , dbExecs.length(), &statement, 0);  
	if(result != SQLITE_OK )    
	{
		CCLOG( "get GetPlayerInfo failed��error :%d " , result);   
	}
	else 
	{
		CCLOG( "get GetPlayerInfo success  "); 
		Vec2 pos,point1,point2,point3,point4,point5,point6,point7,point8;
		float radius;

		while(sqlite3_step(statement) == SQLITE_ROW) 
		{   
			int LevelID=sqlite3_column_int(statement,1)	 ;
			float Classifiaction= sqlite3_column_double(statement,2);
			if(Classifiaction==1.0)
			{	      
				pos.x=sqlite3_column_double(statement,3);
				pos.y=sqlite3_column_double(statement,4);
				
				point1.x=sqlite3_column_double(statement,6);
				point1.y=sqlite3_column_double(statement,7);

				point2.x=sqlite3_column_double(statement,8);
				point2.y=sqlite3_column_double(statement,9);

				point3.x=sqlite3_column_double(statement,10);
				point3.y=sqlite3_column_double(statement,11);

				auto bodyptr=TollgateBody::createTollgateBody(Classifiaction,pos);
				bodyptr->getPosArray()->push_back(point1);
				bodyptr->getPosArray()->push_back(point2);
				bodyptr->getPosArray()->push_back(point3);

				Tollgateptr->getbodiesArray()->pushBack(bodyptr);




			}
			if(Classifiaction==2.0)
			{
				pos.x=sqlite3_column_double(statement,3);
				pos.y=sqlite3_column_double(statement,4);

				point1.x=sqlite3_column_double(statement,6);
				point1.y=sqlite3_column_double(statement,7);

				point2.x=sqlite3_column_double(statement,8);
				point2.y=sqlite3_column_double(statement,9);

				auto bodyptr=TollgateBody::createTollgateBody(Classifiaction,pos);
				bodyptr->getPosArray()->push_back(point1);
				bodyptr->getPosArray()->push_back(point2);


				Tollgateptr->getbodiesArray()->pushBack(bodyptr);



			}
			if(Classifiaction==3.0)
			{
				pos.x=sqlite3_column_double(statement,3);
				pos.y=sqlite3_column_double(statement,4);



				radius=sqlite3_column_double(statement,5)  ;

				auto bodyptr=TollgateBody::createTollgateCircle(Classifiaction,pos,radius);
				Tollgateptr->getbodiesArray()->pushBack(bodyptr);




			}				


			if(Classifiaction==4.0)
			{
				pos.x=sqlite3_column_double(statement,3);
				pos.y=sqlite3_column_double(statement,4);

				point1.x=sqlite3_column_double(statement,6);
				point1.y=sqlite3_column_double(statement,7);

				point2.x=sqlite3_column_double(statement,8);
				point2.y=sqlite3_column_double(statement,9);

				point3.x=sqlite3_column_double(statement,10);
				point3.y=sqlite3_column_double(statement,11);

				point4.x=sqlite3_column_double(statement,12);
				point4.y=sqlite3_column_double(statement,13);

				point5.x=sqlite3_column_double(statement,14);
				point5.y=sqlite3_column_double(statement,15);

				point6.x=sqlite3_column_double(statement,16);
				point6.y=sqlite3_column_double(statement,17);

				point7.x=sqlite3_column_double(statement,18);
				point7.y=sqlite3_column_double(statement,19);

				point8.x=sqlite3_column_double(statement,20);
				point8.y=sqlite3_column_double(statement,21);

				auto bodyptr=TollgateBody::createTollgateBody(Classifiaction,pos);
				bodyptr->getPosArray()->push_back(point1);
				bodyptr->getPosArray()->push_back(point2);
				bodyptr->getPosArray()->push_back(point3);
				bodyptr->getPosArray()->push_back(point4) ;
				bodyptr->getPosArray()->push_back(point5);
				bodyptr->getPosArray()->push_back(point6);
				bodyptr->getPosArray()->push_back(point7);
				bodyptr->getPosArray()->push_back(point8);
				Tollgateptr->getbodiesArray()->pushBack(bodyptr);

			};  

		}

		return Tollgateptr;
	}

}

//�ر����ݿ�  
void DB::CloseDB()
{ 
	sqlite3_close(pDB);  
}







