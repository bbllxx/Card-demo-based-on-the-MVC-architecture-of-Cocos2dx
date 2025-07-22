#pragma once
/*
* 实现相关业务逻辑（回退按钮响应逻辑、反序列读取并创建关卡、卡牌信息响应逻辑）
*/
class ClickService
{
public:
	//回退按钮响应逻辑
	static bool goBackClick();

	//卡牌信息响应逻辑
	static void cardClick(int cardId);

	//反序列读取并创建关卡
	static void deserializeCard();

};

