#include"Ball.h"
Sprite*Ball::addBall(Vec2 a,Vec2 b,int c)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int width = abs((a - b).x);
	int height = abs((a - b).y);
	auto ball = Sprite::create("CloseNormal.png");
	ball->setScale(2*width/ball->getContentSize().width );
	ball->setPosition((a+b)/2);
	/////////////
	PhysicsBody* ballBody = PhysicsBody::createCircle(width, PHYSICSBODY_MATERIAL_DEFAULT);
	//�Ƿ���������Ϊ��̬  
	//ballBody->setDynamic(false);  
	//��������Ļָ���  
	//ballBody->getShape(0)->setRestitution(1.0f);
	//���������Ħ����  
	ballBody->getShape(0)->setFriction(0.1f);
	//���������ܶ�  
	ballBody->getShape(0)->setDensity(0.0f);
	//��������  
	ballBody->getShape(0)->setMass(c);
	//���������Ƿ�������ϵ��Ӱ��  
	ballBody->setGravityEnable(true);
	//��������ĳ���  
	//Vect force = Vect(50000.0f, 0.0f);
	//ballBody->applyImpulse(force);
	//��������ӵ�������  
	ball->setPhysicsBody(ballBody);
	//this->addChild(ball, 1);
	return ball;
}
