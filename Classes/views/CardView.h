#pragma once
#include<cocos2d.h>
#include"models/CardType.h"
USING_NS_CC;

/*
*卡片视图layer，实现卡片视觉效果及动画，同时自定义监听事件，以此来
* 判断相应事件同时通过回调函数将信息传递至controller。
*/
class CardView : public cocos2d::Layer {
public:
    //create函数创建Node并autorelease;
    static CardView* create(CardFaceType face, CardSuitType suit,Vec2 initPosition);

    //初始化数据，用来构建Node视图
    bool init(CardFaceType face, CardSuitType suit, Vec2 initPosition);

    //获取初始位置
    Vec2 getInitPosition();
    
    //读写_cardId
    int getCardId();
    void setCardId(int id);

    //监听事件控制按钮
    void setTouchActive(bool active);

    //回调
    std::function<void(int)> onCardClickCallBack;

    //移动动画
    void animationToStack();
    void animationGoBack();

    //初始层级设置
    void setInitZOrder(int zOrder);
    int getInitZOrder();

private:
    Vec2 _initPosition;//初始位置
    int _cardId;//在数组中的存储位置
    int _initZOrder;//创建时默认生成的层级
    EventListenerTouchOneByOne* _touchListener = nullptr;//监听器
};

