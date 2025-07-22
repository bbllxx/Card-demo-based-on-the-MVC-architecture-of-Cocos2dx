// CardModel.h
#pragma once

#include"CardType.h"
#include"json/document.h"
#include"cocos2d.h"

USING_NS_CC;
/*
* 卡牌Model支持序列化和反序列化
*/
class CardModel {
public:
    CardModel(CardSuitType suit, CardFaceType face, cocos2d::Vec2 initPosition);

    //获取卡牌点数
    CardSuitType getSuit() const;
    CardFaceType getFace() const;

    //初始位置读取与写入
    cocos2d::Vec2 getInitPosition() const;

    //序列化
    void serialize(rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const;
        

    // 从 rapidjson 的对象反序列化
    //参数 value ：文件的value模块
    //返回值CardModel*
    static CardModel* deserialize(const rapidjson::Value& value);
 
private:
    CardSuitType _suit;//花色
    CardFaceType _face;//牌面
    cocos2d::Vec2 _initPosition;//卡牌初始位置
};
