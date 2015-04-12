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
	//是否设置物体为静态  
	//ballBody->setDynamic(false);  
	//设置物体的恢复力  
	//ballBody->getShape(0)->setRestitution(1.0f);
	//设置物体的摩擦力  
	ballBody->getShape(0)->setFriction(0.1f);
	//设置物体密度  
	ballBody->getShape(0)->setDensity(0.0f);
	//设置质量  
	ballBody->getShape(0)->setMass(c);
	//设置物体是否受重力系数影响  
	ballBody->setGravityEnable(true);
	//设置物体的冲力  
	//Vect force = Vect(50000.0f, 0.0f);
	//ballBody->applyImpulse(force);
	//把物体添加到精灵中  
	ball->setPhysicsBody(ballBody);
	//this->addChild(ball, 1);
	return ball;
}
