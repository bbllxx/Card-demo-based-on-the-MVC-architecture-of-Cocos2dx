#include "GoBackView.h"

bool GoBackView::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
    auto label = cocos2d::Label::createWithSystemFont("回退", "Arial", 80);
    label->setPosition(cocos2d::Vec2(950, 290));  // 设置位置
    this->addChild(label);

    // 创建触摸事件监听器
    auto _touchListener = cocos2d::EventListenerTouchOneByOne::create();

    // 设置触摸开始事件回调
    _touchListener->onTouchBegan = [this, label](cocos2d::Touch* touch, cocos2d::Event* event) {
        // 判断触摸是否在文字按钮区域内
        cocos2d::Rect labelRect = label->getBoundingBox();
        if (labelRect.containsPoint(touch->getLocation())) {
            // 如果在按钮区域内，执行回调
            if (onGoBackCallBack) {
                onGoBackCallBack();  // 通知控制器
            }
            return true;  // 触摸事件被处理
        }
        return false;  // 其他地方点击不处理
        };

    // 添加触摸事件监听器
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

    return true;
}
