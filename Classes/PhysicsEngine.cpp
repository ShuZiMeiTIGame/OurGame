#include"PhysicsEngine.h"

DrawNode*PhysicsWor::addBall(Vec2 p, int r, int c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 a1 = p - Vec2(r / 1.44, r / 1.44);
	Vec2 b1 = p + Vec2(r / 1.44, r / 1.44);
	int width = abs((a1 - b1).x);
	int height = abs((a1 - b1).y);
	PhysicsBody* ballBody = PhysicsBody::createCircle(width, PHYSICSBODY_MATERIAL_DEFAULT);
	ballBody->getShape(0)->setFriction(0.1f);
	ballBody->getShape(0)->setDensity(c);
	ballBody->setGravityEnable(true);
	DrawNode* draw = DrawNode::create();
	draw->setPosition(p);
	draw->setAnchorPoint(Vec2(0, 0) - Vec2(2 * c, 0));
	draw->drawDot(Vec2::ZERO, width, Color4F::WHITE);
	draw->setPhysicsBody(ballBody);
	return draw;
}

DrawNode* PhysicsWor::addBox(Vec2 a, Vec2 b, float c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int width = abs((a - b).x);
	int height = abs((a - b).y);
	Point boxPoint = Vec2(width, height);
	PhysicsBody* boxBody = PhysicsBody::createBox(Size(boxPoint));
	boxBody->getShape(0)->setRestitution(0.0f);
	boxBody->getShape(0)->setFriction(0.5f);
	boxBody->getShape(0)->setDensity(c);
	boxBody->setGravityEnable(true);
	DrawNode *draw = DrawNode::create();
	draw->drawRect(a, b, Color4F::WHITE);
	draw->setPosition((a + b) / 2);
	draw->setPhysicsBody(boxBody);
	return draw;
}

DrawNode *PhysicsWor::addSan(Vec2 a, std::vector<Vec2>* pos)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point points[3];
	Vec2 c1 = Vec2(0, 0);
	int j = 0;
	auto i = pos->begin();
	while (i != pos->end()){
		c1 += *i;
		points[j++] = *i;
		i++;
	}
	Vec2 c = c1 / j;
	Point poi[3];
	for (int i = 0; i < j; i++)
	{
		poi[i] = points[i] - c;
		
	}
	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, j, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	sanBody->getShape(0)->setRestitution(0);
	sanBody->getShape(0)->setFriction(1.0f);
	sanBody->getShape(0)->setDensity(0.5f);
	DrawNode* draw = DrawNode::create();
	draw->setPosition(a);
	draw->drawPolygon(poi, 3, Color4F::WHITE, 1, Color4F::WHITE);
	draw->setPhysicsBody(sanBody);
	return draw;
}

DrawNode*PhysicsWor::addPolygon(Vec2 p, std::vector<Vec2>* pos)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point points[20];
	Vec2 c1 = Vec2(0, 0);
	int j = 0;
	auto i = pos->begin();
	while (i != pos->end()){
		c1 += *i;
		points[j++] = *i;
		i++;
	}
	Vec2 c = c1 / j;
	Point poi[20];
	for (int i = 0; i < j; i++)
	{
		poi[i] = points[i] - c;

	}
	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, j, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	sanBody->getShape(0)->setRestitution(0);
	sanBody->getShape(0)->setFriction(1.0f);
	sanBody->getShape(0)->setDensity(0.5f);
	DrawNode* draw = DrawNode::create();
	draw->setPosition(p);
	draw->drawPolygon(poi, 3, Color4F::WHITE, 1, Color4F::WHITE);
	draw->setPhysicsBody(sanBody);
	return draw;
}

