#ifndef __BOX_H__
#define __BOX_H__
#include "cocos2d.h"
USING_NS_CC;
static class Box//生成矩形刚体
{
public:
	//began时的点，end时的点，重力
	static Sprite*addBox(Vec2 a, Vec2 b, int c);
private:
};
#endif