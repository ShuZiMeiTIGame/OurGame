#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__
#include "cocos2d.h"
USING_NS_CC;
class PhysicsWor :cocos2d::Layer
{
public:
	static DrawNode*addBox(Vec2 a, Vec2 b, float c);//������
	static DrawNode*addBall(Vec2 p, int r, int c);//��Բ
	static DrawNode*addSan(Vec2 a, std::vector<Vec2>* pos);//��������
	static DrawNode*addPolygon(Vec2 p, std::vector<Vec2>*pos);//�����

	void Joint1(Vec2 p, Vec2 s, PhysicsWorld*world);//С��	//p �е� s�����εĳ��� rԲ�뾶
	void Joint3(Vec2 p, std::vector<Vec2>* pos, float w, float h, PhysicsWorld*world);//���ΰ� w�� h��
	void Joint4(Vec2 p1, Vec2 p2, Vec2 s1, Vec2 s2, int c1, int c2, PhysicsWorld*world);//���ɰ� ����/c�ܶ�
	void Joint6(Vec2 p, Vec2 o, PhysicsWorld*world, int r);//��ת�ĳ�����//p �е� s�����εĳ���
private:
	Layer* _layer;
	PhysicsWorld* _world;
};
#endif