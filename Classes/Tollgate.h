#ifndef _TOLLGATE_H_
#define _TOLLGATE_H_
#include"TollgateBody.h"
USING_NS_CC;
class Tollgate
{
public:
	Tollgate(int level, bool isPassed);

	static Tollgate* createTollgate(int level, bool isPassed);

	int getLevel();
	void setLevel(int level);
	bool isPassed();

	Vector<TollgateBody*>* getbodiesArray();
private:
	int _level;
	bool _isPassed;

	Vector<TollgateBody*> _bodies;
};
#endif