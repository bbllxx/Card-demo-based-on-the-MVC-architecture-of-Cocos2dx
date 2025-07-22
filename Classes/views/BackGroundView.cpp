#include "BackGroundView.h"

bool BackGroundView::init()
{
	if (!Layer::init())
	{
		return false;
	}

    // ���� Playfield ������ɫ��
    auto playfield = LayerColor::create(Color4B(139, 69, 19, 255), 1080, 1500); // ��ɫ (RGB: 139, 69, 19)
    playfield->setPosition(Vec2(0, 580)); // ע�⣺���������ţ��ײ��� Stack
    this->addChild(playfield, 0); // �㼶 0

    // ���� Stack ������ɫ��
    auto stack = LayerColor::create(Color4B(128, 0, 128, 255), 1080, 580); // ��ɫ (RGB: 128, 0, 128)
    stack->setPosition(Vec2(0, 0)); // λ����Ļ�ײ�
    this->addChild(stack, 0); // �㼶 0

    return true;
}
