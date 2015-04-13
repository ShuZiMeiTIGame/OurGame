#ifndef __GAMESCENETWO_H__
#define __GAMESCENETWO_H__
<<<<<<< HEAD
#include "cocos2d.h"
#include"HelloWorldScene.h"

USING_NS_CC;
class GameSceneTwo : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameSceneTwo);
	void Joint1(Vec2 p);
	void Joint2(Vec2 p);//Ð¡³µ
	void Joint3(Vec2 p);
	void onEnter();

private:
	Point a, b;
	Sprite*boxA;
	Sprite*boxB;
};
=======

>>>>>>> origin/master

#endif