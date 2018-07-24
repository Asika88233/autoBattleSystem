#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "soldier.h"
using namespace std;
//战士类


class Warrior:public soldier
{
	public:
                   Warrior(string);//构造函数
	       virtual ~Warrior(void);//析构函数
                   void attack(soldier *);//攻击
	       void rest();//休息
	       void restAgain(); //休战
                   void haveDrug(); //吃药,吃药恢复体力
	       bool die();//死亡
	       virtual void makeDecision(soldier **);//决策,从一组对手中进行决策 每个角色的决策
                   bool enemyGroupDefeated(soldier **);//判断是否已经击败对方全组
	       virtual string getName();//获取姓名
                   virtual void setHP(int);//被杀伤生命点数
	       int getDrug();//获得药物
                   bool restComplete; //是否休息结束
                   virtual int getHP();
};

#endif // WARRIOR_H
