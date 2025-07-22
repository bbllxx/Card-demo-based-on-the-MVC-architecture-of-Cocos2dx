

#include "GameSceneController.h"
#include "SimpleAudioEngine.h"
#include"views/BackGroundView.h"
#include"views/GoBackView.h"

USING_NS_CC;

Scene* GameSceneController::createScene()
{
    return GameSceneController::create();
}

// ³õÊ¼»¯ instance
bool GameSceneController::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    Layer* bg = BackGroundView::create();//±³¾°
    GoBackView* gb = GoBackView::create();//»ØÍË¼ü
    this->addChild(bg);
    this->addChild(gb);
    
    return true;
}

