#include "CardView.h"
#include"utils/GetCardUtil.h"

CardView* CardView::create(CardFaceType face, CardSuitType suit, Vec2 initPosition)
{
    CardView* layer = new CardView();
    if (layer && layer->init(face, suit, initPosition)) {
        layer->autorelease(); // Cocos2d-x 自动内存管理
        return layer;
    }
    delete layer;
    return nullptr;
}

bool CardView::init(CardFaceType face, CardSuitType suit, Vec2 initPosition) {
    if (!Layer::init()) return false;

    //初始化初始位置
    _initPosition = initPosition;
    
    //挑选颜色
    std::string colorStr = (suit == CST_DIAMONDS || suit == CST_HEARTS) ? "red" : "black";

    // 加载底图
    auto bg = Sprite::create("card_general.png");//182*282
    this->addChild(bg);

    // 小数字
    std::string faceStr = getFaceString(face); // A, 2, ..., K
    auto numberSprite = Sprite::create("small_" + colorStr + "_" + faceStr + ".png");//
    numberSprite->setPosition(Vec2(-50, 95));
    this->addChild(numberSprite);

    // 花色图标
    std::string suitStr = getSuitString(suit); // spade, heart, etc.
    auto suitSprite = Sprite::create(suitStr + ".png");
    suitSprite->setPosition(Vec2(50, 95));
    this->addChild(suitSprite);
    
    // 中间大数字
    auto centerSprite = Sprite::create("big_" + colorStr + "_" + faceStr + ".png");
    centerSprite->setPosition(Vec2(0, -25));
    this->addChild(centerSprite);

    // 创建监听器
    _touchListener = EventListenerTouchOneByOne::create();
    _touchListener->onTouchBegan = [=](Touch* t, Event* e) {
        //设置响应区域
        Vec2 locationInNode = this->convertToNodeSpace(t->getLocation());
        Size size = bg->getContentSize();
        Rect rect = Rect(-size.width / 2, -size.height / 2, size.width, size.height);

        if (rect.containsPoint(locationInNode)) {
            if (onCardClickCallBack) {
                onCardClickCallBack(_cardId);
            }
            return true;
        }
        return false;  // 触摸点不在节点区域内，不拦截
        };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

    
    //放置在初始位置
    this->setPosition(initPosition);

    return true;
}

Vec2 CardView::getInitPosition(){ return Vec2(); }

int CardView::getCardId() { return _cardId; }

void CardView::setCardId(int id) { _cardId = id; }

void CardView::setTouchActive(bool active)
{
    if (_touchListener) {
        _touchListener->setEnabled(active);
    }
}

void CardView::animationToStack()
{
    auto moveTo = MoveTo::create(0.6f, Vec2(750,350));
    runAction(moveTo);
}

void CardView::animationGoBack()
{
    //移动到初始位置
    auto moveTo = MoveTo::create(0.6f, _initPosition);
    auto setZOrder = CallFunc::create([=]() {
        this->setLocalZOrder(_initZOrder);  // 动画执行完再设置层级
        });
    //动画序列
    auto seq = Sequence::create(moveTo, setZOrder, nullptr);

    runAction(seq);

}

void CardView::setInitZOrder(int zOrder)
{
    _initZOrder = zOrder;
}

int CardView::getInitZOrder()
{
    return _initZOrder;
}



