#include"Joint.h"
void Joint::Joint1(Vec2 p)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto boxA = Sprite::create("1.png");
	boxA->setPosition(p + Vec2(0, 0));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	//boxABody->setDensity(false);
	boxABody->setDynamic(false);
	//boxABody->setGravityEnable(true);
	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);
	//Density ÃÜ¶È  Dynamic¶¯Ì¬


	//auto boxB = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	auto boxB = Sprite::create("1.png");
	boxB->setPosition(p + Vec2(0, -boxB->getContentSize().width));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxBBody->getShape(0)->setMass(6);
	boxBBody->setGravityEnable(true);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);

	auto world = this->getScene()->getPhysicsWorld();

	//PhysicsJointMotor*joint = PhysicsJointMotor::construct(boxBBody, boxABody, 5);
	PhysicsJointSpring  *joint = PhysicsJointSpring::construct(boxABody, boxBBody,
		Vec2(0, 0), Vec2(0, 0), 100, 1);
	world->addJoint(joint);


}