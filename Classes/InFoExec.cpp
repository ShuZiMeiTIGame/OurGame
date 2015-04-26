#include "InFoExec.h"


InFoExec* InFoExec::m_InFoExec=nullptr;


InFoExec* InFoExec::GetInStance()
{ 
	if(m_InFoExec == nullptr) {
		m_InFoExec = new InFoExec();
	}
	return  m_InFoExec;
}

bool InFoExec::ExecInsert(std::string TableName,int Clasification,int Id,std::vector <float> &info)
{
	static int   d=1;
	char i_string[10]={0};

	if(Clasification==1)
	{
		int ix=0;
		static int md=1;
		char* a=nullptr;
		for ( std::vector<float>::iterator m = info.begin(); m != info.end(); m++ )
		{ 		

			CCLOG("%d",ix);
			if(ix==0)
			{
				std::string dbExecs=""; 
				dbExecs.append("insert into ");
				dbExecs.append(TableName);
				dbExecs.append("(passindex,playerscores,playerPosX,playerPosY) values ( ");
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(",NULL,NULL,NULL)");


				ix++;


				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}

			if(ix==1)
			{
				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set playerscores=");
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");
				ix++;
				CCLOG("%s",a);

				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}


			if(ix==2)
			{ 

				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set playerPosX=");			 
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");

				ix++;

				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}

			if(ix==3)
			{

				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set playerPosY=");
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");

				ix++;

				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}


		}

		ix=0;
		md++;
		return true;

	}
	if(Clasification==2)
	{
		int ix=0;

		for ( std::vector<float>::iterator m = info.begin(); m != info.end(); m++ )
		{ 		

			if(ix==0)
			{
				std::string dbExecs=""; 
				dbExecs.append("insert into ");
				dbExecs.append(TableName);
				dbExecs.append("(LevelID,Classifiaction,PosX,PosY,Radius,Point1X,Point1Y,Point2X,Point2Y,Point3X,Point3Y,Point4X,Point4Y,Point5X,Point5Y,Point6X,Point6Y,Point7X,Point7Y,Point8X,Point8Y) values (");
				char f_str[10]={0};
				itoa(Id,f_str,10);
				dbExecs.append(f_str); 
				dbExecs.append(",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL)");


				ix++;


				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}

			if(ix==1)
			{
				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set Classifiaction=");
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");

				ix++;
				CCLOG("%s",i_string);

				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}


			if(ix==2)
			{ 

				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set PosX=");			 
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");

				ix++;

				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}

			if(ix==3)
			{

				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set PosY=");
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");

				ix++;

				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}

			if(ix==4)
			{

				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				dbExecs.append(" set Radius=");
				char f_str[10]={0};
				sprintf(f_str,"%f",*m);
				dbExecs.append(f_str);
				dbExecs.append(" where ID=");
				dbExecs.append("(select MAX(ID) from ");
				dbExecs.append(TableName);
				dbExecs.append(")");

				ix++;
				CCLOG("%d",ix);
				DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;
			}

			if(ix>4)
			{			   

				char i_sringone[10]={0};

				std::string dbExecs=""; 
				dbExecs.append("update ");
				dbExecs.append(TableName);
				if(ix%2!=0)
				{
					CCLOG("%s","xx");
					CCLOG("%d",d);
					CCLOG("%d",ix);
					dbExecs.append(" set Point");
					itoa(d,i_sringone,10);
					dbExecs.append(i_sringone);
					dbExecs.append("X=");
					char sf_str[10]={0};
					sprintf(sf_str,"%f",*m);
					dbExecs.append(sf_str);
					dbExecs.append(" where ID=");
					dbExecs.append("(select MAX(ID) from ");
					dbExecs.append(TableName);
					dbExecs.append(")");
					ix++;
					goto loop;
				}
				if(ix%2==0)
				{
					CCLOG("%d",d);
					dbExecs.append(" set Point");						  
					itoa(d,i_sringone,10);
					dbExecs.append(i_sringone);
					dbExecs.append("Y=");
					char f_str[10]={0};
					sprintf(f_str,"%f",*m);
					dbExecs.append(f_str);	 
					dbExecs.append(" where ID=");
					dbExecs.append("(select MAX(ID) from ");
					dbExecs.append(TableName);
					dbExecs.append(")");
					ix++;
					d++;
					goto loop;

				}



				ix++;

loop:  DB::sharedDB()->InsertTableDataWithContent(dbExecs);
				continue;

			}


		}

		ix=0;
		d=1;
		return true;

	}
}


