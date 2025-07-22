#pragma once
#include"CardModel.h"
#include"views/CardView.h"

//��Ϸģʽ�����洢playfield��stack��Ϣ�Լ�����ջ
class GameModel {
public:
    static GameModel& getInstance(); // ��ȡ����ʵ��

    // ���ø��ƺ͸�ֵ����ֹ�������졢��ֵ���죩
    GameModel(const GameModel&) = delete;
    GameModel& operator=(const GameModel&) = delete;

    std::vector<CardModel*>cardObjs;//��Ƭ�߼�����洢��
    std::vector<CardView*>cardViews;//������ʾ����洢��

    std::vector<int> playfield_1;//���������� 1
    std::vector<int> playfield_2;//���������� 2
    std::vector<int> stack;//��������3
    std::stack<int> undostack;//��������0

    //��ӿ���ID����������
    //����1 area ��������������
    //����2 cardId ������ӿ���ID
    void addCardToArea(int area, int cardId);
    //�Ƴ���Ӧ������ID
    //����1 area �����Ƴ��������
    void popCardToArea(int area);

    //��ӿ��Ƶ�cardobjs
    void addCardToObjs(CardModel* card);

private:
    GameModel(); // ˽�й���
    ~GameModel(); // ˽������
};

