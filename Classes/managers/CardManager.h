#pragma once
/*
* ʵ��
*/
class CardManager
{
public:
	//����Ƿ������������stack����
	//���� cardId ������鿨��ID
	int check(int cardId);

	//����Ƿ������������stack�����������Ӧ����
	//���� cardId ������������ӵĿ���ID
	int checkAndMoveToStack(int cardId);

};

