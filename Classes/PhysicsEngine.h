<<<<<<< HEAD
#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor :cocos2d::Layer
{
public:
	static Sprite*addWall(Vec2 p);//ƽ̨����
	static Sprite*addSan(Vec2 a, Vec2 b, std::vector<Vec2>* pos );//��������
	static Sprite*addBox(Vec2 a, Vec2 b, float c);//������
	static Sprite*addBall(Vec2 a, Vec2 b, int c);//��Բ
	static Sprite*addBall(Vec2 a, int b);//�����
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