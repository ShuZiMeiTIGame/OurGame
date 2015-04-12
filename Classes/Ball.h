#ifndef __BALL_H__
#define __BALL_H__
#include "cocos2d.h"
USING_NS_CC;

class Ball//生成圆形刚体
	//:public cocos2d::Layer
{
public:
	//began时的点，end时的点，密度
	static Sprite*addBall(Vec2 a,Vec2 b,int c);
	static Sprite*addBall(Vec2 a,int b);
	
private:

};
#endif