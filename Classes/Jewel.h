#ifndef JEWEL_H
#define JEWEL_H

#include "cocos2d.h"

USING_NS_CC;

class Jewel : public Sprite
{
public:
    static Jewel* createByType(int type, int x, int y); //根据宝石类型以及坐标创建宝石
    bool init(int type, int x, int y);
    
public:
    int getType() { return m_type; }
    int getX() { return m_x; }
    int getY() { return m_y; }
    
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    
    bool isSwaping() { return m_isSwaping; }
    bool isCrushing() { return m_isCrushing; }
    
    void setSwapingState(bool state) { m_isSwaping = state; }
    
    void crush(); //消除
    
private:
    //类型
    int m_type;
    
    //坐标
    int m_x;
    int m_y;
    
    bool m_isSwaping; //是否正在交换
    bool m_isCrushing; //是否正在消除
};

#endif
