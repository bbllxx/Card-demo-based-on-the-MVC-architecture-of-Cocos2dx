#pragma once

#include "cocos2d.h"


class GameSceneController : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    //��ʼ��
    virtual bool init();
    
    //���˰������߼�����
    void handleGoBackClick();

    //���Ƶ�����߼�����
    //���� cardId��������Ķ���ID
    void handleCardClick(int cardId);

    //�����г�ʼ������
    void deserializeCardInit();

    //���ûص�������Ϊ�ص�������ֵ
    void setCardViewCallBack();
    
    // ͨ��Cocos�괴��create����
    CREATE_FUNC(GameSceneController);
};


