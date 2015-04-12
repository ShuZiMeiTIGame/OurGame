#include"Box.h"

 Sprite* Box::addBox(Vec2 a, Vec2 b,int c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int width = abs((a - b).x);
	int height = abs((a - b).y);
	auto box = Sprite::create("1.png", Rect(a.x, a.y, width, height));
	box->setPosition((a.x+b.x)/2, (a.y+b.y)/2);
	Point boxPoint = Vec2(width, height);
	PhysicsBody* boxBody = PhysicsBody::createBox(Size (boxPoint));
	//是否设置物体为静态  
	//boxBody->setDynamic(false);
	//设置物体的恢复力  
	boxBody->getShape(0)->setRestitution(0.0f);
	//设置物体的摩擦力  
	boxBody->getShape(0)->setFriction(0.5f);
	//设置物体密度  
	boxBody->getShape(0)->setDensity(7.0f);
	//设置质量  
	boxBody->getShape(0)->setMass(c);
	//设置物体是否受重力系数影响  
	boxBody->setGravityEnable(true);
	//把物体添加到精灵中  
	box->setPhysicsBody(boxBody);
	return box;
}