void PhysicsWor::Joint1(Vec2 p, Vec2 s, PhysicsWorld*world)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto c = PhysicsWor::addBox(p, p + s, 1);
	auto a = PhysicsWor::addBall(p + Vec2(2 * c->getContentSize().width / 3,
		-c->getContentSize().height / 2), 10, 5);
	auto b = PhysicsWor::addBall(p + Vec2(1 * c->getContentSize().width / 3,
		-c->getContentSize().height / 2), 10, 5);

	addChild(a, 1);
	addChild(b, 1);
	addChild(c, 1);
	PhysicsBody* aBody = a->getPhysicsBody();
	PhysicsBody* bBody = b->getPhysicsBody();
	PhysicsBody* cBody = c->getPhysicsBody();

	PhysicsJointDistance *joint1 = PhysicsJointDistance::construct(cBody, aBody,
		Vec2(0, a->getContentSize().height / 2), Vec2(0, 0));
	PhysicsJointDistance *joint2 = PhysicsJointDistance::construct(cBody, bBody,
		Vec2(0, b->getContentSize().height / 2), Vec2(0, 0));
	PhysicsJointDistance *joint3 = PhysicsJointDistance::construct(cBody, aBody,
		Vec2(+c->getContentSize().width / 4, a->getContentSize().height / 2), Vec2(0, 0));
	PhysicsJointDistance *joint4 = PhysicsJointDistance::construct(cBody, bBody,
		Vec2(-c->getContentSize().width / 4, b->getContentSize().height / 2), Vec2(0, 0));
	world->addJoint(joint1);
	world->addJoint(joint2);
	world->addJoint(joint3);
	world->addJoint(joint4);
}

void PhysicsWor::Joint3(Vec2 p, std::vector<Vec2>* pos, float w, float h, PhysicsWorld*world)
{
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
	int t;
	Vec2 c = (a1 + a2 + a3) / 3;
	if (a1.y < a2.y)  {
		t = a1.y, a1.y = a2.y, a2.y = t;
	}
	if (a2.y < a3.y) {
		t = a2.y, a2.y = a3.y, a3.y = t;
	}
	if (a1.y < a2.y){
		t = a1.y, a1.y = a2.y, a2.y = t;
	}
	int hi = (a1 - c).y;
	auto a = PhysicsWor::addSan(p, pos);
	addChild(a, 1);
	auto aBody = a->getPhysicsBody();
	Vec2 boxCenter = (p + Vec2(0, hi) + Vec2(0, h / 2));
	Vec2 box1 = (boxCenter + Vec2(-w / 2, h / 2));
	Vec2 box2 = (boxCenter + Vec2(w / 2, -h / 2));
	auto b = PhysicsWor::addBox(box1, box2, 0.5);
	auto bBody = b->getPhysicsBody();
	addChild(b, 1);
	PhysicsJointDistance*joint = PhysicsJointDistance::construct(aBody, bBody,
		Vec2(0, hi), Vec2(0, -b->getContentSize().height / 2));
	world->addJoint(joint);
}

void PhysicsWor::Joint4(Vec2 p1, Vec2 p2, Vec2 s1, Vec2 s2, int c1, int c2, PhysicsWorld*world)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto a = PhysicsWor::addBox(p1, p1 + s1, c1);
	auto aBody = a->getPhysicsBody();
	aBody->setDynamic(false);
	auto b = PhysicsWor::addBox(p2, p2 + s2, c2);
	auto bBody = b->getPhysicsBody();
	addChild(a, 1);
	addChild(b, 1);
	PhysicsJointSpring  *joint = PhysicsJointSpring::construct(aBody, bBody,
		Vec2(0, 0), Vec2(0, 0), 400, 10);
	world->addJoint(joint);
}

void PhysicsWor::Joint6(Vec2 p, Vec2 o, PhysicsWorld *world, int r)
{
	auto a = PhysicsWor::addBall(p, r, 5);
	auto b = PhysicsWor::addBox(p + Vec2(r, r), p + o + Vec2(r, r), 5);
	auto aBody = a->getPhysicsBody();
	aBody->setCategoryBitmask(0x0);
	aBody->setCollisionBitmask(0x0);
	aBody->setDynamic(false);
	auto bBody = b->getPhysicsBody();
	addChild(a, 1);
	addChild(b, 1);
	PhysicsJointMotor *joint1 = PhysicsJointMotor::construct(aBody, bBody, 3);
	PhysicsJointPin*joint2 = PhysicsJointPin::construct(aBody, bBody, Vec2(p));
	world->addJoint(joint1);
	world->addJoint(joint2);
}
