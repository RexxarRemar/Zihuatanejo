#ifndef __ANT_H
#define __ANT_H
//#include "f:\cocos2d-x-3.3_proj\ant\cocos2d\cocos\2d\ccsprite.h"
#include"cocos2d.h"
USING_NS_CC;
class Ant :
	public Sprite
{
//ant的数据类写成一个单例类，这个地方不再写为单例
public:
	static Ant * getInstance();
private:
	Ant(void);
	~Ant(void);
//	static Sprite* sp;
};

#endif