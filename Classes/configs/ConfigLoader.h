#pragma once
#include<string>
#include<json/document.h>
/*
* JSON文件读取逻辑
*/
class ConfigLoader
{
public :
	//加载JSON
	//参数filename：待加载文件路径
	//返回值rapidjson::Document*
	static rapidjson::Document* loadCardModelFromFile(const std::string& filename);
};

