#include "BackGroundView.h"

bool BackGroundView::init()
{
	if (!Layer::init())
	{
		return false;
	}

    // 创建 Playfield 区域（棕色）
    auto playfield = LayerColor::create(Color4B(139, 69, 19, 255), 1080, 1500); // 棕色 (RGB: 139, 69, 19)
    playfield->setPosition(Vec2(0, 580)); // 注意：从下往上排，底部是 Stack
    this->addChild(playfield, 0); // 层级 0

    // 创建 Stack 区域（紫色）
    auto stack = LayerColor::create(Color4B(128, 0, 128, 255), 1080, 580); // 紫色 (RGB: 128, 0, 128)
    stack->setPosition(Vec2(0, 0)); // 位于屏幕底部
    this->addChild(stack, 0); // 层级 0

    return true;
}
