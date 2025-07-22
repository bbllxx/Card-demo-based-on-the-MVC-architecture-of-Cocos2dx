#pragma once
#include "cocos2d.h"

USING_NS_CC;
/*
* 回退键的视图，以及回退键监视器
*/

class GoBackView:public cocos2d::Layer
{
public:

	virtual bool init();

	//当用户点击“回退”按钮时调用，供外部绑定实际处理逻辑
	std::function<void()> onGoBackCallBack;

	CREATE_FUNC(GoBackView);

};

