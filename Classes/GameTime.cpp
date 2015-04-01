#include"GameTime.h"
Scene* GameTime::createScene(){
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vect(0, -9.8));
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = GameTime::create();
	scene->addChild(layer);
	return scene;
}
bool GameTime::init(){
	if (!Layer::init())
		return false;
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//物理边界
	auto box = PhysicsBody::createEdgeBox(visibleSize);
	auto boxNode = Node::create();
	boxNode->setPosition(visibleSize / 2);
	boxNode->setPhysicsBody(box);
	addChild(boxNode);

	//测试小球
	auto ballSprite = Sprite::create("ball.png");
	ballSprite->setPosition(Vec2(500, 600));
	auto circleBody = PhysicsBody::createCircle(ballSprite->getContentSize().width / 2);
	circleBody->setMass(2000);
	ballSprite->setPhysicsBody(circleBody);
	addChild(ballSprite);



	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameTime::OnTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameTime::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameTime::OnTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
bool GameTime::OnTouchBegan(Touch* touch, Event* event_){
	pre_point = cur_point = touch->getLocation();
	return true;
}
void GameTime::OnTouchMoved(Touch* touch, Event* event_){
	cur_point = touch->getLocation();
	log("Point:%f,%f", cur_point.x, cur_point.y);
	if ((cur_point - pre_point).getLengthSq() > 25){
		pointArray.push_back(pre_point);
		pointArray.push_back(cur_point);
		pre_point = cur_point;
	}
}
void GameTime::OnTouchEnded(Touch* touch, Event* event_){
	cur_point = touch->getLocation();
	if ((cur_point - pre_point).getLengthSq() > 25){
		pointArray.push_back(pre_point);
		pointArray.push_back(cur_point);
		pre_point = cur_point;
	}
	if (pointArray.size() < 2)
		return;
	for (auto i = pointArray.begin(); i != pointArray.end() - 2; i++){
		auto body = PhysicsBody::createEdgeSegment(Vec2(i->x, i->y), Vec2((i + 1)->x, (i + 1)->y));
		body->setMass(20);
		body->setGravityEnable(true);
		//body->set
		auto edgeNode = Node::create();
		edgeNode->setPhysicsBody(body);
		addChild(edgeNode);
	}


	pointArray.clear();
}
void GameTime::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	DrawPrimitives::setDrawColor4B(0,255, 255, 255);
	glLineWidth(6);
	if (pointArray.size() < 2)
		return;
	for (auto  i = pointArray.begin(); i != pointArray.end() - 2;i++){
		DrawPrimitives::drawLine(Vec2(i->x, i->y), Vec2((i+1)->x, (i+1)->y));

	}
}
