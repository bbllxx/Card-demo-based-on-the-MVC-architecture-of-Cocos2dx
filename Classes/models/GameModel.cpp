#include "GameModel.h"

GameModel::GameModel() {
    // 初始化数据
}

GameModel::~GameModel() {
    // 清理数据
    for (auto card : cardObjs)
    {
        delete card;
    }
}

GameModel& GameModel::getInstance() {
    static GameModel instance;  // C++11 保证线程安全
    return instance;
}

void GameModel::addCardToArea(int area, int cardId)
{
    switch (area) {
    case 0: undostack.push(cardId);break;//0代表手牌右区
    case 1: playfield_1.push_back(cardId); break;//1代表公共牌1区
    case 2: playfield_2.push_back(cardId); break;//2代表公共牌2区
    case 3: stack.push_back(cardId); break;//3代表手牌左区
    }
}

void GameModel::popCardToArea(int area)
{
    switch (area) {
    case 0: undostack.pop(); break;//0代表手牌右区
    case 1: playfield_1.pop_back(); break;//1代表公共牌1区
    case 2: playfield_2.pop_back(); break;//2代表公共牌2区
    case 3: stack.pop_back(); break;//3代表手牌左区
    }
}

void GameModel::addCardToObjs(CardModel* card)
{
    cardObjs.push_back(card);//添加到卡片数组中

    //添加到相关卡牌逻辑区
    int id = cardObjs.size() - 1;
    if ((*card).getInitPosition().y<=580) { addCardToArea(3, id); }
    else
    {
        if ((*card).getInitPosition().x <= 540) { addCardToArea(1, id); }
        else { addCardToArea(2, id); }
    }
}


