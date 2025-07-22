

#include "GameSceneController.h"
#include "SimpleAudioEngine.h"
#include"views/BackGroundView.h"
#include"views/GoBackView.h"

USING_NS_CC;

Scene* GameSceneController::createScene()
{
    return GameSceneController::create();
}

// ��ʼ�� instance
bool GameSceneController::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    Layer* bg = BackGroundView::create();//����
    GoBackView* gb = GoBackView::create();//���˼�
    this->addChild(bg);
    this->addChild(gb);
    
    return true;
}

