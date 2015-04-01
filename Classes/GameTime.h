#ifndef _GAMETIME_H_
#define _GAMETIME_H_
#include"cocos2d.h"
USING_NS_CC;
class GameTime : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameTime);
	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
private:
	//´¥Ãþ»Øµ÷º¯Êý
	bool OnTouchBegan(Touch* touch, Event* event_);
	void OnTouchMoved(Touch* touch, Event* event_);
	void OnTouchEnded(Touch* touch, Event* event_);
	Vec2 pre_point;
	Vec2 cur_point;
	std::vector<Vec2> pointArray;
};
#endif