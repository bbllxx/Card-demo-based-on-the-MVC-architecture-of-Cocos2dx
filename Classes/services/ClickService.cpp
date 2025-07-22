#include "ClickService.h"
#include "managers/CardManager.h"
#include "models/GameModel.h"
#include "models/CardModel.h"
#include "views/CardView.h"
#include "configs/ConfigLoader.h"

bool ClickService::goBackClick()
{
    GameModel& gameModel = GameModel::getInstance();

    if (gameModel.undostack.empty()) return false;//判断参照牌区栈是否为空

    //获取卡牌与图片对象指针
    int cardId = gameModel.undostack.top();
    CardView* cardView = gameModel.cardViews[cardId];
    CardModel* cardModel = gameModel.cardObjs[cardId];

    (*cardView).animationGoBack();//执行动画
    (*cardView).setTouchActive(true);//恢复Layer响应
    gameModel.undostack.pop();//退栈

    if ((*cardModel).getInitPosition().y <= 580)//判断区域
    {
        //获取stack底部元素
        if (!gameModel.stack.empty())
        {
            int stackBackId = gameModel.stack[gameModel.stack.size() - 1];
            (*gameModel.cardViews[stackBackId]).setTouchActive(false); //关闭输入响应
        }
        gameModel.addCardToArea(3, cardId);
    }
    else
    {
        int area = ((*cardModel).getInitPosition().x <= 540) ? 1 : 2;//判断区域
        if (area == 1)
        {
            //获取playfield_1底部元素
            if (!gameModel.playfield_1.empty())
            {
                int playBackId = gameModel.playfield_1[gameModel.playfield_1.size() - 1];
                (*gameModel.cardViews[playBackId]).setTouchActive(false);//关闭输入响应
            }
        }
        else
        {
            //获取playfield_2底部元素
            if (!gameModel.playfield_2.empty())
            {
                int playBackId = gameModel.playfield_2[gameModel.playfield_2.size() - 1];
                (*gameModel.cardViews[playBackId]).setTouchActive(false);//关闭输入响应
            }
        }
        gameModel.addCardToArea(area, cardId);//添加卡牌到对于区域
    }

    return true;
}

void ClickService::cardClick(int cardId)
{
    CardManager cardManager;

    //判断是否满足条件并把card挪入相应区域
    int area = cardManager.checkAndMoveToStack(cardId);
    if (!area) CCLOG("CAN NOT");
    if (area)
    {
        //获取cardView指针
        GameModel& gameModel = GameModel::getInstance();
        CardView* cardView = gameModel.cardViews[cardId];

        (*cardView).animationToStack();//执行动画
        (*cardView).setLocalZOrder(gameModel.undostack.size() + 2);//设置层级
        (*cardView).setTouchActive(false);//关闭响应

        if (area == 1&& !gameModel.playfield_1.empty())
        {
            //获取playfield_1底部元素
            int playBackId = gameModel.playfield_1[gameModel.playfield_1.size() - 1];
            (*gameModel.cardViews[playBackId]).setTouchActive(true);//开启输入响应
        }
        else if(area == 2 && !gameModel.playfield_2.empty())
        {
            //获取playfield_2底部元素
            int playBackId = gameModel.playfield_2[gameModel.playfield_2.size() - 1];
            (*gameModel.cardViews[playBackId]).setTouchActive(true);//开启输入响应
        }
        else if(!gameModel.stack.empty())
        {
            //获取stack底部元素
            int stackBackId = gameModel.stack[gameModel.stack.size() - 1];
            (*gameModel.cardViews[stackBackId]).setTouchActive(true); //开启输入响应
        }
    }
}

void ClickService::deserializeCard()
{
    //读取文件
    rapidjson::Document* doc = ConfigLoader::loadCardModelFromFile("configs/InitGameConfig.json");
    if (!doc) CCLOG("InitGameConfig.json error ");

    GameModel& gameModel = GameModel::getInstance();

    //// 反序列化 Playfield 中的每个卡片
    if (doc->HasMember("Playfield") && (*doc)["Playfield"].IsArray()) {
        const rapidjson::Value& playfield = (*doc)["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfield.Size(); i++) {
            CardModel* card = CardModel::deserialize(playfield[i]);
            gameModel.addCardToObjs(card);
        }
    }

    // 反序列化 Stack 中的每个卡片
    if (doc->HasMember("Stack") && (*doc)["Stack"].IsArray()) {
        const rapidjson::Value& stack = (*doc)["Stack"];
        for (rapidjson::SizeType i = 0; i < stack.Size(); i++) {
            CardModel* card = CardModel::deserialize(stack[i]);
            gameModel.addCardToObjs(card);
        }
    }

    //根据所有卡片信息批量创建视图
    for (auto i = 0; i < gameModel.cardObjs.size(); i++)
    {
        CardModel* cardModel = gameModel.cardObjs[i];
        CardView* cardView = CardView::create(
            (*cardModel).getFace(),
            (*cardModel).getSuit(), 
            (*cardModel).getInitPosition()
        );
        gameModel.cardViews.push_back(cardView);
        (*cardView).setTouchActive(false);//默认关闭Layer响应
    }

    //获取stack底部元素
    int stackBackId = gameModel.stack[gameModel.stack.size() - 1];
    (*gameModel.cardViews[stackBackId]).setTouchActive(true); //开启输入响应
    //获取playfield_1底部元素
    int playBackId = gameModel.playfield_1[gameModel.playfield_1.size() - 1];
    (*gameModel.cardViews[playBackId]).setTouchActive(true);//开启输入响应
    //获取playfield_2底部元素
     playBackId = gameModel.playfield_2[gameModel.playfield_2.size() - 1];
    (*gameModel.cardViews[playBackId]).setTouchActive(true);//开启输入响应
}
