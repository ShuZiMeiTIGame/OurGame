#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();   
    CREATE_FUNC(HelloWorld);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	//void onEnter();
	void addBox2();
	void addBall2();
	void addSan2();
	void update(float w);
	Sprite*san01;
	Sprite*wall01;
	//
	//void drawLine(Vec2 a,Vec2 b);
	void LineBody(Vec2 a,Vec2 b);
	Point a1;
	Point b1;
	Point a2;
	Point b2;
	Point c2;
	//
	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
	void addJoint(Vec2 p);
	void addJointFixed(Vec2 p,int i);
private:
	Sprite* ball2;
	Sprite* box2;
	Sprite* san2;

	bool isBall;
	bool isBox;
	bool isSan;
	Sprite* box;
};


#endif 