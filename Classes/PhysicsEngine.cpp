#include"PhysicsEngine.h"
Sprite*PhysicsWor::addWall(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto wall = Sprite::create("2.png");
	wall->setPosition(p.x, p.y);
	Point points[3] = { Point(-80.00000, -20.00000), Point(80.00000, 20.00000), Point(80.00000, -20.00000) };
	PhysicsBody* boxBody = PhysicsBody::createPolygon(points, 3);
	boxBody->getShape(0)->setRestitution(0.0f);
	boxBody->getShape(0)->setFriction(0.5f);
	boxBody->getShape(0)->setDensity(7.0f);
	boxBody->setGravityEnable(true);
	wall->setPhysicsBody(boxBody);
	return wall;
}

Sprite*PhysicsWor::addBall(Vec2 a, Vec2 b, int c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int width = abs((a - b).x);
	int height = abs((a - b).y);
	auto ball = Sprite::create("CloseNormal.png");
	ball->setScale(2 * width / ball->getContentSize().width);
	ball->setPosition((a + b) / 2);
	PhysicsBody* ballBody = PhysicsBody::createCircle(width, PHYSICSBODY_MATERIAL_DEFAULT);
	ballBody->getShape(0)->setFriction(0.1f);
	ballBody->getShape(0)->setDensity(0.0f);
	ballBody->setGravityEnable(true);
	ball->setPhysicsBody(ballBody);
	return ball;
}

Sprite*PhysicsWor::addBall(Vec2 a, int b)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto ball = Sprite::create("CloseNormal.png");
	ball->setPosition(a);
	ball->setScale(2 * b / ball->getContentSize().width);
	PhysicsBody* ballBody = PhysicsBody::createCircle(b, PHYSICSBODY_MATERIAL_DEFAULT);
	ballBody->getShape(0)->setFriction(0.5f);
	ballBody->getShape(0)->setDensity(0.1f);
	ball->setPhysicsBody(ballBody);
	return ball;
}

Sprite* PhysicsWor::addBox(Vec2 a, Vec2 b, float c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int width = abs((a - b).x);
	int height = abs((a - b).y);
	auto box = Sprite::create("1.png", Rect(a.x, a.y, width, height));
	box->setPosition((a.x + b.x) / 2, (a.y + b.y) / 2);
	Point boxPoint = Vec2(width, height);
	PhysicsBody* boxBody = PhysicsBody::createBox(Size(boxPoint));
	boxBody->getShape(0)->setRestitution(0.0f);
	boxBody->getShape(0)->setFriction(0.5f);
	boxBody->getShape(0)->setDensity(c);
	boxBody->setGravityEnable(true);
	box->setPhysicsBody(boxBody);
	return box;
}

Sprite*PhysicsWor::addSan(Vec2 a, std::vector<Vec2>* pos)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto san = Sprite::create("3.png");
	san->setPosition(a);
	Point points[3];
	int j = 0;
	auto i = pos->begin();
	while (i != pos->end()){
		points[j++] = *i;
		i++;
	}
//=======
//	san->setPosition(a); 
	
	//Point points[3];
	//int i=0;
	//auto j = pos->begin();
	//for (; j!= pos->end(); j++)
	//{
	//	points[3] = { *j };
	//	i++;
	//}
	//Vec2 a2 = points[1];
	//Vec2 b = points[2];
	//int x = abs((a2 - b).x);
	//int y = abs((a2 - b).y);
	//if (y>x)
	//{
	//	x = y;
	//}
	//san->setScale(2 *  x/ san->getContentSize().width);
	PhysicsBody*boxBody = PhysicsBody::createPolygon(points, 3);
	boxBody->getShape(0)->setRestitution(0);
	boxBody->getShape(0)->setFriction(0.1f);
	boxBody->getShape(0)->setDensity(0.3f);
	//boxBody->setGravityEnable(true);
	//boxBody->setDynamic(false);
	san->setPhysicsBody(boxBody);
	return san;
}