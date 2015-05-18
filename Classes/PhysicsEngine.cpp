#include"PhysicsEngine.h"
Layer* PhysicsWor::_layer = nullptr;
PhysicsWorld* PhysicsWor::_world = nullptr;
void PhysicsWor::InitPar(Layer* layer,PhysicsWorld* world){
	_layer = layer;
	_world = world;
}

DrawNode*PhysicsWor::addBall(Vec2 p, int r, float c)
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
	// DrawPrimitives::drawSolidCircle((a + b) / 2, (a - b).x, CC_DEGREES_TO_RADIANS(90), 50, 1.0f, 1.0f);
	//return ball;
}

//Sprite*PhysicsWor::addBall(Vec2 a, int b)
//{
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	auto ball = Sprite::create("CloseNormal.png");
//	ball->setPosition(a);
//	ball->setScale(2 * b / ball->getContentSize().width);
//	PhysicsBody* ballBody = PhysicsBody::createCircle(b, PHYSICSBODY_MATERIAL_DEFAULT);
//	ballBody->getShape(0)->setFriction(0.5f);
//	ballBody->getShape(0)->setDensity(0.1f);
//	ball->setPhysicsBody(ballBody);
//	return ball;
//}

DrawNode* PhysicsWor::addBox(Vec2 a, Vec2 b, float c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float width = abs((a - b).x);
	float height = abs((a - b).y);
	Vec2 d = (a + b) / 2;

	Point boxPoint = Vec2(width, height);
	PhysicsBody* boxBody = PhysicsBody::createBox(Size(boxPoint));
	boxBody->getShape(0)->setRestitution(0.0f);
	boxBody->getShape(0)->setFriction(0.5f);
	boxBody->getShape(0)->setDensity(c);
	boxBody->setGravityEnable(true);
	DrawNode *draw = DrawNode::create();
	draw->drawSolidRect( Vec2(width, height)/2, -Vec2(width, height)/2, Color4F::WHITE);
	draw->setPosition(d);
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
	/////////////////////
	//int arrL = sizeof(points) / sizeof(points[0]);
	Point poi[3];
	for (int i = 0; i < j; i++)
	{
		poi[i] = points[i] - c;
		
	}
	///////
	/*Vec2 a1 = points[0];
	Vec2 a2 = points[1];
	Vec2 a3 = points[2];*/

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
	//float w = (a3 + a1).x / 2;
	//float h = (a2 + a1).y / 2;
	//Vec2 b2 = Vec2(a2.x - w, a2.y - h);
	//Vec2 b1 = Vec2(a1.x - w, a1.y - h);
	//Vec2 b3 = Vec2(a3.x - w, a3.y - h);
	//Vec2 poi[3] = { b1, b2, b3 };
	////

	/*Vec2 c = (a1 + a2 + a3) / 3;
	Vec2 b1 = a1 - c;
	Vec2 b2 = a2 - c;
	Vec2 b3 = a3 - c;
	Vec2 poi[3] = { b1, b2, b3 }; */
	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, j, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	sanBody->getShape(0)->setRestitution(0);
	sanBody->getShape(0)->setFriction(1.0f);
	sanBody->getShape(0)->setDensity(5);
	
	/*auto san = Sprite::create();
	san->setPosition(a);
	san->setPhysicsBody(sanBody);*/
	//sanBody->setDynamic(false);
	//sanBody->getShape(0)->recenterPoints(poi, 3, Vec2(0,0));
	DrawNode* draw = DrawNode::create();
	//draw->setAnchorPoint(Vec2::ZERO);
	//draw->setAnchorPoint(a);
	draw->setPosition(a);
	draw->drawPolygon(poi, 3, Color4F::WHITE, 1, Color4F::WHITE);
	draw->setPhysicsBody(sanBody);
	return draw;
}

