#include"PaintingLayer.h"

bool PaintingLayer::init(){
	if (!Layer::init())
		return false;
	//��ȡ��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//������ʼ��
	isSetPosition = false;
	isTriangle = false;
	isPolygon = false;
	isBox = false;
	//��ʼ������
	pre_point = cur_point = Vec2::ZERO;
	//����DrawNode
	drawNode = DrawNode::create();
	addChild(drawNode,20);
	//���Ʋ˵�
	auto label = MenuItemFont::create("setPositon", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	label->setTag(0);
	label->setPosition(Vec2(0, -100));
	auto tranLabel = MenuItemFont::create("Triangle", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	tranLabel->setTag(1);
	tranLabel->setPosition(Vec2(0, -50));
	auto BoxLabel = MenuItemFont::create("Box", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	BoxLabel->setTag(2);
	BoxLabel->setPosition(Vec2(0, 0));
	auto PolygonLabel = MenuItemFont::create("Polygon", CC_CALLBACK_1(PaintingLayer::OnMenuClicked, this));
	PolygonLabel->setTag(3);
	PolygonLabel->setPosition(Vec2(0, 50));

	auto menu = Menu::create(label, tranLabel, BoxLabel, PolygonLabel, NULL);
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
	if (isPolygon){
		pointArray.push_back(cur_point);
		//�ж�ֱ���Ƿ��ཻ
		/*if (pointArray.size() >= 2){
		for (auto i = pointArray.end() - 1; i != pointArray.begin() - 1; i--){
		i, i - 1;
		}
		}*/
	}
	if (isTriangle){
		pointArray.push_back(cur_point);
	}
	return true;
}
void PaintingLayer::OnTouchMoved(Touch* touch, Event* event_){
	cur_point = touch->getLocation();
	if (isBox)
		drawNode->clear();
	if (isPolygon || isTriangle){
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
			//���������
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
	//�������ֹͣ����
	pre_point = cur_point = Vec2::ZERO;
}
void PaintingLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	//DrawPrimitives::setDrawColor4B(3, 171, 174, 255);//������
	//glLineWidth(2.0f);
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
}
void PaintingLayer::OnMenuClicked(Ref* ref){
	isSetPosition = false;
	isTriangle = false;
	isPolygon = false;
	isBox = false;
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
	default:
		break;
	}
}