bool InFoExec::SaveAllInfo(int Clasification,int Id,std::vector <float> &info)
{ 
	if(DB::sharedDB()->OpenDBWithFileName("hahaha.db"))
	{ 
		std::string TableName ="";
		std::string dbExecs=""; 
		dbExecs.append("create table ");
		if(Clasification==1)
		{
			dbExecs.append("levelinfo");
			TableName="levelinfo" ;
			dbExecs.append("(ID integer primary key autoincrement,passindex float,playerscores float,playerPosX float,playerPosY float)");
		}

		if(Clasification==2)
		{
			dbExecs.append("pointinfo");
			TableName="pointinfo" ;
			char i_str[10]={0};
			itoa(Id,i_str,10);
			dbExecs.append(i_str);
			TableName.append(i_str);
			dbExecs.append("(ID integer primary key autoincrement,LevelID integer,Classifiaction float,PosX float,PosY float,Radius float,Point1X float,Point1Y float,Point2X float,Point2Y float,Point3X float,Point3Y float,Point4X float,Point4Y float,Point5X float,Point5Y float,Point6X float,Point6Y float,Point7X float,Point7Y float,Point8X float,Point8Y float)");
		}


		DB::sharedDB()->CreateTableWithContent(dbExecs);
		ExecInsert(TableName,Clasification,Id,info);
		DB::sharedDB()->CloseDB();
		return true;


	}
	return false;
}


Tollgate* InFoExec::Getlevelinfo(int ID)
{ 
	if(DB::sharedDB()->OpenDBWithFileName("hahaha.db"))
	{
		std::string dbExecs=""; 
		dbExecs.append("select * from ");
		dbExecs.append("levelinfo");
		dbExecs.append(" where ID=");
		char i_str[10]={0};
		itoa(ID,i_str,10);
		dbExecs.append(i_str);
		resultptr = DB::sharedDB()->GetOneTableAllInfo(dbExecs,ID);
		DB::sharedDB()->CloseDB();
		return resultptr;

	}
	return false;
}

bool InFoExec::DeleteSomeInfo(int Clasification,int ID,int LevelID)
{
	if(DB::sharedDB()->OpenDBWithFileName("hahaha.db"))
	{
		std::string dbExecs=""; 
		dbExecs.append("delete from ");
		if(Clasification==1)
		{
			dbExecs.append("levelinfo");
			dbExecs.append(" where ID=");
			char i_str[10]={0};
			itoa(LevelID, i_str, 10);
			dbExecs.append(i_str);
		}
		if(Clasification==2)
		{
			dbExecs.append("pointinfo");
			char i_str[10]={0};
			itoa(LevelID,i_str,10);
			dbExecs.append(i_str);
			dbExecs.append(" where ID=");
			itoa(ID,i_str,10);
			dbExecs.append(i_str);
			dbExecs.append(" and LevelID=");
			itoa(LevelID,i_str,10);
			dbExecs.append(i_str);

		}
		DB::sharedDB()->UpdateTableDataWithContent(dbExecs);
		DB::sharedDB()->CloseDB();
		return true;

	}

	return true;
}	


bool InFoExec::DeleteOneTable(int Clasification,int ID)
{
	if(DB::sharedDB()->OpenDBWithFileName("hahaha.db"))
	{ 
		std::string dbExecs="";
		dbExecs.append("drop table ");
		if(Clasification==1)
		{
			dbExecs.append("levelinfo");
		}

		if(Clasification==2)
		{
			dbExecs.append("pointinfo");
			char i_str[10]={0};
			itoa(ID,i_str,10);
			dbExecs.append(i_str);
		}

		DB::sharedDB()->DropTableWithTableName(dbExecs);
		DB::sharedDB()->CloseDB();

		return true;
	}
	return false;
}




