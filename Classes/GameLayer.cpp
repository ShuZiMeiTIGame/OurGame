#include"GameLayer.h"
bool GameLayer::init(){
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
	////加载关卡
	loadTollgate(_level);
	//scheduleUpdate();
	return true;
}
//加载对应关卡
void GameLayer::loadTollgate(int level){

	int height = 749;
	//auto tollgate = Tollgate::createTollgate(level, false, Vec2(140, height - 244));
	auto tollgate = Tollgate::createTollgate(level, false, Vec2(150, height - 244));

	ballSprite = PhysicsWor::addBall(tollgate->getBallPostion(), 20);
	addChild(ballSprite);

	auto bodies = tollgate->getbodiesArray();
	auto body1 = TollgateBody::createTollgateBody(TollgateBody::RECT, Vec2(115, 250));
	auto poss = body1->getPosArray();
	poss->push_back(Vec2(0, 500));
	poss->push_back(Vec2(230, 0));
	bodies->pushBack(body1);

	auto body2 = TollgateBody::createTollgateBody(TollgateBody::RECT, Vec2(837, height - 354));
	auto poss2 = body2->getPosArray();
	poss2->push_back(Vec2(250, height - 345));
	poss2->push_back(Vec2(1420, height - 364));
	bodies->pushBack(body2);

	auto body3 = TollgateBody::createTollgateBody(TollgateBody::TRIANGLE, Vec2(837, height - 354));
	auto poss3 = body3->getPosArray();
	poss3->push_back(Vec2(696, 0));
	poss3->push_back(Vec2(835, height - 369));
	poss3->push_back(Vec2(981, 0));
	bodies->pushBack(body3);
	auto j = bodies->begin();
	while (j != bodies->end()){
		int type = (*j)->getType();
		if (type == TollgateBody::RECT){
			auto posArray = (*j)->getPosArray();
			Vec2 cur_point = (*posArray)[1];
			Vec2 pre_point = (*posArray)[0];
			int width = abs((cur_point - pre_point).x);
			int height = abs((cur_point - pre_point).y);
			auto body2 = PhysicsBody::createBox(Size(width, height));
			body2->setMass(2000);
			body2->setGravityEnable(true);
			body2->getShape(0)->setDensity(0.5f);
			body2->getShape(0)->setFriction(0.2f);
			body2->getShape(0)->setRestitution(0.1f);
			auto edgeSprite = Scale9Sprite::create("wood.jpg", Rect(pre_point.x, pre_point.y, width, height));
			edgeSprite->setContentSize(Size(width, height));
			edgeSprite->setPosition((*j)->getPosition());
			edgeSprite->setPhysicsBody(body2);
			addChild(edgeSprite);
		}
		else if (type == TollgateBody::CIRCLE){

		}
		else if (type == TollgateBody::TRIANGLE){
			addChild(PhysicsWor::addSan((*j)->getPosition(), (*j)->getPosArray()));
		}
		j++;
	}
	_level = level;
	statusLayer->showLevelNumber(_level);
	
}
void GameLayer::setLevel(int level, StatusLayer* status){
	_level = level;
	statusLayer = status;
}
int GameLayer::getLevel(){
	return _level;
}
Vec2 GameLayer::getBallPos(){
	Vec2 pos = ballSprite->getPosition();
	return pos;
}
void GameLayer::update(float t){
	Layer::update(t);
}

