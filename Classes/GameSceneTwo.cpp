#include"GameSceneTwo.h"
#include"DrawBody.h"
#include"PhysicsEngine.h"
USING_NS_CC;

Scene*GameSceneTwo::createScene(){
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);	
	auto layer = GameSceneTwo::create();
	scene->getPhysicsWorld()->setGravity(Vect(0, -490));
	scene->addChild(layer);
	return scene;
}

bool GameSceneTwo::init(){
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto edgeSpace = Sprite::create();
	PhysicsBody* body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	body->getShape(0)->setFriction(0.5f);//摩擦系数
	body->getShape(0)->setRestitution(0.0f);//反弹系数
	edgeSpace->setPhysicsBody(body);	//绑定
	edgeSpace->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(edgeSpace, 1);
	////创建监听对象
	//auto Listener = EventListenerTouchOneByOne::create();
	////定义监听对象回调方法
	//Listener->onTouchBegan = CC_CALLBACK_2(GameSceneOne::onTouchBegan, this);
	//Listener->onTouchMoved = CC_CALLBACK_2(GameSceneOne::onTouchMoved, this);
	//Listener->onTouchEnded = CC_CALLBACK_2(GameSceneOne::onTouchEnded, this);
	////在时间的分发器中注册
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);


	//auto a = Sprite::create();
	//a->setPosition(300,300);
	//PhysicsBody* aBody = PhysicsBody::createCircle(300, PHYSICSBODY_MATERIAL_DEFAULT);
	////aBody->setGravityEnable(true);
	//a->setPhysicsBody(aBody);
	//addChild(a, 1);
	Point pointsOne[] = {
		Point(381.00000, 14.00000), Point(254.00000, 57.00000),
		Point(186.00000, 120.00000), Point(152.00000, 179.00000),
		Point(516.00000, 179.00000), Point(516.00000, 39.00000),
		Point(254.00000, 57.00000), Point(186.00000, 120.00000),
		Point(152.00000, 179.00000), Point(516.00000, 179.00000),
		Point(516.00000, 39.00000), Point(381.00000, 14.00000)
	};
		
	Point pointsTwo[] = {
		Point(134.00000, 241.00000), Point(140.00000, 357.00000),
		Point(134.00000, 241.00000), Point(516.00000, 241.00000),
		Point(140.00000, 357.00000), Point(196.00000, 460.00000),
		Point(288.00000, 529.00000), Point(196.00000, 460.00000),
		Point(413.00000, 553.00000), Point(508.00000, 532.00000),
		Point(508.00000, 532.00000), Point(516.00000, 241.00000)};
	int sum2 = sizeof(pointsTwo);
	int sum1 = sizeof(pointsOne);
	for (int i = 0; i < sum1 / 8; i = i + 2)
	{
		//addChild(DrawBody::addDraw(pointsTwo[i], pointsTwo[i + 1]), 1);
		//addChild(DrawBody::addDraw(pointsOne[i], pointsOne[i + 1]), 1);
	}

	return true;
}
void GameSceneTwo::onEnter()
{
	Node::onEnter();
	//Joint1(Vec2(639, 300));
	Joint2(Vec2(639, 300));
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch *touch, Event *event)
	{
		Point touchPoint = convertTouchToNodeSpace(touch);
		b = a = touchPoint;
		return true;
	};
	listener->onTouchEnded = [=](Touch*touch, Event*event)
	{
		Point touchPoint = convertTouchToNodeSpace(touch);
		b = touchPoint;
		addChild(PhysicsWor::addBox(a, b, 0.5), 1);
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameSceneTwo::Joint1(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sanA = Sprite::create("3.png");
	sanA->setPosition(p+Vec2(0,0));
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
		Vec2(0, -sanA->getContentSize().height/2), Vec2(0, 0));
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
void GameSceneTwo::Joint2(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	boxA = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxA->setPosition(p + Vec2(-400, 0));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	boxABody->setDynamic(false);
	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);
	boxB = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxB->setPosition(p + Vec2(-300, 0));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);
	auto boxC = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxC->setPosition(p + Vec2(-200, 0));
	auto boxCBody = PhysicsBody::createBox(boxC->getContentSize());
	boxC->setPhysicsBody(boxCBody);
	addChild(boxC, 1);
	auto boxD = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxD->setPosition(p + Vec2(-100, 0));
	auto boxDBody = PhysicsBody::createBox(boxD->getContentSize());
	boxD->setPhysicsBody(boxDBody);
	addChild(boxD, 1);
	auto boxE = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxC->setPosition(p + Vec2(0, 0));
	auto boxEBody = PhysicsBody::createBox(boxE->getContentSize());
	boxE->setPhysicsBody(boxEBody);
	addChild(boxE, 1);
	auto boxF = Sprite::create("1.png", Rect(a.x, a.y, 100, 20));
	boxF->setPosition(p + Vec2(100, 0));
	auto boxFBody = PhysicsBody::createBox(boxF->getContentSize());
	boxF->setPhysicsBody(boxFBody);
	addChild(boxF, 1);
	boxABody->getShape(0)->setRestitution(0);


	auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointLimit*joint1 = PhysicsJointLimit::construct(boxABody, boxBBody,
		Vec2(50, 0), Vec2(-50, 0), 0, 3);
	PhysicsJointLimit  *joint2 = PhysicsJointLimit::construct(boxBBody, boxCBody,
		Vec2(50, 0), Vec2(-50, 0), 0, 3);
	PhysicsJointLimit  *joint3 = PhysicsJointLimit::construct(boxCBody, boxDBody,
		Vec2(50, 0), Vec2(-50, 0), 0, 3);
	PhysicsJointLimit  *joint4 = PhysicsJointLimit::construct(boxDBody, boxEBody,
		Vec2(50, 0), Vec2(-50, 0), 0, 3);
	PhysicsJointLimit  *joint5 = PhysicsJointLimit::construct(boxEBody, boxFBody,
		Vec2(50, 0), Vec2(-50, 0), 0, 3);
	world->addJoint(joint1);
	world->addJoint(joint2);
	world->addJoint(joint3);
	world->addJoint(joint4);
	world->addJoint(joint5);
}
