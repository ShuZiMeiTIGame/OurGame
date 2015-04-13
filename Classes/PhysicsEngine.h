<<<<<<< HEAD
#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor :cocos2d::Layer
{
public:
	static Sprite*addWall(Vec2 p);//Æ½Ì¨¸ÕÌå
	static Sprite*addSan(Vec2 a, Vec2 b, std::vector<Vec2>* pos );//»­Èý½ÇÐÎ
	static Sprite*addBox(Vec2 a, Vec2 b, float c);//»­¾ØÐÎ
	static Sprite*addBall(Vec2 a, Vec2 b, int c);//»­Ô²
	static Sprite*addBall(Vec2 a, int b);//Öí½ÅÇò
private:
};
=======
#ifndef _PHYSICS_H_
#define _PHYSICS_H_
#include"addJoint.h"
#include"Ball.h"
#include"Box.h"
#include"San.h"
#include"Wall.h"
>>>>>>> origin/master
#endif