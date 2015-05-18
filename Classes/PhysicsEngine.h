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

	void Joint1(Vec2 p, float w,float h,int r);//С��	
	void Joint2(Vec2 p);//
	void Joint3(Vec2 p,  std::vector<Vec2>* pos); //���ΰ� w�� h��
	void Joint4(Vec2 p1, Vec2 p2, float w1, float h1, float w2, float h2,float c1, float c2);//���������εĵ��ɰ� ����/c�ܶ�
	void Joint6(Vec2 p, float w,float h,  float r,int z);//��ת�ĳ����� r��תԲ�뾶 z��ת���ٶ�

	/*void Joint10(DrawNode*a, DrawNode*b,Vec2 aPos,Vec2 bPos,Vec2 aCen,Vec2 bCen);*/
    /*
	*w��h��
	*ʵ��
	*Joint1(Vec2(600, 600), 200, 100,10);
	*Joint4(Vec2(400, 400), Vec2(500, 500), 50, 50, 50, 50,0.5,0.5);
	*Joint6(Vec2(600, 600), 50,50, 1,-2);
	*/


	static void InitPar(Layer* layer,PhysicsWorld* world);
private:
	static Layer* _layer;
	static PhysicsWorld* _world;

};


#endif