#pragma once
#include<string>
#include"models/CardType.h"

/*
* ��̬���ߺ��������Խ�ö�����ļ��ַ����Ӧ
*/

std::string getFaceString(CardFaceType face)
{
    //ö�ٵ���
    static const std::string faceNames[] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };
    const int index = face;
    if (index < 0 || index >= 13) return "Unknown";
    return faceNames[index];
}

std::string getSuitString(CardSuitType suit)
{
    //ö�ٻ�ɫ
    static const std::string suitNames[] = {
        "club", "diamond", "heart", "spade"
    };
    const int index = suit;
    if (index < 0 || index >= 4) return "Unknown";
    return suitNames[index];
}
