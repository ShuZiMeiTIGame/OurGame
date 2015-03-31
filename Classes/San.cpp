#include"San.h"
Sprite*San::addSan(Vec2 a,Vec2 b ,Point points[3])
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto san= Sprite::create("3.png");
	//int width = abs((a - b).x);
	//int height = abs((a - b).y);
	//san->setPosition((a.x + b.x) / 2, (a.y + b.y) / 2);
	san->setPosition(a);
	//Point points[3] = { Point(a), Point((a+b).x/2,b.y), Point(b) };
	PhysicsBody* boxBody = PhysicsBody::createPolygon(points, 3);
	//�Ƿ���������Ϊ��̬  
	//boxBody->setDynamic(false);
	//��������Ļָ���  
	boxBody->getShape(0)->setRestitution(1.0f);
	//���������Ħ����  
	boxBody->getShape(0)->setFriction(0.1f);
	//���������ܶ�  
	boxBody->getShape(0)->setDensity(1.0f);
	//��������  
	boxBody->getShape(0)->setMass(5);
	//���������Ƿ�������ϵ��Ӱ��  
	boxBody->setGravityEnable(true);
	//��������ӵ�������  
	san->setPhysicsBody(boxBody);
	return san;
}