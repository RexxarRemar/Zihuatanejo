#ifndef __ANT_H
#define __ANT_H
//#include "f:\cocos2d-x-3.3_proj\ant\cocos2d\cocos\2d\ccsprite.h"
#include"cocos2d.h"
USING_NS_CC;
class Ant :
	public Sprite
{
//ant��������д��һ�������࣬����ط�����дΪ����
public:
	static Ant * getInstance();
private:
	Ant(void);
	~Ant(void);
//	static Sprite* sp;
};

#endif