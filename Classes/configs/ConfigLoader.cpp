#include "ConfigLoader.h"
#include "json/filereadstream.h"
#include "cocos2d.h"

USING_NS_CC;

rapidjson::Document* ConfigLoader::loadCardModelFromFile(const std::string& filename)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filename);
    // ���ļ�
    FILE* fp = fopen(fullPath.c_str(), "r");
    if (!fp) {
        // �ļ���ʧ��
        CCLOG("FILE Field!!");
        return nullptr;
    }

    // ����һ���ļ���ȡ��
    char buffer[65536];  // ʹ��һ���㹻��Ļ�����
    rapidjson::FileReadStream fs(fp, buffer, sizeof(buffer));

    // ���� Document ������ JSON ����
    rapidjson::Document* document=new rapidjson::Document();
    document->ParseStream(fs);

    // �ر��ļ�
    fclose(fp);

    if (document->HasParseError()) {
        // ��������������ؿ�ָ��
        CCLOG("document->HasParseError() ERROR!!");
        delete document;
        return nullptr;
    }
    return document;
}

