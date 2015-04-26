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

<<<<<<< HEAD
	auto san = Sprite::create("3.png");
	san->setPosition(a);
=======
>>>>>>> origin/master
	Point points[3];
	int j = 0;
	auto i = pos->begin();
	while (i != pos->end()){
		points[j++] = *i;
		i++;
	}
	Vec2 a1 = points[0];
	Vec2 a2 = points[1];
	Vec2 a3 = points[2];
	//float w = (a3 + a1).x;
	//float h = (a2 + a1).y;
	//Vec2 c = Vec2(w, h);
	//Vec2 b1 = a1 - c;
	//Vec2 b2 = a2 - c;
	//Vec2 b3 = a3 - c;
	//等腰
	//float w = (a3 - a1).x;
	//float h = (a2 - a1).y;
	//Vec2 c = Vec2(w, h);
	//Vec2 b1 = Vec2(-w / 2, -h / 2);
	//Vec2 b2 = Vec2(0, h / 2);
	//Vec2 b3 = Vec2(w / 2, -h / 2);
	//Vec2 poi[3] = { b1, b2, b3 };
	//san->setScale(2 * (a3 - a1).x / san->getContentSize().width);
//特列
	//float w = (a3 + a1).x/2;
	//float h = (a2 + a1).y/2;
	//Vec2 b2 = Vec2(a2.x - w, a2.y - h);
	//Vec2 b1 = Vec2(a1.x - w, a1.y - h);
	//Vec2 b3 = Vec2(a3.x - w, a3.y - h);
	//Vec2 poi[3] = { b1, b2, b3 };
	//setPhysics会重新设置锚点  --!!
	Vec2 poi[3] = { a1, a2, a3 };
	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, 3);
	sanBody->getShape(0)->setRestitution(0);
	sanBody->getShape(0)->setFriction(0.1f);
	sanBody->getShape(0)->setDensity(0.3f);
	auto san = Sprite::create("3.png");
	san->setPosition(a);
	san->setPhysicsBody(sanBody);
	return san;

	//DrawNode* draw = DrawNode::create();
	//draw->drawTriangle(a1, a2,a3,Color4F(1, 1, 1, 1));
	//this->addChild(draw, 1);
	//draw->setPhysicsBody(b2);
	//这个添加到三角形下面就好 b2是那个b2 = triangle->getPhysicsBody();
}
