#include"GameTime.h"
Scene* GameTime::createScene(){
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vect(0, -980));
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
	isSetPosition = false;
	//测试小球
	ballSprite = Sprite::create("ball.png");
	ballSprite->setPosition(Vec2(500, 600));
	auto circleBody = PhysicsBody::createCircle(ballSprite->getContentSize().width / 2);
	circleBody->setMass(200);
	circleBody->getShape(0)->setDensity(0.6f);
	circleBody->getShape(0)->setFriction(0.3f);
	circleBody->getShape(0)->setRestitution(0.8f);
	ballSprite->setPhysicsBody(circleBody);
	addChild(ballSprite);
	//控制菜单
	auto label = MenuItemFont::create("setPositon",CC_CALLBACK_1(GameTime::OnMenuClicked,this));
	auto menu = Menu::create(label, NULL);
	menu->setPosition(Vec2(100,visibleSize.height - 100));
	addChild(menu);

	//初始化坐标
	pre_point = cur_point = Vec2::ZERO;


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameTime::OnTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameTime::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameTime::OnTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
bool GameTime::OnTouchBegan(Touch* touch, Event* event_){
	pre_point = cur_point = touch->getLocation();
	if (isSetPosition){
		ballSprite->setPosition(cur_point);
		isSetPosition = false;
	}
	return true;
}
void GameTime::OnTouchMoved(Touch* touch, Event* event_){
	cur_point = touch->getLocation();
	//log("Point:%f,%f", cur_point.x, cur_point.y);
	//if ((cur_point - pre_point).getLengthSq() > 50){
	//	pointArray.push_back(pre_point);
	//	pointArray.push_back(cur_point);
	//	pre_point = cur_point;
	//}
}
void GameTime::OnTouchEnded(Touch* touch, Event* event_){
	//cur_point = touch->getLocation();
	//if ((cur_point - pre_point).getLengthSq() > 50){
	//	pointArray.push_back(pre_point);
	//	pointArray.push_back(cur_point);
	//	pre_point = cur_point;
	//}
	//if (pointArray.size() < 2)
	//	return;
	//for (auto i = pointArray.begin(); i != pointArray.end() - 2; i++){
	//	auto body = PhysicsBody::createEdgeSegment(Vec2(i->x, i->y), Vec2((i + 1)->x, (i + 1)->y));
	//	int width = abs(i->x - (i + 1)->x);
	//	int height = abs(i->y - (i + 1)->y);
	//	auto body2 = PhysicsBody::createBox(Size(width, height));
	//	body2->setMass(200);
	//	body2->setGravityEnable(true);
	//	//body->set
	//	auto edgeNode = Node::create();
	//	//edgeNode->setPosition(Vec2(i->x,i->y));
	//	edgeNode->setPhysicsBody(body);
	//	addChild(edgeNode);
	//}

	int width = abs((cur_point - pre_point).x);
	int height = abs((cur_point - pre_point).y);
	auto body2 = PhysicsBody::createBox(Size(width, height));
	body2->setMass(2000);
	body2->setGravityEnable(true);
	body2->getShape(0)->setDensity(0.5f);
	body2->getShape(0)->setFriction(0.2f);
	body2->getShape(0)->setRestitution(0.1f);
	auto edgeSprite = Scale9Sprite::create("wood.jpg",Rect(pre_point.x,pre_point.y,width,height));
	edgeSprite->setContentSize(Size(width, height));
	edgeSprite->setPosition(pre_point + (cur_point - pre_point) / 2);
	edgeSprite->setPhysicsBody(body2);
	addChild(edgeSprite);
	//清空坐标停止绘制
	pre_point = cur_point = Vec2::ZERO;
	pointArray.clear();
}
void GameTime::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	DrawPrimitives::setDrawColor4B(249,209, 9, 255);
	glLineWidth(2);
	//if (pointArray.size() < 2)
	//	return;
	//for (auto  i = pointArray.begin(); i != pointArray.end() - 2;i++){
	//	DrawPrimitives::drawLine(Vec2(i->x, i->y), Vec2((i+1)->x, (i+1)->y));
	//}

	if (cur_point == Vec2::ZERO && pre_point == Vec2::ZERO)
		return;
	DrawPrimitives::drawRect(pre_point,cur_point);
}
void GameTime::OnMenuClicked(Ref* ref){
	isSetPosition = true;
}
