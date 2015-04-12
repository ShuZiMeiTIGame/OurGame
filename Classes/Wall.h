#ifndef __WALL_H__
#define __WALL_H__
#include "cocos2d.h"
USING_NS_CC;
class Wall:cocos2d::Layer
{
public:
	static Sprite*addWall(Vec2 p);
private:

};
#endif