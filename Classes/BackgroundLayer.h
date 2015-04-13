#ifndef _BACKGROUNDLAYER_H_
#define _BACKGROUNDLAYER_H_
#include"cocos2d.h"
USING_NS_CC;
class BackgroundLayer :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(BackgroundLayer);
};
#endif