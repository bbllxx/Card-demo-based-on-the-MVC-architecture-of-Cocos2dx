#include "CardManager.h"
#include "models/GameModel.h"
#include"models/CardModel.h"

int CardManager::check(int cardId)
{
	GameModel& gameModel = GameModel::getInstance();
	CardModel* card = gameModel.cardObjs[cardId];//��ȡ��Ӧ���ƶ���
	if ((*card).getInitPosition().y <= 580)
	{
		return 3;
	}
	else if (gameModel.undostack.empty()) return 0;
	else
	{
		CardModel* stackTop = gameModel.cardObjs[gameModel.undostack.top()];
		int numDistance = (*card).getFace() - (*stackTop).getFace();
		if (numDistance == 1 || numDistance == -1)
		{
			return ((*card).getInitPosition().x <= 540) ? 1 : 2;
		}
	}
	return 0;
}

int CardManager::checkAndMoveToStack(int cardId)
{
	int area = check(cardId);
	if (!area) CCLOG("NOT CHECK");
	if (!area) return 0;
	GameModel& gameModel = GameModel::getInstance();
	gameModel.popCardToArea(area);
	gameModel.addCardToArea(0, cardId);
	return area;
}
