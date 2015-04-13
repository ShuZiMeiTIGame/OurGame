#include"BackgroundLayer.h"
bool BackgroundLayer::init(){
	if (!Layer::init())
		return false;
	//��ȡ��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����ɫ
	//auto bg = CCLayerColor::create(Color4B(34, 177, 22, 255), visibleSize.width, visibleSize.height);
	auto bg = CCLayerColor::create(Color4B(0, 0, 0, 255), visibleSize.width, visibleSize.height);
	//auto bg = CCLayerColor::create(Color4B(255, 255, 255, 255), visibleSize.width, visibleSize.height);
	addChild(bg);
	return true;
}
