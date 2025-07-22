#pragma once
/*
* 实现
*/
class CardManager
{
public:
	//检查是否满足进入手牌stack牌区
	//参数 cardId ：待检查卡牌ID
	int check(int cardId);

	//检查是否满足进入手牌stack牌区并加入对应区域
	//参数 cardId ：待检查与待添加的卡牌ID
	int checkAndMoveToStack(int cardId);

};

