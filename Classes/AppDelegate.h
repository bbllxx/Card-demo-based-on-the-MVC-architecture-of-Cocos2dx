
#pragma once

#include "cocos2d.h"

//ͨ���̳�Application����Ҫ��Ϸ��ͼ������������Ϸ���ڡ��ֱ��ʡ�FPS��
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    //Director��Scene��ʼ��
   
    virtual bool applicationDidFinishLaunching();

    //��̨����ʱ��Ⱦ����
  
    virtual void applicationDidEnterBackground();

    //����ǰ̨ǰ��������
    
    virtual void applicationWillEnterForeground();
};

