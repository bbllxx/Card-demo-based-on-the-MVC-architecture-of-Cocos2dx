#pragma once
#include<string>
#include"models/CardType.h"

/*
* 静态工具函数，用以将枚举与文件字符相对应
*/

std::string getFaceString(CardFaceType face)
{
    //枚举点数
    static const std::string faceNames[] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };
    const int index = face;
    if (index < 0 || index >= 13) return "Unknown";
    return faceNames[index];
}

std::string getSuitString(CardSuitType suit)
{
    //枚举花色
    static const std::string suitNames[] = {
        "club", "diamond", "heart", "spade"
    };
    const int index = suit;
    if (index < 0 || index >= 4) return "Unknown";
    return suitNames[index];
}
