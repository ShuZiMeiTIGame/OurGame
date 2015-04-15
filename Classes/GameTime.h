#ifndef _GAMETIME_H_
#define _GAMETIME_H_
#include"cocos2d.h"
#include"BackgroundLayer.h"
#include"GameLayer.h"
#include"PaintingLayer.h"
#include"StatusLayer.h"
USING_NS_CC;

class GameTime : public Scene
{
public:
	static Scene* create(int level);
	virtual bool init(int level);
	void newTollgate(int level);
	virtual void update(float df);
private:
	int _level;
	GameLayer* gameLayer;
	StatusLayer* statusLayer;
	//多边形处理函数f
	void polyPointsProcessor(std::vector<Vec2>* points);
	//求两线段是交点
	Vec2 getIntersection(Vec2 a,Vec2 b,Vec2 c);
};
#endif