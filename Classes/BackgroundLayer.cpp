#include"BackgroundLayer.h"
bool BackgroundLayer::init(){
	if (!Layer::init())
		return false;
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//背景色
	//auto bg = CCLayerColor::create(Color4B(34, 177, 22, 255), visibleSize.width, visibleSize.height);
	auto bg = CCLayerColor::create(Color4B(0, 0, 0, 255), visibleSize.width, visibleSize.height);
	//auto bg = CCLayerColor::create(Color4B(255, 255, 255, 255), visibleSize.width, visibleSize.height);
	addChild(bg);
	return true;
}
