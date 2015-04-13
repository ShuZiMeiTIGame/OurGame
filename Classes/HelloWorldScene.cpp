#include "HelloWorldScene.h"
#include"PhysicsEngine.h"
//#include"addJoint.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
	//使用物理世界创建场景
	auto scene = Scene::createWithPhysics();
	//显示物理世界调试状态, 显示红色的框, 方便调试
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//把空间保持我们创建的层中，就是上面所说m_world的作用，方便后面设置空间的参数  
	//layer->setPhyWorld(scene->getPhysicsWorld());
	auto layer = HelloWorld::create();
	scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//创建一个物理世界,用来碰撞  
	Sprite* edgeSpace = Sprite::create();
	// 大小和屏幕的尺寸相同,debug框的宽度为3个像素
	PhysicsBody* body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	//摩擦系数
	body->getShape(0)->setFriction(5.0f);
	//反弹系数
	//body->getShape(0)->setRestitution(1.0f);
	//绑定
	edgeSpace->setPhysicsBody(body);
	//空间放的位置
	edgeSpace->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(edgeSpace, 1);
	//创建监听对象
	auto Listener = EventListenerTouchOneByOne::create();
	//定义监听对象回调方法
	Listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	Listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	//在时间的分发器中注册
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);
	addBox2();
	addBall2();
	addSan2();
	isSan = false;
	isBall = false;
	isBox = false;
	//
	//Wall*a = new Wall();
	//wall01 = a->addWall(Vec2(600, 300));
	//addChild(wall01, 1);
	//drawLine(Vec2(300,300),Vec2(300,500));
	//LineBody(Vec2(300, 300), Vec2(300, 500));
	//LineBody(Vec2(300, 300), Vec2(100, 300));
	LineBody(Vec2(777.00000, 75.00000), Vec2(960.00000, 129.00000));
	LineBody(Vec2(249.00000, 105.00000), Vec2(0.00000, 157.00000));
	LineBody(Vec2(691.00000, 67.00000), Vec2(249.00000, 105.00000));
	LineBody(Vec2(691.00000, 67.00000), Vec2(777.00000, 75.00000));
	//////////////////////////////////////
	//addNewSpriteAtPosition(Vec2(100,300));
	this->scheduleUpdate();
	////
	// draw->drawSegment(Point(size.width / 6, 0), Point(size.width / 6, size.height), 3/*半径*/, Color4F(1, 1, 1, 1));
	auto draw = DrawNode::create();
	draw->setPosition(Point::ZERO);
	this->addChild(draw, 1);
	//draw->drawPolygon(Vec2(a1), 5, Color4F::WHITE);
	//draw();
	auto spritebk = Sprite::create("111.png");
	spritebk->setPosition(0, 0);
	addChild(spritebk, 2);
	
	return true;
}
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)				
{
	Point touchPoint = convertTouchToNodeSpace(touch);
	b1=a1 = touchPoint;
	if (ball2->boundingBox().containsPoint(touchPoint))
	{
		isBall = true;
		isBox = false;
		isSan = false;
	}
	else if (box2->boundingBox().containsPoint(touchPoint))
	{
		isBox = true;
		isBall = false;
		isSan = false;
	}
	else if(san2->boundingBox().containsPoint(touchPoint))
	{
		isSan = true;
		isBall = false;
		isBox= false;
	}
	else{}
	Vec2 location = touch->getLocation();
	//addJoint(location);
	//addNewSpriteAtPosition(location);
	return true;
}
void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
	Point touchPoint = convertTouchToNodeSpace(touch);
	b1  = touchPoint;
	

}
void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event){
	Vec2 location = touch->getLocation();
	 b1 = location;
	 if (isBall)
	 {
		 addChild(PhysicsWor::addBall(a1, b1,500));
	 }
	 if (isBox)
	 {
		 addChild(PhysicsWor::addBox(a1, b1,500));
		 
	 }
	 if (isSan)
	 {
		 Point points[3] = { Point(-29.00000, -25.00000), Point(-1.00000, 28.00000), Point(31.00000, -25.00000) };
		 Vector<Point>pointArr();
		 /*for (int i = 0; i < 3; i++)
		 {
			 pointArr.push_back(points[i]);

		 }*/



		// addChild(PhysicsWor::addSan(a1,b1,points),1);
	 }

	 b1 = a1 = Vec2(0, 0);
}
void HelloWorld::addBox2(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	box2 = Sprite::create("2.png");
	box2->setPosition(800,500);
	addChild(box2, 2);
}
void HelloWorld::addBall2(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	ball2 = Sprite::create("CloseNormal.png");
	ball2->setPosition(800, 400);
	addChild(ball2, 2);
}
void HelloWorld::addSan2(){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	san2= Sprite::create("3.png");
	san2->setPosition(800, 300);
	addChild(san2, 2);
}
void HelloWorld::update(float w)
{
	static int speedY = -1;
//	static int speedX = -1;
	wall01->setPositionY(wall01->getPositionY() + speedY);
	//wall01->setPositionX(wall01->getPositionX() + speedX);
	if (wall01->getPositionY() >= 500 && speedY > 0)
	{
		speedY = -1;
	}
	if (wall01->getPositionY() <= 200 && speedY<0)
	{
		speedY = +1;
	}
	//if (wall01->getPositionX() >= 600 && speedX > 0)
	//{
	//	speedX = -1;
	//}
	//if (wall01->getPositionX() <= 400 && speedX<0)
	//{
	//	speedX = +1;
	//}
}
void HelloWorld::LineBody(Vec2 a, Vec2 b)
{
	PhysicsBody*lineBody = PhysicsBody::createEdgeSegment(a, b); 
	auto drawNode = DrawNode::create();
	drawNode->setPhysicsBody(lineBody);
	addChild(drawNode, 1);
} 
void  HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	if (isBox)
	{
		//DrawPrimitives::drawRect(a1, b1); 
		DrawPrimitives::drawSolidRect(a1, b1, Color4F::WHITE);		
	}
	if (isBall)
	{
		DrawPrimitives::drawSolidCircle((a1+b1)/2 , (a1-b1).x, CC_DEGREES_TO_RADIANS(90), 50, 1.0f, 1.0f);
	}
}
void HelloWorld::addJoint(Vec2 p)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto boxA = Sprite::create("4.png");
	boxA->setPosition(p + Vec2(0,  2*boxA->getContentSize().width/3));
	auto boxABody = PhysicsBody::createBox(boxA->getContentSize());

	boxA->setPhysicsBody(boxABody);
	addChild(boxA, 1);
	////
	auto boxB = Sprite::create("4.png");
	/////////////
	boxB->setPosition(p + Vec2(0, 0));
	auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
	//boxBBody->getShape(0)->setMass(500);
	boxB->setPhysicsBody(boxBBody);
	addChild(boxB, 1);
	//
	auto ballC = Sprite::create("CloseNormal.png");
	ballC->setPosition(p + Vec2(0, 0));
	auto ballCBody = PhysicsBody::createCircle(ballC->getContentSize().height/2);//这里可以改物理物体的形状
	ballC->setPhysicsBody(ballCBody);
	addChild(ballC, 1);

	auto world = this->getScene()->getPhysicsWorld();
	//PhysicsJointDistance* joint = PhysicsJointDistance::construct(boxABody, boxBBody,
	//	Vec2(0, 0), Vec2(0, 0));
	//world->addJoint(joint);
	PhysicsJointMotor*joint = PhysicsJointMotor::construct(boxABody, boxBBody,1);
	PhysicsJointDistance * joint2 = PhysicsJointDistance::construct(boxABody, boxBBody,
	Vec2(0, 0), Vec2(0, 0));
