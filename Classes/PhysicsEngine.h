#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor :cocos2d::Layer
{
public:
	static DrawNode*addBox(Vec2 a, Vec2 b, float c);//画矩形
	static DrawNode*addBall(Vec2 p, int r, int c);//画圆
	static DrawNode*addSan(Vec2 a, std::vector<Vec2>* pos);//画三角形
	static DrawNode*addPolygon(Vec2 p, std::vector<Vec2>*pos);//多边形

	void Joint1(Vec2 p, Vec2 s, PhysicsWorld*world);//小车	//p 中点 s长方形的长宽 r圆半径
	void Joint3(Vec2 p, std::vector<Vec2>* pos, float w, float h, PhysicsWorld*world);//跷跷板 w宽 h高
	void Joint4(Vec2 p1, Vec2 p2, Vec2 s1, Vec2 s2, int c1, int c2, PhysicsWorld*world);//弹簧吧 可能/c密度
	void Joint6(Vec2 p, Vec2 o, PhysicsWorld*world, int r);//旋转的长方形//p 中点 s长方形的长宽
private:
	Layer* _layer;
	PhysicsWorld* _world;
};
#endif