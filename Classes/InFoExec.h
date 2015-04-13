#include "cocos2d.h"
#include "sqlite3.h"
#include "DB.h"
#include "Tollgate.h"

USING_NS_CC;

class InFoExec
{ 

public:

	static	InFoExec* GetInStance();
	Tollgate* Getlevelinfo(int ID);

	bool SaveAllInfo(int Clasification,int Id,std::vector <float> &info);
	bool DeleteSomeInfo(int Clasification,int ID,int LevelID);
	bool DeleteOneTable(int Clasification,int ID);
	bool ExecInsert(std::string dbExec,int Clasification,int Id,std::vector <float> &info);



private:
	static InFoExec* m_InFoExec;
	std::vector<float>  result;
	Tollgate* resultptr;




};