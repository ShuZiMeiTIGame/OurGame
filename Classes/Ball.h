#ifndef __BALL_H__
#define __BALL_H__
#include "cocos2d.h"
USING_NS_CC;

class Ball//����Բ�θ���
	//:public cocos2d::Layer
{
public:
	//beganʱ�ĵ㣬endʱ�ĵ㣬�ܶ�
	static Sprite*addBall(Vec2 a,Vec2 b,int c);
	static Sprite*addBall(Vec2 a,int b);
	
private:

};
#endif