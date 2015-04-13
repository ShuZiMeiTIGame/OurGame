#ifndef _GAMETIME_H_
#define _GAMETIME_H_
#include"cocos2d.h"
#include"cocos-ext.h"
#include"Tollgate.h"
#include"PhysicsEngine.h"
#include"BackgroundLayer.h"
#include"PaintingLayer.h"
USING_NS_CC;
using namespace cocos2d::extension;

class GameTime : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void onEnter();
	CREATE_FUNC(GameTime);
	void loadTollgate(int level);
	virtual void update(float df);
private:
	//多边形处理函数f
	void polyPointsProcessor(std::vector<Vec2>* points);
	//求两线段是交点
	Vec2 getIntersection(Vec2 a,Vec2 b,Vec2 c);
	Sprite* ballSprite;
};
#endif