#include "ConfigLoader.h"
#include "json/filereadstream.h"
#include "cocos2d.h"

USING_NS_CC;

rapidjson::Document* ConfigLoader::loadCardModelFromFile(const std::string& filename)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filename);
    // 打开文件
    FILE* fp = fopen(fullPath.c_str(), "r");
    if (!fp) {
        // 文件打开失败
        CCLOG("FILE Field!!");
        return nullptr;
    }

    // 创建一个文件读取流
    char buffer[65536];  // 使用一个足够大的缓冲区
    rapidjson::FileReadStream fs(fp, buffer, sizeof(buffer));

    // 创建 Document 并解析 JSON 数据
    rapidjson::Document* document=new rapidjson::Document();
    document->ParseStream(fs);

    // 关闭文件
    fclose(fp);

    if (document->HasParseError()) {
        // 如果解析出错，返回空指针
        CCLOG("document->HasParseError() ERROR!!");
        delete document;
        return nullptr;
    }
    return document;
}

