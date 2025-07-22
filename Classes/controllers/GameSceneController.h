#pragma once

#include "cocos2d.h"

class GameSceneController : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    
    // 通过Cocos宏创建create函数
    CREATE_FUNC(GameSceneController);
};


