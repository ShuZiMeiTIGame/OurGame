#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor :cocos2d::Layer
{
public:
<<<<<<< HEAD
	static DrawNode* addSan(Vec2 a, std::vector<Vec2>* pos);//std::vector<Vec2>* pos
=======
	static Sprite*addWall(Vec2 p);//ƽ̨����
	static Sprite*addSan(Vec2 a, std::vector<Vec2>* pos );//��������
>>>>>>> origin/master
	static Sprite*addBox(Vec2 a, Vec2 b, float c);//������
	static Sprite*addBall(Vec2 a, Vec2 b, int c);//��Բ
	static DrawNode* addBall(Vec2 a, int b);//�����
private:
	Layer* _layer;
	PhysicsWorld* _world;
};
#endif