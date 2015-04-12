#include"Wall.h"
Sprite*Wall::addWall(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto wall = Sprite::create("wall.png");
	wall->setPosition(p.x, p.y);
	Point points[3] = { Point(-80.00000, -20.00000), Point(80.00000, 20.00000),Point(80.00000, -20.00000) };
	/*Point points[4] = 
	{ Point(247.50000, 97.00000), Point(59.50000, -23.00000), Point(27.50000, -33.00000),
	Point(-162.50000, 97.00000)};
	Point points2[4] =
	{ Point(27.50000, -33.00000), Point(59.50000, -23.00000), Point(235.50000, -137.00000),
	Point(-162.50000, -153.00000) };*/

	PhysicsBody* boxBody = PhysicsBody::createPolygon(points, 4);
	//PhysicsBody* boxBody2 = PhysicsBody::createPolygon(points2, 4);

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
	//auto wall01 = Sprite::create();
	//wall01->setPhysicsBody(boxBody2);
	
	return wall;
}

