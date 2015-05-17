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
	drawNode->setPosition(Vec2(0, 0));
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

	auto retuLable = MenuItemFont::create("Return", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	retuLable->setTag(6);
	retuLable->setPosition(Vec2(0, -250));

	auto menu = Menu::create(label, tranLabel, BoxLabel, PolygonLabel, rePlay, circle, retuLable, NULL);
	menu->setPosition(Vec2(100, visibleSize.height - 100));
	addChild(menu,10);
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
	pointArray.push_back(cur_point);
	return true;
}
void PaintingLayer::OnTouchMoved(Touch* touch, Event* event_){

	cur_point = touch->getLocation();
	if (isPolygon){
		if (pointArray.size() == 1){
			pointArray.push_back(cur_point);
			return;
		}
		auto end = *(pointArray.end() - 1);
		Vec2 dis = cur_point - end;
		if (sqrt(dis.x * dis.x + dis.y * dis.y) > 36)
		if (pointArray.size() < 200)
			pointArray.push_back(cur_point);
	}
	if (isTriangle || isCircle || isBox){
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
	const double PI = 3.141592653589793;
	if (pointArray.size() < 2){
		pointArray.clear();
		drawNode->clear();
		return;
	}
	cur_point = touch->getLocation();
	if (isPolygon && pointArray.size() > 2){
		drawNode->clear();
		Vec2 p0;
		auto first = pointArray.begin();
		float xOffSet = abs(pointArray.begin()->x - cur_point.x);
		float yOffSet = abs(pointArray.begin()->y - cur_point.y);
		if (xOffSet < 50 && yOffSet < 50){
			pointArray.pop_back();
			//pointArray.push_back(*first);
			p0 = *pointArray.begin();
			auto i = pointArray.begin();
			while (i != pointArray.end()){
				if (i->y < p0.y)
					p0 = (*i);
				else if (i->y == p0.y && i->x < p0.x)
					p0 = (*i);
				i++;
			}
			int size = pointArray.size();
			Vec2* tubao = new Vec2[size];
			tubao[0] = p0;
			pointArray.erase(std::find(pointArray.begin(), pointArray.end(), p0));
			//对左边进行相对于p0的逆时针坐标排序
			for (int j = 1; j < size; j++){
				std::vector<Vec2>::iterator right;
				auto i = pointArray.begin();
				double angle = PI;
				while (i != pointArray.end()){
					Vec2 pos = (*i) - p0;
					double ang = atan(pos.y / pos.x);
					if (ang < 0)
						ang = ang + PI;
					if (ang < angle){
						angle = ang;
						right = i;
					}
					i++;
				}
				tubao[j] = *right;
				pointArray.erase(right);
			}
			std::vector<Vec2> valuePos;
			valuePos.push_back(tubao[0]);
			valuePos.push_back(tubao[1]);
			for (int i = 0; i < size - 1; i++){
				auto end = valuePos.end() - 1;
				Vec2 p1 = *(end - 1);
				Vec2 p2 = *(end);
				Vec2 p3;
				if (i >= size - 2)
					 p3 = tubao[0];
				else
					 p3 = tubao[i + 2];
				if (isRight(p1, p2, p3))
					valuePos.push_back(p3);
				else{
					if (valuePos.size() > 1)
						valuePos.pop_back();
						i--;
				}
			}
			Color4F color = Color4F(Color4B(3, 171, 174, 255));
			auto begin = valuePos.begin();
			while (begin != valuePos.end() - 1){
				drawNode->drawSegment(*begin,*(begin+1),2,color);
				begin++;
			}
			drawNode->drawSegment(*valuePos.begin(), *(valuePos.end() - 1), 2, color);
			auto lam = [=](){
				drawNode->clear();
			};
			CallFunc* func = CallFunc::create(lam);
			auto wait = MoveBy::create(0.4f,Vec2::ZERO);
			auto sequence = Sequence::create(wait,func,NULL);
			drawNode->runAction(sequence);
			addChild(PhysicsWor::addPolygon(&valuePos));
			pointArray.clear();
		}
	}
	if (isBox){
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
			auto triangle = PhysicsWor::addSan(Vec2(100,100),&pointArray);
			addChild(triangle);
			pointArray.clear();
			drawNode->clear();
		}
	}
	if (isCircle){
		//int r = std::abs(pointArray[0].x - pointArray[1].x)/ 2;
		Vec2 center(Vec2::ZERO);
		int r = std::min(abs(pointArray[0].x - pointArray[1].x) / 2, abs(pointArray[0].y - pointArray[1].y) / 2);
		if (pointArray[0].x < pointArray[1].x)
			center = Vec2(pointArray[0].x + r, pointArray[0].y - r);
		else
			center = Vec2(pointArray[0].x - r, pointArray[0].y + r);
		if (!center.equals(Vec2::ZERO))
			addChild(PhysicsWor::addBall(center, r, 1));
	}
	if (!isPolygon && !isTriangle){
		pointArray.clear();
		drawNode->clear();
	}
	//清空坐标停止绘制
	pre_point = cur_point = Vec2::ZERO;
}
void PaintingLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	//DrawPrimitives::setDrawColor4B(3, 171, 174, 255);//看不见
	//glLineWidth(2.0f);
	if (pointArray.size() < 2)
		return;
	Color4F color = Color4F(Color4B(3,171,174,255));
	if (isTriangle){
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
		Vec2 center;
		int r = std::min(abs(pointArray[0].x - pointArray[1].x) / 2, abs(pointArray[0].y - pointArray[1].y) / 2);
		if (pointArray[0].x < pointArray[1].x)
			center = Vec2(pointArray[0].x + r, pointArray[0].y - r);
		else
			center = Vec2(pointArray[0].x - r, pointArray[0].y + r);
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
	case 6:
		Director::getInstance()->popScene();
		break;
	default:
		break;
	}
}
bool PaintingLayer::isRight(Vec2 p1, Vec2 p2, Vec2 p3){
	Vec2 a = p2 - p1;
	Vec2 b = p3 - p1;
	if ((a.x * b.y - a.y * b.x) > 0)
		return true;
	return false;
}