#include"StartScene.h"
Scene* StartScene::createScene(){
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);
	return scene;
}
bool StartScene::init(){
	if (!Layer::init())
		return false;
	//获取屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//开始菜单背景精灵
	auto bkg = Sprite::create("ScrollView.jpg");
	bkg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(bkg);
	//菜单
	auto startLabel = CCMenuItemFont::create("Start",CC_CALLBACK_1(StartScene::menuCallBack_S,this));
	startLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(startLabel);
	auto aboutLabel = CCMenuItemFont::create("About", CC_CALLBACK_1(StartScene::menuCallBack_A, this));;
	aboutLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(aboutLabel);
	auto exitLabel = CCMenuItemFont::create("Exit", CC_CALLBACK_1(StartScene::menuCallBack_E, this));;
	exitLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
	addChild(exitLabel);

	return true;
}

void StartScene::menuCallBack_S(Ref* ref){
	Director::getInstance()->replaceScene(GameTime::createScene());
}
void StartScene::menuCallBack_A(Ref* ref){

}
void StartScene::menuCallBack_E(Ref* ref){
	Director::getInstance()->end();
}







