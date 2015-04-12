#include"Wall.h"
Sprite*Wall::addWall(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto wall = Sprite::create("wall.png");
	wall->setPosition(p.x, p.y);
	Point points[3] = { Point(-80.00000, -20.00000), Point(80.00000, 20.00000), Point(80.00000, -20.00000) };
	PhysicsBody* boxBody = PhysicsBody::createPolygon(points, 3);
	//�Ƿ���������Ϊ��̬  
	boxBody->setDynamic(false);
	//��������Ļָ���  
	boxBody->getShape(0)->setRestitution(0.0f);
	//���������Ħ����  
	boxBody->getShape(0)->setFriction(0.5f);
	//���������ܶ�  
	boxBody->getShape(0)->setDensity(7.0f);
	//��������  
	boxBody->getShape(0)->setMass(5);
	//���������Ƿ�������ϵ��Ӱ��  
	boxBody->setGravityEnable(true);
	//��������ӵ�������  
	wall->setPhysicsBody(boxBody);
	
	return wall;
}

