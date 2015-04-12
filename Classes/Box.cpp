#include"Box.h"

 Sprite* Box::addBox(Vec2 a, Vec2 b,int c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int width = abs((a - b).x);
	int height = abs((a - b).y);
	auto box = Sprite::create("1.png", Rect(a.x, a.y, width, height));
	box->setPosition((a.x+b.x)/2, (a.y+b.y)/2);
	Point boxPoint = Vec2(width, height);
	PhysicsBody* boxBody = PhysicsBody::createBox(Size (boxPoint));
	//�Ƿ���������Ϊ��̬  
	//boxBody->setDynamic(false);
	//��������Ļָ���  
	boxBody->getShape(0)->setRestitution(0.0f);
	//���������Ħ����  
	boxBody->getShape(0)->setFriction(0.5f);
	//���������ܶ�  
	boxBody->getShape(0)->setDensity(7.0f);
	//��������  
	boxBody->getShape(0)->setMass(c);
	//���������Ƿ�������ϵ��Ӱ��  
	boxBody->setGravityEnable(true);
	//��������ӵ�������  
	box->setPhysicsBody(boxBody);
	return box;
}
