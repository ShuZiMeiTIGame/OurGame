#include"Joint.h"

void Joint::Joint1(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sanA = Sprite::create("3.png");
	sanA->setPosition(p + Vec2(0, 0));
	Point points[3] = { Point(-29.00000, -25.00000), Point(-1.00000, 28.00000), Point(31.00000, -25.00000) };
	auto sanABody = PhysicsBody::createPolygon(points, 3);
	sanA->setPhysicsBody(sanABody);
	addChild(sanA, 1);

	auto ballB = Sprite::create("CloseNormal.png");
	ballB->setPosition(p + Vec2(-20, -30));
	auto ballBBody = PhysicsBody::createCircle(10);
	ballBBody->setGravityEnable(true);
	ballBBody->getShape(0)->setFriction(0.5f);
	ballB->setPhysicsBody(ballBBody);
	addChild(ballB, 1);

	auto ballC = Sprite::create("CloseNormal.png");
	ballC->setPosition(p + Vec2(20, -30));
	auto ballCBody = PhysicsBody::createCircle(10);
	ballCBody->setGravityEnable(true);
	ballCBody->getShape(0)->setFriction(0.5f);
	ballC->setPhysicsBody(ballCBody);
	addChild(ballC, 1);
	auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointDistance *joint1 = PhysicsJointDistance::construct(sanABody, ballBBody,
		Vec2(0, -sanA->getContentSize().height / 2), Vec2(0, 0));
	PhysicsJointDistance *joint2 = PhysicsJointDistance::construct(sanABody, ballCBody,
		Vec2(0, -sanA->getContentSize().height / 2), Vec2(0, 0));
	PhysicsJointDistance *joint3 = PhysicsJointDistance::construct(sanABody, ballBBody,
		Vec2(-30, -sanA->getContentSize().height / 2), Vec2(0, 0));
	PhysicsJointDistance *joint4 = PhysicsJointDistance::construct(sanABody, ballCBody,
		Vec2(30, -sanA->getContentSize().height / 2), Vec2(0, 0));
	world->addJoint(joint1);
	world->addJoint(joint2);
	world->addJoint(joint3);
	world->addJoint(joint4);

}

