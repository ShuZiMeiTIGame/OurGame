#include"Wall.h"
Sprite*Wall::addWall(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto wall = Sprite::create("wall.png");
	wall->setPosition(p.x, p.y);
	Point points[3] = { Point(-80.00000, -20.00000), Point(80.00000, 20.00000), Point(80.00000, -20.00000) };
	PhysicsBody* boxBody = PhysicsBody::createPolygon(points, 3);
	//是否设置物体为静态  
	boxBody->setDynamic(false);
	//设置物体的恢复力  
	boxBody->getShape(0)->setRestitution(0.0f);
	//设置物体的摩擦力  
	boxBody->getShape(0)->setFriction(0.5f);
	//设置物体密度  
	boxBody->getShape(0)->setDensity(7.0f);
	//设置质量  
	boxBody->getShape(0)->setMass(5);
	//设置物体是否受重力系数影响  
	boxBody->setGravityEnable(true);
	//把物体添加到精灵中  
	wall->setPhysicsBody(boxBody);
	
	return wall;
}

