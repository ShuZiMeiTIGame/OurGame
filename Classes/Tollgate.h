#ifndef _TOLLGATE_H_
#define _TOLLGATE_H_
#include"TollgateBody.h"
USING_NS_CC;
class Tollgate
{
public:
	Tollgate(int level, bool isPassed,Vec2 pos);
	static Tollgate* createTollgate(int level, bool isPassed, Vec2 pos);
	int getLevel();
	void setLevel(int level);
	bool isPassed();
	void setBallPosition(Vec2 pos);
	Vec2 getBallPostion();
	Vector<TollgateBody*>* getbodiesArray();
private:
	int _level;
	bool _isPassed;
	Vec2 _pos;
	Vector<TollgateBody*> _bodies;
};
#endif