DrawNode*PhysicsWor::addPolygon( std::vector<Vec2>* pos)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int size = pos->size();
	Point *points = new Point[size];
	Vec2 c1 = Vec2(0, 0);
	int j = 0;
	auto i = pos->begin();
	while (i != pos->end()){
		c1 += *i;
		points[j++] = *i;
		i++;
	}
	Vec2 c = c1 / j;
	//int arrL = sizeof(points) / sizeof(points[0]);
	int q = pos->size();
	Point *poi = new Point[size];
	//Point poi[20];
	for (int i = 0; i < j; i++)
	{
		poi[--q] = points[i] - c;
		
	}
	//Point poi[4] = { Point(530, 500), Point(380, 600), Point(530, 940), Point(680, 600) };
	PhysicsBody*polygonBody = PhysicsBody::createPolygon(poi, j, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	polygonBody->getShape(0)->setRestitution(0); 
	polygonBody->getShape(0)->setFriction(1.0f);
	polygonBody->getShape(0)->setDensity(0.5f);

	DrawNode* draw = DrawNode::create();
	draw->setPosition(c);
	draw->drawPolygon(poi, j, Color4F::WHITE, 1, Color4F::WHITE);
	draw->setPhysicsBody(polygonBody);
	return draw;
}

//DrawNode *PhysicsWor::addSan(Vec2 a, std::vector<Vec2>* pos)
//{
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//
//	Point points[3];
//	int j = 0;
//	auto i = pos->begin();
//	while (i != pos->end()){
//		points[j++] = *i;
//		i++;
//	}
//	Vec2 a1 = points[0];
//	Vec2 a2 = points[1];
//	Vec2 a3 = points[2];
//	//float w = (a3 + a1).x;
//	//float h = (a2 + a1).y;
//	//Vec2 c = Vec2(w, h);
//	//Vec2 b1 = a1 - c;
//	//Vec2 b2 = a2 - c;
//	//Vec2 b3 = a3 - c;
//	//等腰
//	//float w = (a3 - a1).x;
//	//float h = (a2 - a1).y;
//	//Vec2 c = Vec2(w, h);
//	//Vec2 b1 = Vec2(-w / 2, -h / 2);
//	//Vec2 b2 = Vec2(0, h / 2);
//	//Vec2 b3 = Vec2(w / 2, -h / 2);
//	//Vec2 poi[3] = { b1, b2, b3 };
//	//san->setScale(2 * (a3 - a1).x / san->getContentSize().width);
//	//特列
//	//float w = (a3 + a1).x / 2;
//	//float h = (a2 + a1).y / 2;
//	//Vec2 b2 = Vec2(a2.x - w, a2.y - h);
//	//Vec2 b1 = Vec2(a1.x - w, a1.y - h);
//	//Vec2 b3 = Vec2(a3.x - w, a3.y - h);
//	//Vec2 poi[3] = { b1, b2, b3 };
//	//setPhysics会重新设置锚点  --!!
//	Vec2 poi[3] = { a1, a2, a3 };
//	//PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO
//	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, 3, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
//	sanBody->getShape(0)->setRestitution(0);
//	sanBody->getShape(0)->setFriction(1.0f);
//	//sanBody->setGravityEnable(false);
//	sanBody->getShape(0)->setDensity(0.0f);
//	sanBody->getShape(0)->setMass(200);
//	/*auto san = Sprite::create();
//	san->setPosition(a);
//	san->setPhysicsBody(sanBody);*/
//	//sanBody->setDynamic(false);
//	//sanBody->getShape(0)->recenterPoints(poi, 3, Vec2(0,0));
//	DrawNode* draw = DrawNode::create();
//	//draw->setAnchorPoint(Vec2::ZERO);
//	draw->drawTriangle(a1, a2, a3, Color4F(1, 1, 1, 1));
//	draw->setPhysicsBody(sanBody);
//	//sanBody->getShape(0)->recenterPoints(poi, 3, Vec2::ANCHOR_MIDDLE);
//	return draw;
//
//}
//Sprite*PhysicsWor::addsan(Vec2 a, std::vector<Vec2>*pos)
//{
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Point points[3];
//	int j = 0;
//	auto i = pos->begin();
//	while (i != pos->end()){
//		points[j++] = *i;
//		i++;
//	}
//	Vec2 a1 = points[0];
//	Vec2 a2 = points[1];
//	Vec2 a3 = points[2];
//	/*float w = (a3 + a1).x / 2;
//	float h = (a2 + a1).y / 2;
//	Vec2 b2 = Vec2(a2.x - w, a2.y - h);
//	Vec2 b1 = Vec2(a1.x - w, a1.y - h);
//	Vec2 b3 = Vec2(a3.x - w, a3.y - h);
//	Vec2 poi[3] = { b1, b2, b3 };*/
//	Vec2 poi[3] = { a1, a2, a3 };
//	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, 3);
//	auto san = Sprite::create();
//	auto aa = a + Vec2(900, 200);
//	san->setPosition(aa);
//	san->setPhysicsBody(sanBody);
//	/*	DrawNode* draw = DrawNode::create();
//		draw->setAnchorPoint(Vec2::ZERO);
//		draw->drawTriangle(a1,a2,a3,Color4F(1, 1, 1, 1));
//		draw->setPhysicsBody(sanBody);*/
//	return san;
//}

