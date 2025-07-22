#pragma once
#include"cocos2d.h"

USING_NS_CC;
/*
* 背景视图，仅实现背景效果
*/
class BackGroundView :public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(BackGroundView);
};

