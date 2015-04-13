#ifndef _PAINTINGLAYER_H_
#define _PAINTINGLAYER_H_
#include"cocos2d.h"
#include"cocos-ext.h"
USING_NS_CC;
using namespace cocos2d::extension;
class PaintingLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PaintingLayer);
	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
private:
	//触摸回调函数
	bool OnTouchBegan(Touch* touch, Event* event_);
	void OnTouchMoved(Touch* touch, Event* event_);
	void OnTouchEnded(Touch* touch, Event* event_);
	//菜单回调函数
	void OnMenuClicked(Ref* ref);
	Vec2 pre_point;
	Vec2 cur_point;
	bool isSetPosition;
	bool isBox;
	bool isTriangle;
	bool isPolygon;
	std::vector<Vec2> pointArray;
};
#endif