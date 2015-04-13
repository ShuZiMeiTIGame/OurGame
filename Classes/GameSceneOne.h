#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include"PhysicsEngine.h"
#include "cocos2d.h"
#include"HelloWorldScene.h"
USING_NS_CC;
class GameSceneOne : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameSceneOne);
	void update(float t);
	void Joint1(Vec2 p);
	void Joint2(Vec2 p);
	void Joint3(Vec2 p);
	void onEnter();

private:
	Point a, b;
	Sprite*boxA;
	Sprite*boxB;
};

#endif 
