#include"GameSceneOne.h"
<<<<<<< HEAD
#include"DrawBody.h"

=======
#include"Ball.h"
#include"DrawBody.h"
#include"Box.h"
>>>>>>> origin/master
USING_NS_CC;

Scene*GameSceneOne::createScene(){
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);	//显示物理世界调试状态, 显示红色的框, 方便调试
	auto layer = GameSceneOne::create();
<<<<<<< HEAD
	scene->getPhysicsWorld()->setGravity(Vect(0,-490));
=======
	scene->getPhysicsWorld()->setGravity(Vect(0,-980));
>>>>>>> origin/master
	scene->addChild(layer);
	return scene;
}

bool GameSceneOne::init(){
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


<<<<<<< HEAD
	Sprite *a =PhysicsWor ::addBall(Vec2(100, 500),20);
=======
	Sprite *a = Ball::addBall(Vec2(100, 500),20);
>>>>>>> origin/master
	addChild(a, 1);
	a->setTag(1);
	auto background = Sprite::create("background2.png");
	background->setPosition(480,340);
	addChild(background, 0);
	
	Point pointsOne[] = {
		Point(960.00000, 118.00000), Point(960.00000, 0.00000),
		Point(675.00000, 0.00000), Point(675.00000, 171.00000),
		Point(960.00000, 118.00000), Point(675.00000, 171.00000),
		Point(557.00000, 196.00000), Point(388.00000, 240.00000),
		Point(0.00000, 351.00000), Point(190.00000, 318.00000),
		Point(557.00000, 196.00000), Point(558.00000, -3.00000),
		Point(0.00000, -3.00000), Point(0.00000, 351.00000),
		Point(190.00000, 318.00000), Point(388.00000, 240.00000)};
	Point pointsTwo[] = {
		Point(609.00000, 281.00000), Point(609.00000, 0.00000),
		Point(609.00000, 281.00000), Point(0.00000, 501.00000),
		Point(657.00000, 261.00000), Point(954.00000, 153.00000),
		Point(657.00000, 0.00000), Point(657.00000, 261.00000) };

	int sum2 = sizeof(pointsTwo);
	int sum1 = sizeof(pointsOne);
	for (int i = 0; i < sum2 / 8; i = i + 2)
	{
		//addChild(DrawBody::addDraw(pointsOne[i], pointsOne[i + 1]), 1);
		addChild(DrawBody::addDraw(pointsTwo[i], pointsTwo[i + 1]), 1);
<<<<<<< HEAD
		Vector<Vec2>points();
=======
>>>>>>> origin/master
	}

	auto sprite = Sprite::create("win.png");
	sprite->setPosition(480, 360);
	addChild(sprite, 1);
	sprite->setTag(2);

	this->scheduleUpdate();
	//

		return true;
}
void GameSceneOne::onEnter()
{
	Node::onEnter();///////////////////////////////////////
<<<<<<< HEAD
	//Joint1(Vec2(639, 300));
	//Joint2(Vec2(639, 300));
	Joint3(Vec2(50, 550));
=======
	Joint1(Vec2(639, 300));
	//Joint2(Vec2(639, 300));
>>>>>>> origin/master
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
<<<<<<< HEAD
		addChild( PhysicsWor::addBox(a, b, 0.5), 1);
=======
		addChild(Box::addBox(a, b, 0.5), 1);
>>>>>>> origin/master
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameSceneOne::update(float t)
{
	auto a = getChildByTag(1);
	auto sprite = getChildByTag(2);
	if (a->getPositionX() <= 800)
	{
		sprite->setVisible(false);
	}
	else
	{
		sprite->setVisible(true);
	}
}
void GameSceneOne::Joint1(Vec2 p)
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

	auto boxB = Sprite::create("1.png", Rect(a.x, a.y, 300, 20));
	boxB->setPosition(p + Vec2(0, 44));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	//boxBBody->getShape(0)->setRestitution(1);
	//boxBBody->getShape(0)->setFriction(5);
	boxBBody->setGravityEnable(true);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);

	auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointDistance*joint = PhysicsJointDistance::construct(sanABody, boxBBody,
		Vec2(0, sanA->getContentSize().height/2), Vec2(0, -boxB->getContentSize().height / 2));
	world->addJoint(joint);
	
}
void GameSceneOne::Joint2(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 boxA = Sprite::create("1.png", Rect(620, 300, 40, 100));
	boxA->setPosition(p + Vec2(0, 0));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());
	boxABody->getShape(0)->setMass(10);

	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);

	boxB = Sprite::create("1.png", Rect(a.x, a.y, 80, 20));
	boxB->setPosition(p + Vec2(0, boxB->getContentSize().width));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	boxBBody->setGravityEnable(true);
<<<<<<< HEAD
	boxBBody->getShape(0)->setFriction(0.5f);
=======
>>>>>>> origin/master
	boxBBody->setDynamic(false);
	boxBBody->getShape(0)->setRestitution(0);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);

	auto world = this->getScene()->getPhysicsWorld();
	PhysicsJointSpring  *joint = PhysicsJointSpring::construct(boxABody, boxBBody,
		Vec2(0, 0), Vec2(0, 0), 400, 10);
	world->addJoint(joint);
}
<<<<<<< HEAD
void GameSceneOne::Joint3(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sanA = Sprite::create("3.png");
	sanA->setPosition(p + Vec2(0, 0));
	Point points[3] = { Point(-29.00000, -25.00000), Point(-1.00000, 28.00000), Point(31.00000, -25.00000) };
	auto sanABody = PhysicsBody::createPolygon(points, 3);
	//sanABody->setDynamic(false);
	sanA->setPhysicsBody(sanABody);
	addChild(sanA, 1);

	auto ballB = Sprite::create("1.png");
	ballB->setPosition(p + Vec2(-20, -30));
	auto ballBBody = PhysicsBody::createCircle(10);
	ballBBody->setGravityEnable(true);
	ballB->setPhysicsBody(ballBBody);
	addChild(ballB, 1);

	auto ballC = Sprite::create("1.png");
	ballC->setPosition(p + Vec2(20, -30));
	auto ballCBody = PhysicsBody::createCircle(10);
	ballCBody->setGravityEnable(true);
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
=======
>>>>>>> origin/master
