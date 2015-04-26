#include"GameLayer.h"
bool GameLayer::init(){
	if (!Layer::init())
		return false;
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//物理边界
	auto box = PhysicsBody::createEdgeBox(Size(visibleSize.width-50,visibleSize.height-50));
	//重要
	box->getShape(0)->setRestitution(0.0f);
	auto boxNode = Node::create();
	boxNode->setPosition(visibleSize / 2);
	boxNode->setPhysicsBody(box);
	addChild(boxNode);
	////加载关卡
	//loadTollgate(_level);
	//scheduleUpdate();
	return true;
}
//加载对应关卡
void GameLayer::loadTollgate(int level){
	std::vector<float> vect;
	//InFoExec::GetInStance()->SaveAllInfo(2, 1, vect);
	int height = 749;
	//auto tollgate = Tollgate::createTollgate(level, false, Vec2(140, height - 244));
	//auto tollgate = Tollgate::createTollgate(level, false, Vec2(150, height - 244));

	auto tollgate = InFoExec::GetInStance()->Getlevelinfo(level);
	ballSprite = PhysicsWor::addBall(tollgate->getBallPostion(), 20);
	addChild(ballSprite);
	auto bodies = tollgate->getbodiesArray();

	//auto body1 = TollgateBody::createTollgateBody(TollgateBody::RECT, Vec2(115, 250));
	//auto poss = body1->getPosArray();
	//poss->push_back(Vec2(0, 500));
	//poss->push_back(Vec2(230, 0));
	//bodies->pushBack(body1);

	////auto body2 = TollgateBody::createTollgateBody(TollgateBody::RECT, Vec2(837, height - 354));
	//auto body2 = TollgateBody::createTollgateBody(TollgateBody::RECT, Vec2(837, height - 300));
	//auto poss2 = body2->getPosArray();
	//poss2->push_back(Vec2(250, height - 345));
	//poss2->push_back(Vec2(1420, height - 364));
	//bodies->pushBack(body2);

	//auto body3 = TollgateBody::createTollgateBody(TollgateBody::TRIANGLE, Vec2(837, height - 600));
	//auto poss3 = body3->getPosArray();
	////poss3->push_back(Vec2(696, 0));
	////poss3->push_back(Vec2(835, height - 369));
	////poss3->push_back(Vec2(981, 0));

	//poss3->push_back(Vec2(-200, 0));
	//poss3->push_back(Vec2(0, 390));
	//poss3->push_back(Vec2(200, 0));
	//bodies->pushBack(body3);

	PhysicsBody* b1;
	PhysicsBody* b2;

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
				b1 = body2;
			//body2->setMass(2000);
			//body2->setGravityEnable(true);
			//body2->getShape(0)->setDensity(0.5f);
			//body2->getShape(0)->setFriction(0.2f);
			//body2->getShape(0)->setRestitution(0.1f);
			//body2->setDynamic(false);
			auto edgeSprite = Scale9Sprite::create("wood.jpg", Rect(pre_point.x, pre_point.y, width, height));
			edgeSprite->setContentSize(Size(width, height));
			edgeSprite->setPosition((*j)->getPosition());
			edgeSprite->setPhysicsBody(body2);
			addChild(edgeSprite);
		}
		else if (type == TollgateBody::CIRCLE){

		}
		else if (type == TollgateBody::TRIANGLE){
			auto triangle = PhysicsWor::addSan((*j)->getPosition(), (*j)->getPosArray());
			auto mySprite = Sprite::create();
			//mySprite->setTexture(Texture2D::initWithImage(Image::))
			b2 = triangle->getPhysicsBody();
			addChild(triangle);
		}
		j++;
	}
	//Vec2 pos = ((*body2->getPosArray())[0] - (*body2->getPosArray())[1]) / 2;
	////Vec2 pos2(1420 - 250,);
	//auto pin = PhysicsJointDistance::construct(b1, b2,Vec2::ZERO, Vec2(0, 390));
	//_phyWorld->addJoint(pin);
	_level = level;
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
Sprite* GameLayer::getBall(){
	return ballSprite;
}
void GameLayer::setPhysicsWorld(PhysicsWorld* world){
	_phyWorld = world;
}
