#pragma once

#include "cocos2d.h"


class GameSceneController : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    //初始化
    virtual bool init();
    
    //回退按键的逻辑处理
    void handleGoBackClick();

    //卡牌点击的逻辑处理
    //参数 cardId：被点击的对象ID
    void handleCardClick(int cardId);

    //反序列初始化对象
    void deserializeCardInit();

    //设置回调函数，为回调函数赋值
    void setCardViewCallBack();
    
    // 通过Cocos宏创建create函数
    CREATE_FUNC(GameSceneController);
};


