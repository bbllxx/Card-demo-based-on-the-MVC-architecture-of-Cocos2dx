#include "ClickService.h"
#include "managers/CardManager.h"
#include "models/GameModel.h"
#include "models/CardModel.h"
#include "views/CardView.h"
#include "configs/ConfigLoader.h"

bool ClickService::goBackClick()
{
    GameModel& gameModel = GameModel::getInstance();

    if (gameModel.undostack.empty()) return false;//�жϲ�������ջ�Ƿ�Ϊ��

    //��ȡ������ͼƬ����ָ��
    int cardId = gameModel.undostack.top();
    CardView* cardView = gameModel.cardViews[cardId];
    CardModel* cardModel = gameModel.cardObjs[cardId];

    (*cardView).animationGoBack();//ִ�ж���
    (*cardView).setTouchActive(true);//�ָ�Layer��Ӧ
    gameModel.undostack.pop();//��ջ

    if ((*cardModel).getInitPosition().y <= 580)//�ж�����
    {
        //��ȡstack�ײ�Ԫ��
        if (!gameModel.stack.empty())
        {
            int stackBackId = gameModel.stack[gameModel.stack.size() - 1];
            (*gameModel.cardViews[stackBackId]).setTouchActive(false); //�ر�������Ӧ
        }
        gameModel.addCardToArea(3, cardId);
    }
    else
    {
        int area = ((*cardModel).getInitPosition().x <= 540) ? 1 : 2;//�ж�����
        if (area == 1)
        {
            //��ȡplayfield_1�ײ�Ԫ��
            if (!gameModel.playfield_1.empty())
            {
                int playBackId = gameModel.playfield_1[gameModel.playfield_1.size() - 1];
                (*gameModel.cardViews[playBackId]).setTouchActive(false);//�ر�������Ӧ
            }
        }
        else
        {
            //��ȡplayfield_2�ײ�Ԫ��
            if (!gameModel.playfield_2.empty())
            {
                int playBackId = gameModel.playfield_2[gameModel.playfield_2.size() - 1];
                (*gameModel.cardViews[playBackId]).setTouchActive(false);//�ر�������Ӧ
            }
        }
        gameModel.addCardToArea(area, cardId);//��ӿ��Ƶ���������
    }

    return true;
}

void ClickService::cardClick(int cardId)
{
    CardManager cardManager;

    //�ж��Ƿ�������������cardŲ����Ӧ����
    int area = cardManager.checkAndMoveToStack(cardId);
    if (!area) CCLOG("CAN NOT");
    if (area)
    {
        //��ȡcardViewָ��
        GameModel& gameModel = GameModel::getInstance();
        CardView* cardView = gameModel.cardViews[cardId];

        (*cardView).animationToStack();//ִ�ж���
        (*cardView).setLocalZOrder(gameModel.undostack.size() + 2);//���ò㼶
        (*cardView).setTouchActive(false);//�ر���Ӧ

        if (area == 1&& !gameModel.playfield_1.empty())
        {
            //��ȡplayfield_1�ײ�Ԫ��
            int playBackId = gameModel.playfield_1[gameModel.playfield_1.size() - 1];
            (*gameModel.cardViews[playBackId]).setTouchActive(true);//����������Ӧ
        }
        else if(area == 2 && !gameModel.playfield_2.empty())
        {
            //��ȡplayfield_2�ײ�Ԫ��
            int playBackId = gameModel.playfield_2[gameModel.playfield_2.size() - 1];
            (*gameModel.cardViews[playBackId]).setTouchActive(true);//����������Ӧ
        }
        else if(!gameModel.stack.empty())
        {
            //��ȡstack�ײ�Ԫ��
            int stackBackId = gameModel.stack[gameModel.stack.size() - 1];
            (*gameModel.cardViews[stackBackId]).setTouchActive(true); //����������Ӧ
        }
    }
}

void ClickService::deserializeCard()
{
    //��ȡ�ļ�
    rapidjson::Document* doc = ConfigLoader::loadCardModelFromFile("configs/InitGameConfig.json");
    if (!doc) CCLOG("InitGameConfig.json error ");

    GameModel& gameModel = GameModel::getInstance();

    //// �����л� Playfield �е�ÿ����Ƭ
    if (doc->HasMember("Playfield") && (*doc)["Playfield"].IsArray()) {
        const rapidjson::Value& playfield = (*doc)["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfield.Size(); i++) {
            CardModel* card = CardModel::deserialize(playfield[i]);
            gameModel.addCardToObjs(card);
        }
    }

    // �����л� Stack �е�ÿ����Ƭ
    if (doc->HasMember("Stack") && (*doc)["Stack"].IsArray()) {
        const rapidjson::Value& stack = (*doc)["Stack"];
        for (rapidjson::SizeType i = 0; i < stack.Size(); i++) {
            CardModel* card = CardModel::deserialize(stack[i]);
            gameModel.addCardToObjs(card);
        }
    }

    //�������п�Ƭ��Ϣ����������ͼ
    for (auto i = 0; i < gameModel.cardObjs.size(); i++)
    {
        CardModel* cardModel = gameModel.cardObjs[i];
        CardView* cardView = CardView::create(
            (*cardModel).getFace(),
            (*cardModel).getSuit(), 
            (*cardModel).getInitPosition()
        );
        gameModel.cardViews.push_back(cardView);
        (*cardView).setTouchActive(false);//Ĭ�Ϲر�Layer��Ӧ
    }

    //��ȡstack�ײ�Ԫ��
    int stackBackId = gameModel.stack[gameModel.stack.size() - 1];
    (*gameModel.cardViews[stackBackId]).setTouchActive(true); //����������Ӧ
    //��ȡplayfield_1�ײ�Ԫ��
    int playBackId = gameModel.playfield_1[gameModel.playfield_1.size() - 1];
    (*gameModel.cardViews[playBackId]).setTouchActive(true);//����������Ӧ
    //��ȡplayfield_2�ײ�Ԫ��
     playBackId = gameModel.playfield_2[gameModel.playfield_2.size() - 1];
    (*gameModel.cardViews[playBackId]).setTouchActive(true);//����������Ӧ
}
