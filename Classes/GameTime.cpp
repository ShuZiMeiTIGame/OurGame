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
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	getPhysicsWorld()->setGravity(Vect(0, -980));
	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//调用myUpdate函数判定ball是否到达相应位置
	_level = level;
	//背景层
	auto bgLayer = BackgroundLayer::create();
	//游戏层
	gameLayer = GameLayer::create();
	//绘画层
	auto paintingLayer = PaintingLayer::create();
	//状态层
	statusLayer = StatusLayer::create();
	statusLayer->setLevel(_level);
	gameLayer->setLevel(_level, statusLayer);

	addChild(bgLayer, 1);
	addChild(gameLayer, 5);
	addChild(paintingLayer, 3);
	addChild(statusLayer, 4);
	return true;
}

void GameTime::polyPointsProcessor(std::vector<Vec2>* points){
	if ((*points).size() <= 2 || (*points).begin() != (*points).end() - 1){		//确保边数大于2且首尾相连
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
}
void GameTime::newTollgate(int level){
	this->removeChild(gameLayer, true);
	gameLayer = GameLayer::create();
	gameLayer->setLevel(level, statusLayer);
	this->addChild(gameLayer, 2);
}
void GameTime::update(float df){
	//MessageBox("f", "f");
	Scene::update(df);
	auto ballPos = gameLayer->getBallPos();
	auto winSize = Director::getInstance()->getWinSize();
	if (abs(ballPos.x - winSize.width) < 200 && abs(ballPos.y - winSize.height) < 8000){
		if (_level < 2) _level++;
		newTollgate(_level);
		CCLOG("newTollgate------%d", _level);
	}
}