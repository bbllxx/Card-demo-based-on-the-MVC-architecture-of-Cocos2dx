#include "GameModel.h"

GameModel::GameModel() {
    // ��ʼ������
}

GameModel::~GameModel() {
    // ��������
    for (auto card : cardObjs)
    {
        delete card;
    }
}

GameModel& GameModel::getInstance() {
    static GameModel instance;  // C++11 ��֤�̰߳�ȫ
    return instance;
}

void GameModel::addCardToArea(int area, int cardId)
{
    switch (area) {
    case 0: undostack.push(cardId);break;//0������������
    case 1: playfield_1.push_back(cardId); break;//1��������1��
    case 2: playfield_2.push_back(cardId); break;//2��������2��
    case 3: stack.push_back(cardId); break;//3������������
    }
}

void GameModel::popCardToArea(int area)
{
    switch (area) {
    case 0: undostack.pop(); break;//0������������
    case 1: playfield_1.pop_back(); break;//1��������1��
    case 2: playfield_2.pop_back(); break;//2��������2��
    case 3: stack.pop_back(); break;//3������������
    }
}

void GameModel::addCardToObjs(CardModel* card)
{
    cardObjs.push_back(card);//��ӵ���Ƭ������

    //��ӵ���ؿ����߼���
    int id = cardObjs.size() - 1;
    if ((*card).getInitPosition().y<=580) { addCardToArea(3, id); }
    else
    {
        if ((*card).getInitPosition().x <= 540) { addCardToArea(1, id); }
        else { addCardToArea(2, id); }
    }
}


