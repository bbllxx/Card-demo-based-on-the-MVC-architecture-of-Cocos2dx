#pragma once
#include "cocos2d.h"

USING_NS_CC;
/*
* ���˼�����ͼ���Լ����˼�������
*/

class GoBackView:public cocos2d::Layer
{
public:

	virtual bool init();

	//���û���������ˡ���ťʱ���ã����ⲿ��ʵ�ʴ����߼�
	std::function<void()> onGoBackCallBack;

	CREATE_FUNC(GoBackView);

};

