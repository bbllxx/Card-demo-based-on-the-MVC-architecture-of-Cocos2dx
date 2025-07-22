#pragma once
#include"CardModel.h"
#include"views/CardView.h"

//游戏模式用来存储playfield、stack信息以及回退栈
class GameModel {
public:
    static GameModel& getInstance(); // 获取单例实例

    // 禁用复制和赋值（防止拷贝构造、赋值构造）
    GameModel(const GameModel&) = delete;
    GameModel& operator=(const GameModel&) = delete;

    std::vector<CardModel*>cardObjs;//卡片逻辑对象存储区
    std::vector<CardView*>cardViews;//卡牌显示对象存储区

    std::vector<int> playfield_1;//公共牌左区 1
    std::vector<int> playfield_2;//公共牌右区 2
    std::vector<int> stack;//手牌左区3
    std::stack<int> undostack;//手牌右区0

    //添加卡牌ID到对于区域
    //参数1 area ：待添加区域代号
    //参数2 cardId ；待添加卡牌ID
    void addCardToArea(int area, int cardId);
    //移除对应区域卡牌ID
    //参数1 area ：待移除区域代号
    void popCardToArea(int area);

    //添加卡牌到cardobjs
    void addCardToObjs(CardModel* card);

private:
    GameModel(); // 私有构造
    ~GameModel(); // 私有析构
};

