#pragma once
#include<string>
#include<json/document.h>
/*
* JSON�ļ���ȡ�߼�
*/
class ConfigLoader
{
public :
	//����JSON
	//����filename���������ļ�·��
	//����ֵrapidjson::Document*
	static rapidjson::Document* loadCardModelFromFile(const std::string& filename);
};

