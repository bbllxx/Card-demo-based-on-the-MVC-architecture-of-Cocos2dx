#pragma once
#include<cocos2d.h>
#include"models/CardType.h"
USING_NS_CC;

/*
*��Ƭ��ͼlayer��ʵ�ֿ�Ƭ�Ӿ�Ч����������ͬʱ�Զ�������¼����Դ���
* �ж���Ӧ�¼�ͬʱͨ���ص���������Ϣ������controller��
*/
class CardView : public cocos2d::Layer {
public:
    //create��������Node��autorelease;
    static CardView* create(CardFaceType face, CardSuitType suit,Vec2 initPosition);

    //��ʼ�����ݣ���������Node��ͼ
    bool init(CardFaceType face, CardSuitType suit, Vec2 initPosition);

    //��ȡ��ʼλ��
    Vec2 getInitPosition();
    
    //��д_cardId
    int getCardId();
    void setCardId(int id);

    //�����¼����ư�ť
    void setTouchActive(bool active);

    //�ص�
    std::function<void(int)> onCardClickCallBack;

    //�ƶ�����
    void animationToStack();
    void animationGoBack();

    //��ʼ�㼶����
    void setInitZOrder(int zOrder);
    int getInitZOrder();

private:
    Vec2 _initPosition;//��ʼλ��
    int _cardId;//�������еĴ洢λ��
    int _initZOrder;//����ʱĬ�����ɵĲ㼶
    EventListenerTouchOneByOne* _touchListener = nullptr;//������
};

