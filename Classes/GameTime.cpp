#include"GameTime.h"
Scene* GameTime::create(int level){
	auto scene = new GameTime();
	if (scene && scene->initWithPhysics() && scene->init(level)){
		scene->autorelease();
		return scene;
	}
	else{
		CC_SAFE_DELETE(scene);
		scene = nullptr;
		return NULL;
	}
}
bool GameTime::init(int level){
	if (!Scene::init())
		return false;
	getPhysicsWorld()->setAutoStep(false);
	getPhysicsWorld()->setGravity(Vect(0, -980));
	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//��ȡ��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����߽�
	auto box = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height));
	//��Ҫ
	box->getShape(0)->setRestitution(0.0f);
	box->getShape(0)->setFriction(0.2f);
	auto boxNode = Node::create();
	boxNode->setPosition(visibleSize / 2);
	boxNode->setPhysicsBody(box);
	addChild(boxNode);
	//����myUpdate�����ж�ball�Ƿ񵽴���Ӧλ��
	_level = level;
	//������
	auto bgLayer = BackgroundLayer::create();
	//��Ϸ��
	gameLayer = GameLayer::create();
	//�滭��
	paintingLayer = PaintingLayer::create();
	//״̬��
	statusLayer = StatusLayer::create();
	statusLayer->setLevel(_level);
	gameLayer->setLevel(_level, statusLayer);
	gameLayer->setPhysicsWorld(this->getPhysicsWorld());
	gameLayer->loadTollgate(level);
	addChild(bgLayer, 1);
	addChild(gameLayer, 2);
	addChild(paintingLayer, 3);
	addChild(statusLayer, 4);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameTime::rePlayCallFunc), "RePlay", NULL);
	return true;
}

void GameTime::polyPointsProcessor(std::vector<Vec2>* points){
	if ((*points).size() <= 2 || (*points).begin() != (*points).end() - 1){		//ȷ����������2����β����
		(*points).clear();
		return;
	} 
	//for (auto i = pointArray.begin(); i != pointArray.end() - 1; i++){
	//}
}
Vec2 GameTime::getIntersection(Vec2 a, Vec2 b, Vec2 c){
	float dx1 = c.x - b.x;
	float dx2 = b.x - a.x;
	float dy1 = c.y - b.y;
	float dy2 = b.y - a.y;
	Vec2 intersection = Vec2::ZERO;
	intersection.y = (c.x*dy1*dy2 + b.y*dx2*dy1 - b.x*dy1*dy2 - c.y*dx1*dy2) / (dx2*dy1 - dx1*dy2);
	if (intersection.y > std::max(c.y, b.y) || intersection.y < std::max(c.y, b.y))
		return Vec2::ZERO;
	intersection.x = intersection.y;
	return Vec2::ZERO;
}
void GameTime::newTollgate(int level){
	this->removeChild(gameLayer, true);
	this->removeChild(paintingLayer, true);
	paintingLayer = PaintingLayer::create();
	gameLayer = GameLayer::create();
	gameLayer->setLevel(level, statusLayer);
	gameLayer->setPhysicsWorld(this->getPhysicsWorld());
	gameLayer->loadTollgate(level);
	//������Ϣ��StatusLayer�����Źؿ�������
	NotificationCenter::getInstance()->postNotification("showTollgateNumber", (Ref*)_level);
	this->addChild(gameLayer, 2);
	this->addChild(paintingLayer, 3);
}
void GameTime::update(float df){
	//MessageBox("f", "f");
	Scene::update(df);
	getPhysicsWorld()->step(0.02f);
	auto ballPos = gameLayer->getBallPos();
	auto winSize = Director::getInstance()->getWinSize();
	if (abs(ballPos.x - winSize.width) < 30 && abs(ballPos.y - winSize.height) < 1000){
		if (_level < 10) _level++;
		newTollgate(_level);
		CCLOG("newTollgate------%d", _level);
	}
}
void GameTime::rePlayCallFunc(Ref* ref){
	newTollgate(_level);
}