void PhysicsWor::Joint1(Vec2 p,  float w, float h,int r)
{
	Vec2 s = Vec2(w, h);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto c = PhysicsWor::addBox(p, p+s , 1);
	auto a = PhysicsWor::addBall(p + Vec2(3 * w / 4, -r / 2), r, 5);
	auto b = PhysicsWor::addBall(p + Vec2(1 * w / 4, -r / 2), r, 5);
	_layer->addChild(a, 1);
	_layer->addChild(b, 1);
	_layer->addChild(c, 1);
	PhysicsBody* aBody = a->getPhysicsBody();
	PhysicsBody* bBody = b->getPhysicsBody();
	PhysicsBody* cBody = c->getPhysicsBody();
	PhysicsJointDistance *joint1 = PhysicsJointDistance::construct(cBody, aBody,
		Vec2(0, r/ 2), Vec2(0, 0));
	PhysicsJointDistance *joint2 = PhysicsJointDistance::construct(cBody, bBody,
		Vec2(0, r / 2), Vec2(0, 0));
	PhysicsJointDistance *joint3 = PhysicsJointDistance::construct(cBody, aBody,
		Vec2(+w / 4, r/ 2), Vec2(0, 0));
	PhysicsJointDistance *joint4 = PhysicsJointDistance::construct(cBody, bBody,
		Vec2(-w / 4, r/ 2), Vec2(0, 0));
	_world->addJoint(joint1);
	_world->addJoint(joint2);
	_world->addJoint(joint3);
	_world->addJoint(joint4);
}

//void PhysicsWor::Joint3(Vec2 p, PhysicsWorld*world)
//{
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	//auto sanA = Sprite::create("3.png");
//	//sanA->setPosition(p);
//	//Point points[3] = { Point(-29.00000, -25.00000), Point(-1.00000, 28.00000), Point(31.00000, -25.00000) };
//	//auto sanABody = PhysicsBody::createPolygon(points, 3);
//	//sanABody->setDynamic(false);
//	//sanA->setPhysicsBody(sanABody);
//	//addChild(sanA, 1);
//
//	//auto boxB = Sprite::create("1.png", Rect(p.x, p.y, 300, 20));
//	//boxB->setPosition(p + Vec2(0, 44));
//	//auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
//
//	//boxBBody->setGravityEnable(true);
//	//boxB->setPhysicsBody(boxBBody);
//	//addChild(boxB, 1);
//
//	//PhysicsJointDistance*joint = PhysicsJointDistance::construct(sanABody, boxBBody,
//	//	Vec2(0, sanA->getContentSize().height / 2), Vec2(0, -boxB->getContentSize().height / 2));
//	//world->addJoint(joint);

void PhysicsWor::Joint2(Vec2 p)
{
	/*Point points[3];
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
	auto aBody = a->getPhysicsBody();*/

	/*auto aBox = PhysicsWor::addBox(p, p + Vec2(350, 30), 5);
	auto bBox = PhysicsWor::addBox(p, p - Vec2(30, -60), 5);*/
	auto a = Sprite::create();
	auto aBody = PhysicsBody::create();
	Point vert1[4] = { Point(186.00000, 280.00000), Point(131.00000, 236.00000), Point(131.00000, 342.00000), Point(186.00000, 342.00000) };
	aBody->addShape(PhysicsShapePolygon::create(vert1, 4));
	Point vert2[4] = { Point(186.00000, 280.00000), Point(676.00000, 280.00000), Point(676.00000, 236.00000), Point(131.00000, 236.00000) };
	aBody->addShape(PhysicsShapePolygon::create(vert2, 4));
	a->setPhysicsBody(aBody);
	a->setPosition(p);
	_layer->addChild(a, 1);

}

