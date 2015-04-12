#include "AppDelegate.h"
<<<<<<< HEAD
#include "HelloWorldScene.h"
#include"GameSceneOne.h"
=======
#include"StartScene.h"
<<<<<<< HEAD
#include"DBtest.h"
=======
>>>>>>> origin/master
>>>>>>> c91268dcd4d76477740f67f943c9e815866036a1

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
		//glview->setFrameSize(480, 320);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
<<<<<<< HEAD
	auto scene = StartScene::createScene();
=======
    auto scene = HelloWorld::createScene();

>>>>>>> c91268dcd4d76477740f67f943c9e815866036a1
    // run
    director->runWithScene(scene);

    return true;
}


void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
