#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor
{
public:
	static DrawNode*addSan(Vec2 a, std::vector<Vec2>* pos);//��������
	static DrawNode*addBox(Vec2 a, Vec2 b, float c);//������
	static DrawNode*addBall(Vec2 p, int r, float c);//��Բ
	static DrawNode*addPolygon( std::vector<Vec2>*pos);//�����

	void Joint1(Vec2 p, Vec2 s);//С��	//p �е� s�����εĳ��� 
	void Joint3(Vec2 p, std::vector<Vec2>* pos, float w, float h);//���ΰ� w�� h��
	void Joint4(Vec2 p1, Vec2 p2, Vec2 s1, Vec2 s2, int c1, int c2);//���������εĵ��ɰ� ����/c�ܶ�
	void Joint6(Vec2 p, Vec2 o,  int r);//��ת�ĳ�����//p �е� s�����εĳ��� r��תԲ�뾶
	//static Sprite*addBall(Vec2 a, int b);//�����
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