#pragma once

#include "cocos2d.h"

class GameSceneController : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    
    // ͨ��Cocos�괴��create����
    CREATE_FUNC(GameSceneController);
};


