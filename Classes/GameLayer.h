#ifndef _GAMELAYER_H_
#define _GAMELAYER_H_
#include"cocos2d.h"
#include"Tollgate.h"
#include"PhysicsEngine.h"
#include"cocos-ext.h"
#include"StatusLayer.h"
#include"InFoExec.h"
using namespace cocos2d::extension;
USING_NS_CC;
class GameTime;
class GameLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GameLayer);
	Vec2 getBallPos();
	void setLevel(int level, StatusLayer* status);
	int getLevel();
	void loadTollgate(int level);
	virtual void update(float t);
	DrawNode* getBall();
	void setPhysicsWorld(PhysicsWorld*);
private:
	int _level;
	DrawNode* ballSprite;
	StatusLayer* statusLayer;
	PhysicsWorld* _phyWorld;
};
#endif