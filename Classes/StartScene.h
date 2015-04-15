#ifndef _STARTSCENE_H_
#define _STARTSCENE_H_
#include"cocos2d.h"
#include"GameTime.h"
USING_NS_CC;
class StartScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StartScene);
private:
	//菜单回调函数
	void menuCallBack_S(Ref* ref);
	void menuCallBack_A(Ref* ref);
	void menuCallBack_E(Ref* ref);
};
#endif