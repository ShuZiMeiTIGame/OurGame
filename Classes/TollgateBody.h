#ifndef _TOLLGATEBODY_H_
#define _TOLLGATEBODY_H_
#include"cocos2d.h"
USING_NS_CC;
class TollgateBody:public Ref
{
public:
	TollgateBody();
	TollgateBody(int type, Vec2 pos, std::vector<Vec2>* posArray);


	static TollgateBody* createTollgateBody(int type, Vec2 pos, std::vector<Vec2>* posArray);


	void setType(int type);
	int  getType();
	void setPosition(Vec2 pos);
	Vec2 getPosition();
	std::vector<Vec2>* getPosArray();
	const static int TRIANGLE = 1;
	const static int RECT = 2;
	const static int CIRCLE = 3;
	const static int POLYGON = 4;
private:
	int _type;
	Vec2 _position;
	std::vector<Vec2>* _posArray;
};
#endif