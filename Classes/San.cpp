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
	//是否设置物体为静态  
	//boxBody->setDynamic(false);
	//设置物体的恢复力  
	boxBody->getShape(0)->setRestitution(1.0f);
	//设置物体的摩擦力  
	boxBody->getShape(0)->setFriction(0.1f);
	//设置物体密度  
	boxBody->getShape(0)->setDensity(1.0f);
	//设置质量  
	boxBody->getShape(0)->setMass(5);
	//设置物体是否受重力系数影响  
	boxBody->setGravityEnable(true);
	//把物体添加到精灵中  
	san->setPhysicsBody(boxBody);
	return san;
}