//PhysicsJointFixed*joint3 = PhysicsJointFixed::construct(boxBBody, ballCBody,Vec2(p));
	world->addJoint(joint2);
//world->addJoint(joint3);
	world->addJoint(joint);

	//PhysicsJointGear离心转动  a,b, ,转动的比列
	//PhysicsJointMotor  马达
	//PhysicsJointRatchet 齿轮
	//PhysicsJointFixed 固定
	//PhysicsJointPin会绕一个点动
	//PhysicsJointSpring类似于一个弹簧 stiffness就是拉的得力越小拉的越大 damping阻尼
	//PhysicsJointGroove有一个可以根据力上下滑动的沟，槽
	//PhysicsJointRotarySpring 旋转的弹簧
	//PhysicsJointLimit 刚体间有一个约束但不是固定的 可以拉长缩短 
	//PhysicsJointRotaryLimit
	//test 里面的physics 可以自己去试
}
void HelloWorld::addJointFixed(Vec2 p,int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto world = this->getScene()->getPhysicsWorld();
	if (i = 0)
	{
		auto boxB = Sprite::create("2.png");
		boxB->setPosition(p + Vec2(0, 2 * boxB->getContentSize().height));
		auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
		boxB->setPhysicsBody(boxBBody);
		addChild(boxB, 1);

		auto ballC = Sprite::create("CloseNormal.png");
		ballC->setPosition(p + Vec2(0, 4 * boxB->getContentSize().height));
		auto ballCBody = PhysicsBody::createCircle(ballC->getContentSize().height / 2);
		ballC->setPhysicsBody(ballCBody);
		addChild(ballC, 1);
		PhysicsJointFixed*joint3 = PhysicsJointFixed::construct(ballCBody, boxBBody,
		Vec2(p));
		world->addJoint(joint3);
	}
	if (i=1)
	{
		auto boxB = Sprite::create("2.png");
		boxB->setPosition(p + Vec2(0, 2 * boxB->getContentSize().height));
		auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
		boxB->setPhysicsBody(boxBBody);
		addChild(boxB, 1);

		auto ballC = Sprite::create("CloseNormal.png");
		ballC->setPosition(p + Vec2(0, 4 * boxB->getContentSize().height));
		auto ballCBody = PhysicsBody::createCircle(ballC->getContentSize().height / 2);
		ballC->setPhysicsBody(ballCBody);
		addChild(ballC, 1);
		PhysicsJointPin*joint3 = PhysicsJointPin::construct(ballCBody, boxBBody,
			Vec2(p));
		world->addJoint(joint3);
	}
	if (i=3)
	{
		auto boxB = Sprite::create("1.png");
		boxB->setPosition(p + Vec2(0, 4 * boxB->getContentSize().height));
		auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
		boxB->setPhysicsBody(boxBBody);
		addChild(boxB, 1);
		auto ballC = Sprite::create("CloseNormal.png");
		ballC->setPosition(p + Vec2(0, 0));
		auto ballCBody = PhysicsBody::createCircle(ballC->getContentSize().height / 2);//这里可以改物理物体的形状
		ballC->setPhysicsBody(ballCBody);
		addChild(ballC, 1);

		auto world = this->getScene()->getPhysicsWorld();
		PhysicsJointLimit *joint3 = PhysicsJointLimit::construct(ballCBody, boxBBody,
			Vec2(0, 0), Vec2(0, 0));
		world->addJoint(joint3);
	}
	if (i=4)
	{
		auto boxB = Sprite::create("1.png");
		boxB->setPosition(p + Vec2(0, 4 * boxB->getContentSize().height));
		auto boxBBody = PhysicsBody::createBox(boxB->getContentSize());
		boxB->setPhysicsBody(boxBBody);
		addChild(boxB, 1);
		auto ballC = Sprite::create("CloseNormal.png");
		ballC->setPosition(p + Vec2(0, 0));
		auto ballCBody = PhysicsBody::createCircle(ballC->getContentSize().height / 2);//这里可以改物理物体的形状
		ballC->setPhysicsBody(ballCBody);
		addChild(ballC, 1);

		auto world = this->getScene()->getPhysicsWorld();
		PhysicsJointSpring *joint3 = PhysicsJointSpring::construct(ballCBody, boxBBody,
			Vec2(0, 0), Vec2(0, 0), 1000, 0);
		world->addJoint(joint3);
	}
}

	