#include "AppDelegate.h"
<<<<<<< HEAD
#include "HelloWorldScene.h"
#include"GameSceneOne.h"
#include"GameSceneTwo.h"

=======
#include"StartScene.h"
>>>>>>> origin/master
USING_NS_CC;

AppDelegate::AppDelegate() {
}
<<<<<<< HEAD

AppDelegate::~AppDelegate() {
=======
//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
>>>>>>> origin/master
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	
    if(!glview) {
<<<<<<< HEAD
        glview = GLView::create("My Game");
=======
        glview = GLViewImpl::create("My Game");
		glview->setFrameSize(1670, 749);
>>>>>>> origin/master
        director->setOpenGLView(glview);
		//glview->setFrameSize(480, 320);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
<<<<<<< HEAD
	auto scene = GameSceneTwo::createScene();
=======
>>>>>>> origin/master

	auto scene = StartScene::createScene();
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
