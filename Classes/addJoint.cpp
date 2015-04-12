#include"addJoint.h"
Sprite*Joint::addJoint(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto boxA = Sprite::create("CloseNormal.png");
	boxA->setPosition(p + Vec2(0, -5 * boxA->getContentSize().height));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	boxA->setPhysicsBody(boxABody);
	//addChild(boxA, 1);
	//
	auto boxB = Sprite::create("1.png");
	/////////////
	boxB->setPosition(p + Vec2(0, 2 * boxB->getContentSize().height));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);
	//
	auto ballC = Sprite::create("CloseNormal.png");
	ballC->setPosition(p + Vec2(0, 4 * boxB->getContentSize().height));
	auto ballCBody = PhysicsBody::createBox(ballC->getContentSize());//这里可以改物理物体的形状
	ballC->setPhysicsBody(ballCBody);
	addChild(ballC, 1);
     auto world = this->getScene()->getPhysicsWorld();

	PhysicsJointDistance* joint2 = PhysicsJointDistance::construct(boxBBody, ballCBody,
	Vec2(0, 0), Vec2(0,0));

	//world->addJoint(joint2);
	auto joint = PhysicsJointDistance::construct(boxABody, boxBBody,
		Vec2(0, 0), Vec2(0, 0));
	world->addJoint(joint);
	 auto joint3 = PhysicsJointDistance::construct(ballCBody, boxBBody,
		Vec2(50, 50), Vec2(0, 0));
	world->addJoint(joint3);
	//PhysicsJointGear
	//PhysicsJointFixed//PhysicsJointPin会绕一个点动//PhysicsJointGear会转 两个离心
	//PhysicsJointSpring刚度 阻尼//PhysicsJointGroove//PhysicsJointFixed会生成连在一起但生成位置很奇怪，刚性捆绑，当前试图将两个矩形刚体边界相连进行捆绑。
	return ballC;
}