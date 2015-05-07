#include"PhysicsEngine.h"

DrawNode*PhysicsWor::addBall(Vec2 a, int c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 a1 = a - Vec2(c / 1.44, c / 1.44);
	Vec2 b1 = a + Vec2(c / 1.44, c / 1.44);
	int width = abs((a1 - b1).x);
	int height = abs((a1 - b1).y);
	PhysicsBody* ballBody = PhysicsBody::createCircle(width, PHYSICSBODY_MATERIAL_DEFAULT);
	ballBody->getShape(0)->setFriction(0.1f);
	ballBody->getShape(0)->setDensity(0.0f);
	ballBody->setGravityEnable(true);
	DrawNode* draw = DrawNode::create();
	draw->setPosition(a);
	draw->setAnchorPoint(Vec2(0,0)-Vec2(2*c,0));
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
	float w = (a3 + a1).x / 2;
	float h = (a2 + a1).y / 2;
	Vec2 b2 = Vec2(a2.x - w, a2.y - h);
	Vec2 b1 = Vec2(a1.x - w, a1.y - h);
	Vec2 b3 = Vec2(a3.x - w, a3.y - h);
	Vec2 poi[3] = { b1, b2, b3 };
	//setPhysics会重新设置锚点  --!!
	//Vec2 poi[3] = { a1, a2, a3 }; 
	//PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO
	PhysicsBody*sanBody = PhysicsBody::createPolygon(poi, 3, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	sanBody->getShape(0)->setRestitution(0);
	sanBody->getShape(0)->setFriction(1.0f);
	//sanBody->setGravityEnable(false);
	sanBody->getShape(0)->setDensity(0.5f);
	/*auto san = Sprite::create();
	san->setPosition(a);
	san->setPhysicsBody(sanBody);*/
	//sanBody->setDynamic(false);
	//sanBody->getShape(0)->recenterPoints(poi, 3, Vec2(0,0));
	DrawNode* draw = DrawNode::create();
	//draw->setAnchorPoint(Vec2::ZERO);
	//draw->setAnchorPoint(a);
	draw->setPosition(a);
	draw->drawPolygon(poi,3,Color4F::WHITE,1,Color4F::WHITE);
	draw->setPhysicsBody(sanBody);
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