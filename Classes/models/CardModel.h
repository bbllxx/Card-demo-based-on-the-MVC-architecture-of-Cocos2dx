// CardModel.h
#pragma once

#include"CardType.h"
#include"json/document.h"
#include"cocos2d.h"

USING_NS_CC;
/*
* ����Model֧�����л��ͷ����л�
*/
class CardModel {
public:
    CardModel(CardSuitType suit, CardFaceType face, cocos2d::Vec2 initPosition);

    //��ȡ���Ƶ���
    CardSuitType getSuit() const;
    CardFaceType getFace() const;

    //��ʼλ�ö�ȡ��д��
    cocos2d::Vec2 getInitPosition() const;

    //���л�
    void serialize(rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const;
        

    // �� rapidjson �Ķ������л�
    //���� value ���ļ���valueģ��
    //����ֵCardModel*
    static CardModel* deserialize(const rapidjson::Value& value);
 
private:
    CardSuitType _suit;//��ɫ
    CardFaceType _face;//����
    cocos2d::Vec2 _initPosition;//���Ƴ�ʼλ��
};
