#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor :cocos2d::Layer
{
public:
	static DrawNode* addSan(Vec2 a, std::vector<Vec2>* pos);//std::vector<Vec2>* pos
	static Sprite*addBox(Vec2 a, Vec2 b, float c);//»­¾ØÐÎ
	static Sprite*addBall(Vec2 a, Vec2 b, int c);//»­Ô²
	static DrawNode* addBall(Vec2 a, int b);//Öí½ÅÇò
private:
};
#endif