#ifndef JEWELSJewelsGrid_H
#define JEWELSJewelsGrid_H

#include "cocos2d.h"
#include <vector>

USING_NS_CC;
using namespace std;

#define GRID_WIDTH 40 //一个格子像素为40
#define MOVE_SPEED 0.2 //宝石移动速度
#define FIRST_JEWEL_ID 1 //第一个宝石的ID，宝石ID默认依次递增的
#define LAST_JEWEL_ID 7 //最后一个宝石的ID

class Jewel;

//布局类，包含了宝石在布局内的逻辑
//该网格布局坐标以左下角为原点，x左y上为正方向
class JewelsGrid : public Node
{
public:
    static JewelsGrid* create(int row, int col); //根据行跟列创建布局
    bool init(int row, int col);
    
    void updateMap(); //更新宝石阵列
    bool isDeadMap(); //判断当前布局是否死图（无论如何也不能消除）
    
private:
    //关于创建宝石的方法
    Jewel* createAJewel(int x, int y); //根据布局坐标创建一个宝石
    bool isJewelLegal(Jewel* jewel, int x, int y); //判断创建的宝石是否不会三消（即合法）
    void setJewelPixPos(Jewel* jewel, float x, float y); //设置其游戏实际像素位置。网格坐标轴以左下角为原点，x右y上为正轴
    
    //关于操作宝石的方法
    void swapJewels(Jewel *jewelA, Jewel *jewelB); //交换两个宝石
    void swapJewelToNewPos(Jewel* jewel); //移动到新位置
    
    void refreshJewelsGrid(); //刷新消除后的宝石阵列
    void refreshJewelsToNewPos(int col); //刷新一列宝石
    
private:
    //事件响应部分
    bool onTouchBegan(Touch*, Event*);
    void onTouchMoved(Touch*, Event*);
    
private:
    //游戏逻辑部分
    bool canCrush(); //判断当前状态的宝石阵列是否能消除
    void goCrush(); //开始crush
    
    //捕捉函数，捕捉消除步骤是否完成，然后控制消除流程
    void onJewelsSwaping(float dt);
    void onJewelsSwapingBack(float dt);
    void onJewelsCrushing(float dt);
    void onJewelsRefreshing(float dt);
    
public:
    int getRow() { return m_row; }
    int getCol() { return m_col; }
    
private:
    int m_row; //行数
    int m_col; //列数
    
    Jewel* m_jewelSelected; //当前选择的宝石
    Jewel* m_jewelSwapped; //欲交换的宝石
    
    vector<vector<Jewel*>> m_JewelsBox; //存放宝石对象的容器，通过坐标索引宝石
    Vector<Jewel*> m_crushJewelBox; //准备消除的宝石容器
    Vector<Jewel*> m_newJewelBox; //准备加入布局的宝石的容器
};

#endif

