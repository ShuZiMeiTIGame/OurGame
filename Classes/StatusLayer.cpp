#include"StatusLayer.h"
int StatusLayer::_level = 1;
bool StatusLayer::init(){
	if (!Layer::init())
		return false;
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	numberOfLevel = nullptr;
	return true;
}

void StatusLayer::showLevelNumber(){
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (numberOfLevel != nullptr){
		numberOfLevel->removeFromParentAndCleanup(true);
		free(numberOfLevel);
		numberOfLevel = nullptr;
	}
	numberOfLevel = Sprite::create(StringUtils::format("number%d.png", _level));
	numberOfLevel->setVisible(true);
	numberOfLevel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + numberOfLevel->getContentSize().width / 2));
	auto scale = ScaleTo::create(0.001f, 0);
	auto moveTo = MoveTo::create(0.6f, visibleSize / 2);
	auto rotate = RotateBy::create(0.6f, 720);
	auto scaleTo = ScaleTo::create(0.6f, 1.0f);
	auto spawn = Spawn::create(scale,moveTo, scaleTo, rotate, NULL);
	auto wait = MoveBy::create(0.9, Vec2::ZERO);
	
	auto fadeout = FadeOut::create(0.6f);
	auto scaleTo_out = ScaleTo::create(0.6f, 0.2f);
	auto rotateBy = RotateBy::create(0.6f, 720);
	auto spawn_out = Spawn::create(scaleTo_out, rotateBy, fadeout, NULL);
	auto fun = [=](){
		numberOfLevel->setVisible(false);
		numberOfLevel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + numberOfLevel->getContentSize().width / 2));
	};
	auto callfun = CallFunc::create(fun);
	auto sequence = Sequence::create(spawn, wait, spawn_out, callfun,NULL);
	numberOfLevel->runAction(sequence);
	addChild(numberOfLevel);
}
void StatusLayer::setLevel(int level){
	_level = level;
}
void StatusLayer::onEnterTransitionDidFinish(){
	Layer::onEnterTransitionDidFinish();
	showLevelNumber();
}


