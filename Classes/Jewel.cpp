#include "Jewel.h"
#include "GameScene.h"

Jewel* Jewel::createByType(int type, int x, int y)
{
    auto jewel = new Jewel();
    
    if (jewel && jewel->init(type, x, y))
    {
        jewel->autorelease();
        return jewel;
    }
    else
    {
        CC_SAFE_DELETE(jewel);
        return nullptr;
    }
}

bool Jewel::init(int type, int x, int y)
{
    Sprite::init();
    
    m_type = type;
    m_x = x;
    m_y = y;
    m_isSwaping = false;
    m_isCrushing = false;
    
    //根据资源名初始化纹理，该资源应该在游戏主场景里加载完毕的
    char name[100] = {0};
    sprintf(name, "jewel%d.png", m_type);
    this->initWithTexture(TextureCache::getInstance()->getTextureForKey(name));
    
    this->setAnchorPoint(Vec2(0, 0)); //左下角为锚点
    
    return true;
}

void Jewel::crush()
{
    //加分
    GameScene::addBonus(1);
    
    //开始消除，消除状态为真，直到消除动作结束，将宝石移除渲染节点，并置消除状态为假
    m_isCrushing = true;
    auto action = FadeOut::create(0.2);
    auto call = CallFunc::create([this](){
        this->removeFromParent();
        m_isCrushing = false;
    });
    this->runAction(Sequence::create(action, call, nullptr));
}