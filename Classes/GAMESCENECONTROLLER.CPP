

#include "GameSceneController.h"
#include "SimpleAudioEngine.h"
#include"views/BackGroundView.h"
#include"views/GoBackView.h"
#include"services/ClickService.h"
#include "models/GameModel.h"

USING_NS_CC;

Scene* GameSceneController::createScene()
{
    return GameSceneController::create();
}

// 初始化 instance
bool GameSceneController::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    //场景初始化
    Layer* bg = BackGroundView::create();//背景
    auto gb = GoBackView::create();//回退键
    gb->onGoBackCallBack = [this]() {
        handleGoBackClick();
        };//设置回调函数
    this->addChild(bg);
    this->addChild(gb);

    //关卡初始化
    deserializeCardInit();

    //添加在scene上并设置回调
    setCardViewCallBack();

    return true;
}

void GameSceneController::handleGoBackClick()
{
     ClickService::goBackClick();//回退键逻辑
}



void GameSceneController::handleCardClick(int cardId)
{
    ClickService::cardClick(cardId);//卡牌点击逻辑
}

void GameSceneController::deserializeCardInit()
{
    ClickService::deserializeCard();//初始化逻辑
}

void GameSceneController::setCardViewCallBack()
{
    GameModel& gameModel = GameModel::getInstance();
    for (auto i = 0; i < gameModel.cardViews.size(); i++)
    {
        //显示卡片视图
        CardView* cardView = gameModel.cardViews[i];
        this->addChild(cardView);//将视图绑定scene

        //给初始层级赋默认值
        (*cardView).setInitZOrder((*cardView).getLocalZOrder());

        //给回调函数对象赋值
        (*cardView).onCardClickCallBack = [=](int) {
            handleCardClick(i);
            };
    }
}


