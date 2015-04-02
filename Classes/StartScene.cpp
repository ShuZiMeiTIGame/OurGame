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
	//��ȡ��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//��ʼ�˵���������
	auto bkg = Sprite::create("ScrollView.jpg");
	bkg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(bkg);
	//�˵�
	auto startLabel = CCMenuItemFont::create("Start",CC_CALLBACK_1(StartScene::menuCallBack_S,this));
	startLabel->setPosition(Vec2(0,100));
	auto aboutLabel = CCMenuItemFont::create("About", CC_CALLBACK_1(StartScene::menuCallBack_A, this));;
	aboutLabel->setPosition(Vec2::ZERO);
	auto exitLabel = CCMenuItemFont::create("Exit", CC_CALLBACK_1(StartScene::menuCallBack_E, this));;
	exitLabel->setPosition(Vec2(0,-100));

	auto menu = Menu::create(startLabel, aboutLabel, exitLabel,NULL);
	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(menu);
	return true;
}

void StartScene::menuCallBack_S(Ref* ref){
	//Transaction
	Director::getInstance()->replaceScene(GameTime::createScene());
}
void StartScene::menuCallBack_A(Ref* ref){

}
void StartScene::menuCallBack_E(Ref* ref){
	Director::getInstance()->end();
}