void Joint::Joint2(Vec2 a)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*for (int i = 0; i < 6; i = i + 2)
	{
	boxA = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxA->setPosition(p + Vec2(-400 + i * 100, 0));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);
	boxB = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxB->setPosition(p + Vec2(-300 + i * 100, 0));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);
	PhysicsJointLimit*joint1 = PhysicsJointLimit::construct(boxABody, boxBBody,
	Vec2(50, 0), Vec2(-50, 0), 0, 3);
	auto world = this->getScene()->getPhysicsWorld();
	world->addJoint(joint1);
	}*/
	auto boxA = Sprite::create("1.png", Rect(a.x, a.y, 50, 10));
	boxA->setPosition(a + Vec2(-200, 0));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	boxABody->setDynamic(false);
	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);
	auto boxB = Sprite::create("1.png", Rect(a.x, a.y, 50, 10));
	boxB->setPosition(a + Vec2(-150, 0));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxBBody->getShape(0)->setRestitution(0.0f);
	boxBBody->setGravityEnable(false);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);
	auto boxC = Sprite::create("1.png", Rect(a.x, a.y, 50, 10));
	boxC->setPosition(a + Vec2(-100, 0));
	auto boxCBody = PhysicsBody::createBox(boxC->getContentSize());
	boxCBody->getShape(0)->setRestitution(0.0f);
	boxCBody->setGravityEnable(false);
	boxC->setPhysicsBody(boxCBody);
	addChild(boxC, 1);
	auto boxD = Sprite::create("1.png", Rect(a.x, a.y, 50, 10));
	boxD->setPosition(a + Vec2(-50, 0));
	auto boxDBody = PhysicsBody::createBox(boxD->getContentSize());
	boxDBody->getShape(0)->setRestitution(0.0f);
	boxDBody->setGravityEnable(false);
	boxD->setPhysicsBody(boxDBody);
	addChild(boxD, 1);
	auto boxE = Sprite::create("1.png", Rect(a.x, a.y, 50, 10));
	boxE->setPosition(a + Vec2(0, 0));
	auto boxEBody = PhysicsBody::createBox(boxE->getContentSize());
	boxEBody->getShape(0)->setRestitution(0.0f);
	boxE->setPhysicsBody(boxEBody);
	addChild(boxE, 1);
	auto boxF = Sprite::create("1.png", Rect(a.x, a.y, 50, 10));
	boxF->setPosition(a + Vec2(50, 0));
	auto boxFBody = PhysicsBody::createBox(boxF->getContentSize());
	boxFBody->setDynamic(false);
	boxF->setPhysicsBody(boxFBody);
	addChild(boxF, 1);
	boxABody->getShape(0)->setRestitution(0);


	auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointLimit*joint1 = PhysicsJointLimit::construct(boxABody, boxBBody,
		Vec2(25, 0), Vec2(-25, 0), 1, 1);
	PhysicsJointLimit  *joint2 = PhysicsJointLimit::construct(boxBBody, boxCBody,
		Vec2(25, 0), Vec2(-25, 0), 1, 1);
	PhysicsJointLimit  *joint3 = PhysicsJointLimit::construct(boxCBody, boxDBody,
		Vec2(25, 0), Vec2(-25, 0), 1, 1);
	PhysicsJointLimit  *joint4 = PhysicsJointLimit::construct(boxDBody, boxEBody,
		Vec2(25, 0), Vec2(-25, 0), 1, 1);
	PhysicsJointLimit  *joint5 = PhysicsJointLimit::construct(boxEBody, boxFBody,
		Vec2(25, 0), Vec2(-25, 0), 1, 1);
	world->addJoint(joint1);
	world->addJoint(joint2);
	world->addJoint(joint3);
	world->addJoint(joint4);
	world->addJoint(joint5);
}

void Joint::Joint3(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sanA = Sprite::create("3.png");
	sanA->setPosition(p);
	Point points[3] = { Point(-29.00000, -25.00000), Point(-1.00000, 28.00000), Point(31.00000, -25.00000) };
	auto sanABody = PhysicsBody::createPolygon(points, 3);
	sanABody->setDynamic(false);
	sanA->setPhysicsBody(sanABody);
	addChild(sanA, 1);

	auto boxB = Sprite::create("1.png", Rect(p.x, p.y, 300, 20));
	boxB->setPosition(p + Vec2(0, 44));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	//boxBBody->getShape(0)->setRestitution(1);
	//boxBBody->getShape(0)->setFriction(5);
	boxBBody->setGravityEnable(true);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);

	auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointDistance*joint = PhysicsJointDistance::construct(sanABody, boxBBody,
		Vec2(0, sanA->getContentSize().height / 2), Vec2(0, -boxB->getContentSize().height / 2));
	world->addJoint(joint);

}

void Joint::Joint4(Vec2 p,PhysicsWorld*world)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto boxA = Sprite::create("1.png", Rect(620, 300, 40, 100));
	boxA->setPosition(p + Vec2(0, 0));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	boxABody->getShape(0)->setMass(10);

	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);

	auto boxB = Sprite::create("1.png", Rect(p.x, p.y, 80, 20));
	boxB->setPosition(p + Vec2(0, boxB->getContentSize().width));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxBBody->setGravityEnable(true);
	boxBBody->getShape(0)->setFriction(0.5f);
	boxBBody->setDynamic(false);
	boxBBody->getShape(0)->setRestitution(0);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);
	//PhysicsWorld *world = this->getScene()->getPhysicsWorld();
	//auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointSpring  *joint = PhysicsJointSpring::construct(boxABody, boxBBody,
		Vec2(0, 0), Vec2(0, 0), 400, 10);
	world->addJoint(joint);
}