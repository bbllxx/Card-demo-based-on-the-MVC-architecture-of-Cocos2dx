// CardModel.cpp
#include "CardModel.h"

CardModel::CardModel(CardSuitType suit, CardFaceType face, cocos2d::Vec2 initPosition)
    : _suit(suit), _face(face), _initPosition(initPosition) {}

CardSuitType CardModel::getSuit() const { return _suit; }
CardFaceType CardModel::getFace() const { return _face; }

cocos2d::Vec2 CardModel::getInitPosition() const{ return _initPosition; }

//���л�
void CardModel::serialize(rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const {
    value.SetObject();
    value.AddMember("CardFace", _face, allocator);
    value.AddMember("CardSuit", _suit, allocator);

    rapidjson::Value pos(rapidjson::kObjectType);
    pos.AddMember("x", _initPosition.x, allocator);
    pos.AddMember("y", _initPosition.y, allocator);
    value.AddMember("Position", pos, allocator);
}

// �� rapidjson �Ķ������л���������
CardModel* CardModel::deserialize(const rapidjson::Value& value) {
    const int face = value["CardFace"].GetInt();
    const int suit = value["CardSuit"].GetInt();
    const float positionX = value["Position"]["x"].GetFloat();
    const float positionY = value["Position"]["y"].GetFloat();
    return new CardModel(static_cast<CardSuitType>(suit), static_cast<CardFaceType>(face), Vec2(positionX, positionY));
}

