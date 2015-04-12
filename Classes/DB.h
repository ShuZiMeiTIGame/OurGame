#include "cocos2d.h"
#include "sqlite3.h"

USING_NS_CC;

class  DB
{
 public: 

      DB(); //���ݿ⹹�캯��
     ~DB();	//���ݿ���������

     static DB* sharedDB();	//��̬�������ڷ���һ����̬���ݿ���ʵ��

     sqlite3 *pDB;//���ݿ�ָ��         
     std::string sqlstr;//SQLָ��    
     char * errMsg;//������Ϣ   
     int results;//sqlite3_exec����ֵ���ж����ݿ�����ɹ����
 
     bool OpenDBWithFileName(char *dbName);	   //�����ݿ⣬û�д����ݿ���½�
     bool CreateTableWithContent(char *dbExec); 		 //�½�һ����Ӧ���ݵı�
     bool IsTableExistedWithTableName(std::string dbExec);	   //�ж����Ƿ����
     bool GetTableDataWithContent(std::string dbExec);			//��ȡһ����
     bool InsertTableDataWithContent(std::string dbExec); 		 //����
     bool DeleteTableDataWithContent(std::string dbExec); 		  //ɾ��
     bool UpdateTableDataWithContent(std::string dbExec); 		//ˢ��
     bool ClearTableData(std::string dbExec);					 //������ݿ�
     void CloseDB();											  //�ر����ݿ�

 
 
     int GetPlayerInfoScores(std::string dbExec);   
     bool GetPassInfoIsUnlockedWithIndex(std::string dbExec);
     int GetPassInfoStartsWithIndex(std::string dbExec);  
};