void PhysicsWor::Joint3(Vec2 p, std::vector<Vec2>* pos )
{
	Point points[3];
	int j = 0;
	auto i = pos->begin();
	while (i != pos->end()){
		points[j++] = *i;
		i++;
	}
	Vec2 a4 = points[0];
	Vec2 a1 = points[1];
	Vec2 a2 = points[2];
	Vec2 a3 = points[3];

	std::vector<Vec2> poi;
	poi.push_back(a3);
	poi.push_back(a2);
	poi.push_back(a1);
	//auto a = PhysicsWor::addSan(p, &poi);
	auto a = PhysicsWor::addPolygon(&poi);
	auto aBody = a->getPhysicsBody();

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

	/*Point poi[] = { a3, a2, a1 };
	PhysicsBody*aBody = PhysicsBody::createPolygon(poi, 3, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	aBody->getShape(0)->setRestitution(0);
	aBody->getShape(0)->setFriction(1.0f);
	aBody->getShape(0)->setDensity(0.5f);

	DrawNode* a = DrawNode::create();
	a->setPosition(c);
	a->drawPolygon(poi, 3, Color4F::WHITE, 1, Color4F::WHITE);
	a->setPhysicsBody(aBody);*/
	auto w = a4.x;
	auto h = a4.y;
	Vec2 boxCenter = (p + Vec2(0, hi) + Vec2(0, h / 2));
	Vec2 box1 = (boxCenter + Vec2(-w / 2, h / 2));
	Vec2 box2 = (boxCenter + Vec2(w / 2, -h / 2));
	auto b = PhysicsWor::addBox(box1, box2, 0.5);
	auto bBody = b->getPhysicsBody();
	_layer->addChild(a, 1);
	_layer->addChild(b, 1);
	PhysicsJointDistance*joint = PhysicsJointDistance::construct(aBody, bBody,
		Vec2(0, hi), Vec2(0, -b->getContentSize().height / 2));
	_world->addJoint(joint);
}

void PhysicsWor::Joint4(Vec2 p1, Vec2 p2, float w1, float h1, float w2, float h2, float c1, float c2)
{

	Vec2 s1 = Vec2(w1, h1);
	Vec2 s2 = Vec2(w2, h2);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto a = PhysicsWor::addBox(p1, p1 + s1, c1);
	auto aBody = a->getPhysicsBody();
	aBody->setDynamic(false);
	auto b = PhysicsWor::addBox(p2, p2 + s2, c2);
	auto bBody = b->getPhysicsBody();
	_layer->addChild(a, 1);
	_layer->addChild(b, 1);
	PhysicsJointSpring  *joint = PhysicsJointSpring::construct(aBody, bBody,
		Vec2(0, 0), Vec2(0, 0), 400, 100);
	_world->addJoint(joint);
}

void PhysicsWor::Joint6(Vec2 p, float w,float h, float r,int z)
{
	Vec2 o = Vec2(w, h);
	auto a = PhysicsWor::addBall(p, r, 5);
	auto b = PhysicsWor::addBox(p + Vec2(r, r), p + o + Vec2(r, r), 5);
	auto aBody = a->getPhysicsBody();
	aBody->setCategoryBitmask(0x0);
	aBody->setCollisionBitmask(0x0);
	aBody->setDynamic(false);
	auto bBody = b->getPhysicsBody();
	bBody->setGravityEnable(false);
	_layer->addChild(a, 1);
	_layer->addChild(b, 1);
	PhysicsJointMotor *joint1 = PhysicsJointMotor::construct(aBody, bBody, z);
	PhysicsJointPin*joint2 = PhysicsJointPin::construct(aBody, bBody, Vec2(p));
	_world->addJoint(joint1);
	_world->addJoint(joint2);
}

//void PhysicsWor::Joint10(DrawNode*a, DrawNode*b, Vec2 aPos, Vec2 bPos, Vec2 aCen, Vec2 bCen)
//{
//	auto aBody = a->getPhysicsBody();
//	auto bBody = b->getPhysicsBody();
//	PhysicsJointDistance*joint = PhysicsJointDistance::construct(aBody, bBody, (aPos - aCen), (bPos - bCen));
//	_world->addJoint(joint);
//}