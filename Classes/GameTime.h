#ifndef _GAMETIME_H_
#define _GAMETIME_H_
#include"cocos2d.h"
#include"cocos-ext.h"
USING_NS_CC;
using namespace cocos2d::extension;

class GameTime : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameTime);
	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
private:
	//�����ص�����
	bool OnTouchBegan(Touch* touch, Event* event_);
	void OnTouchMoved(Touch* touch, Event* event_);
	void OnTouchEnded(Touch* touch, Event* event_);
	//�˵��ص�����
	void OnMenuClicked(Ref* ref);
	Vec2 pre_point;
	Vec2 cur_point;
	Sprite* ballSprite;
	bool isSetPosition;
	std::vector<Vec2> pointArray;
};
#endif