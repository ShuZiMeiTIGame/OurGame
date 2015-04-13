#include"GameTime.h"
Scene* GameTime::createScene(){
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vect(0, -980));
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//背景层
	auto bgLayer = BackgroundLayer::create();
	//游戏层
	auto gameLayer = GameTime::create();
	//绘画层
	auto paintingLayer = PaintingLayer::create();
	scene->addChild(paintingLayer, 3);
	scene->addChild(bgLayer, 1);
	scene->addChild(gameLayer, 2);
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
	ballSprite = Ball::addBall(Vec2(500, 600),20);
	/*ballSprite->setPosition(Vec2(500, 600));
	auto circleBody = PhysicsBody::createCircle(ballSprite->getContentSize().width / 2);
	circleBody->setMass(200);
	circleBody->getShape(0)->setDensity(0.6f);
	circleBody->getShape(0)->setFriction(0.3f);
	circleBody->getShape(0)->setRestitution(0.8f);
	ballSprite->setPhysicsBody(circleBody);*/
	addChild(ballSprite);

	//加载关卡
	loadTollgate(1);
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
//加载对应关卡
void GameTime::loadTollgate(int level){
	
	auto tollgate = Tollgate::createTollgate(level, false);
	auto bodies = tollgate->getbodiesArray();
	std::vector<Vec2> poss;
	poss.push_back(Vec2(100, 100));
	poss.push_back(Vec2(300, 300));
	int i = 5;
	while (i--){
		auto body = TollgateBody::createTollgateBody(TollgateBody::RECT, Vec2(300*i, 100), &poss);
		bodies->pushBack(body);
	}

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

		}

		j++;
	}
}
void GameTime::onEnter(){
	Layer::onEnter();
}

