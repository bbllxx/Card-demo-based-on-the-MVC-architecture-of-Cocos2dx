#include "CardView.h"
#include"utils/GetCardUtil.h"

CardView* CardView::create(CardFaceType face, CardSuitType suit, Vec2 initPosition)
{
    CardView* layer = new CardView();
    if (layer && layer->init(face, suit, initPosition)) {
        layer->autorelease(); // Cocos2d-x �Զ��ڴ����
        return layer;
    }
    delete layer;
    return nullptr;
}

bool CardView::init(CardFaceType face, CardSuitType suit, Vec2 initPosition) {
    if (!Layer::init()) return false;

    //��ʼ����ʼλ��
    _initPosition = initPosition;
    
    //��ѡ��ɫ
    std::string colorStr = (suit == CST_DIAMONDS || suit == CST_HEARTS) ? "red" : "black";

    // ���ص�ͼ
    auto bg = Sprite::create("card_general.png");//182*282
    this->addChild(bg);

    // С����
    std::string faceStr = getFaceString(face); // A, 2, ..., K
    auto numberSprite = Sprite::create("small_" + colorStr + "_" + faceStr + ".png");//
    numberSprite->setPosition(Vec2(-50, 95));
    this->addChild(numberSprite);

    // ��ɫͼ��
    std::string suitStr = getSuitString(suit); // spade, heart, etc.
    auto suitSprite = Sprite::create(suitStr + ".png");
    suitSprite->setPosition(Vec2(50, 95));
    this->addChild(suitSprite);
    
    // �м������
    auto centerSprite = Sprite::create("big_" + colorStr + "_" + faceStr + ".png");
    centerSprite->setPosition(Vec2(0, -25));
    this->addChild(centerSprite);

    // ����������
    _touchListener = EventListenerTouchOneByOne::create();
    _touchListener->onTouchBegan = [=](Touch* t, Event* e) {
        //������Ӧ����
        Vec2 locationInNode = this->convertToNodeSpace(t->getLocation());
        Size size = bg->getContentSize();
        Rect rect = Rect(-size.width / 2, -size.height / 2, size.width, size.height);

        if (rect.containsPoint(locationInNode)) {
            if (onCardClickCallBack) {
                onCardClickCallBack(_cardId);
            }
            return true;
        }
        return false;  // �����㲻�ڽڵ������ڣ�������
        };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

    
    //�����ڳ�ʼλ��
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
    //�ƶ�����ʼλ��
    auto moveTo = MoveTo::create(0.6f, _initPosition);
    auto setZOrder = CallFunc::create([=]() {
        this->setLocalZOrder(_initZOrder);  // ����ִ���������ò㼶
        });
    //��������
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



