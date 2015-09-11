#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "cocos2d.h"

USING_NS_CC;

class LoadingScene : public Layer
{
public:
    static Scene* createScene();
    CREATE_FUNC(LoadingScene);
    bool init();
    
private:
    void onTextureLoading(float dt); //检测纹理加载是否完毕
    
    int m_texture_num; //当前加载的纹理数
};

#endif

