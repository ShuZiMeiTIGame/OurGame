#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor
{
public:
	static DrawNode*addSan(Vec2 a, std::vector<Vec2>* pos);//画三角形
	static DrawNode*addBox(Vec2 a, Vec2 b, float c);//画矩形
	static DrawNode*addBall(Vec2 p, int r, float c);//画圆
	static DrawNode*addPolygon( std::vector<Vec2>*pos);//多边形

	void Joint1(Vec2 p, Vec2 s);//小车	//p 中点 s长方形的长宽 
	void Joint3(Vec2 p, std::vector<Vec2>* pos, float w, float h);//跷跷板 w宽 h高
	void Joint4(Vec2 p1, Vec2 p2, Vec2 s1, Vec2 s2, int c1, int c2);//两个长方形的弹簧吧 可能/c密度
	void Joint6(Vec2 p, Vec2 o,  int r);//旋转的长方形//p 中点 s长方形的长宽 r旋转圆半径
	//static Sprite*addBall(Vec2 a, int b);//猪脚球
	//static Sprite*addsan(Vec2 a, std::vector<Vec2>*pos);
<<<<<<< HEAD
	static void init(Layer*layer, PhysicsWorld*world);
private:
 static	Layer* _layer;
 static	PhysicsWorld* _world;
=======
	static void InitPar(Layer* layer,PhysicsWorld* world);
private:
	static Layer* _layer;
	static PhysicsWorld* _world;
>>>>>>> origin/master
};


#endif