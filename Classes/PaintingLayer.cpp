#include"PaintingLayer.h"

bool PaintingLayer::init(){
	if (!Layer::init())
		return false;
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//标量初始化
	isSetPosition = false;
	isTriangle = false;
	isPolygon = false;
	isBox = false;
	isCircle = false;
	//初始化坐标
	pre_point = cur_point = Vec2::ZERO;
	//创建DrawNode
	drawNode = DrawNode::create();
	addChild(drawNode,20);
	//控制菜单
	auto label = MenuItemFont::create("setPositon", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	label->setTag(0);
	label->setPosition(Vec2(0, -100));

	auto circle = MenuItemFont::create("Circle", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	circle->setTag(5);
	circle->setPosition(Vec2(0, -150));

	auto tranLabel = MenuItemFont::create("Triangle", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	tranLabel->setTag(1);
	tranLabel->setPosition(Vec2(0, -50));
	auto BoxLabel = MenuItemFont::create("Box", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	BoxLabel->setTag(2);
	BoxLabel->setPosition(Vec2(0, 0));
	auto PolygonLabel = MenuItemFont::create("Polygon", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	PolygonLabel->setTag(3);
	PolygonLabel->setPosition(Vec2(0, 50));

	auto rePlay = MenuItemFont::create("RePlay", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	rePlay->setTag(4);
	rePlay->setPosition(Vec2(0, -200));


	auto menu = Menu::create(label, tranLabel, BoxLabel, PolygonLabel, rePlay, circle,NULL);
	menu->setPosition(Vec2(100, visibleSize.height - 100));
	addChild(menu);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PaintingLayer::OnTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PaintingLayer::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PaintingLayer::OnTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
bool PaintingLayer::OnTouchBegan(Touch* touch, Event* event_){
	pre_point = cur_point = touch->getLocation();
	if (isSetPosition)
	{
		//ballSprite->setPosition(cur_point);
		isSetPosition = false;
	}
	//if (isPolygon){
	//	pointArray.push_back(cur_point);
	//	//判断直线是否相交
	//	/*if (pointArray.size() >= 2){
	//	for (auto i = pointArray.end() - 1; i != pointArray.begin() - 1; i--){
	//	i, i - 1;
	//	}
	//	}*/
	//}
	//if (isTriangle){
	//	pointArray.push_back(cur_point);
	//}
	pointArray.push_back(cur_point);
	return true;
}
void PaintingLayer::OnTouchMoved(Touch* touch, Event* event_){
	cur_point = touch->getLocation();
	if (isBox)
		drawNode->clear();
	if (isPolygon || isTriangle || isCircle){
		if (pointArray.size() == 1){
			pointArray.push_back(cur_point);
		}
		else{
			pointArray.pop_back();
			pointArray.push_back(cur_point);
		}
		drawNode->clear();
	}
}
void PaintingLayer::OnTouchEnded(Touch* touch, Event* event_){
	cur_point = touch->getLocation();
	if (isPolygon && pointArray.size() > 2){
		auto first = pointArray.begin();
		float xOffSet = abs(pointArray.begin()->x - cur_point.x);
		float yOffSet = abs(pointArray.begin()->y - cur_point.y);
		if (xOffSet < 50 && yOffSet < 50){
			pointArray.pop_back();
			pointArray.push_back(*first);
			//创建多边形
			//Vec2* points = new Vec2[pointArray.size()];
			//int j = 0;
			//for (auto i = pointArray.begin(); i <= pointArray.end() - 1; i++){
			//	points[j++] = *i;
			//}
			////{
			////	points[0] = Vec2(-10, -10);
			////	points[1] = Vec2(-10, 60);
			////	points[2] = Vec2(60, 60);
			////	points[3] = Vec2(60, -10);
			////}
			//auto node = Node::create();
			//auto polygon = PhysicsBody::createPolygon(points, pointArray.size());
			//node->setPhysicsBody(polygon);
			//addChild(node);
			pointArray.clear();
			drawNode->clear();
			//delete(points);
			//points = nullptr;
		}
	}

	if (isBox){
		drawNode->clear();
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
		edgeSprite->setPosition(pre_point + (cur_point - pre_point) / 2);
		edgeSprite->setPhysicsBody(body2);
		addChild(edgeSprite);
		pointArray.clear();

	}
	if (isTriangle){
		if (pointArray.size() == 3){
			//auto triangle = San::addSan();
			pointArray.clear();
			drawNode->clear();
		}

	}
	if (isCircle){
		int r = (pointArray[0].x - pointArray[1].x)/ 2;
		Vec2 center(std::max(pointArray[0].x, pointArray[1].x)-r, std::max(pointArray[0].y, pointArray[1].y)-r);
		addChild(PhysicsWor::addBall(center, r));
	}
	pointArray.clear();
	drawNode->clear();
	//清空坐标停止绘制
	pre_point = cur_point = Vec2::ZERO;
}
void PaintingLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	//DrawPrimitives::setDrawColor4B(3, 171, 174, 255);//看不见
	//glLineWidth(2.0f);
	if (pointArray.size() < 2)
		return;
	Color4F color = Color4F(Color4B(3,171,174,255));
	if (isTriangle && pointArray.size() > 1){
		for (auto i = pointArray.begin(); i != pointArray.end() - 1; i++){
			//DrawPrimitives::drawLine(*i, *(i + 1));
			drawNode->drawSegment(*i, *(i + 1), 2, color);
		}
		if (pointArray.size() == 3){
			auto first = pointArray.begin();
			auto end = pointArray.end() - 1;
			//DrawPrimitives::drawLine(*end, *first);
			drawNode->drawSegment(*end, *first, 2, color);
		}
	}
	else if (isBox){
		if (!(cur_point == Vec2::ZERO && pre_point == Vec2::ZERO)){
			drawNode->drawRect(pre_point, cur_point, color);
		}
	}		
	else if (isPolygon && pointArray.size() > 1){
		for (auto i = pointArray.begin(); i != pointArray.end() - 1; i++){
			drawNode->drawSegment(*i, *(i + 1), 2, color);
		}
	}
	else if (isCircle){
		int r = std::min(abs(pointArray[0].x - pointArray[1].x) / 2, abs(pointArray[0].y - pointArray[1].y) / 2);
		Vec2 center(std::max(pointArray[0].x, pointArray[1].x) - r, std::max(pointArray[0].y, pointArray[1].y) - r);
		drawNode->drawDot(center, r,Color4F(1, 1, 1, 1));
	
	}
}
void PaintingLayer::OnMenuClicked(Ref* ref){
	isSetPosition = false;
	isTriangle = false;
	isPolygon = false;
	isBox = false;
	isCircle = false;
	int tag = ((MenuItemFont*)ref)->getTag();
	switch (tag)
	{
	case 0:
		isSetPosition = true;
		break;
	case 1:
		isTriangle = true;
		break;
	case 2:
		isBox = true;
		break;
	case 3:
		isPolygon = true;
		break;
	case 4:
		NotificationCenter::getInstance()->postNotification("RePlay");
		break;
	case 5:
		isCircle = true;
		break;
	default:
		break;
	}
}
