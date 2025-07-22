
#pragma once

#include "cocos2d.h"

//通过继承Application的主要游戏视图，用来管理游戏窗口、分辨率、FPS等
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    //Director与Scene初始化
   
    virtual bool applicationDidFinishLaunching();

    //后台工作时渲染设置
  
    virtual void applicationDidEnterBackground();

    //进入前台前动画设置
    
    virtual void applicationWillEnterForeground();
};

