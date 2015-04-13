#ifndef _STATUSLAYER_H_
#define _STATUSLAYER_H_
#include"cocos2d.h"
USING_NS_CC;
class StatusLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(StatusLayer);
	void showLevelNumber();
	void setLevel(int level);
	void onEnterTransitionDidFinish();
private:
	static int _level;
	Sprite* numberOfLevel;
};
#endif