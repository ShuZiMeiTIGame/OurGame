#ifndef __JOINT_H__
#define __JOINT_H__
#include "cocos2d.h"
USING_NS_CC;
class Joint : public cocos2d::Layer
{
public:
	void Joint1(Vec2 p, PhysicsWorld*world);
	void Joint2(Vec2 p, PhysicsWorld*world);
	void Joint3(Vec2 p, PhysicsWorld*world);
	void Joint4(Vec2 p, PhysicsWorld*world);
private:
	PhysicsWorld *world;
};
#endif