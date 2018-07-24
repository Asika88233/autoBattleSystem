#ifndef SOLDIER_H
#define SOLDIER_H
//角色类，为抽象数据数据类型，不会为它创造数据类型
#include "Regulations.h"//规则常数
#include "MyRandom.h" //随机数类
#include "Log.h"       //日志类
#include <string>

using namespace std;
class soldier
{
	public:
		soldier();
		virtual ~soldier();
		virtual void attack(soldier *)=0;//纯虚函数，攻击；不给出实现方法，但是在继承的子类中应该给出相应的实现方法。
		virtual void rest(void)=0;     //纯虚函数,休息
		virtual void restAgain(void)=0;//纯虚函数,继续休息
		virtual void haveDrug(void)=0;//吃药，不是吸毒。同样是纯虚函数，恢复体力。
		virtual bool die(void)=0;  //纯虚函数,死亡
		virtual void makeDecision(soldier **)=0;//纯虚函数,决策,从一组对手中进行决策
		virtual string getName()=0;//获得姓名
                        virtual void setHP(int)=0;
                        virtual int getDrug()=0;
                        virtual int getHP()=0;
                        friend void Log::print(soldier *) const;
                        friend void Log::print(string message) const;
	            //友元函数,使得Log类能够访问soldier对象
	protected:
	           int maxHP;             //最大生命    health
                       int HP;                //当前生命
                       int maxSP;             //最大体力    strength
                       int SP;                //当前体力
                       int MP;                //只有法师有魔力资源，但是为了显示的统一性，在通用基类上同样设置mp属性
                       int maxMP;
                       int damage;            //攻击力
                       int EXP;           //经验
                       int level;             //等级
                       string name;       //姓名
	           int drugNum;       //药品数
	           myRandom random;   //随机数对象
	           Log log;           //日志对象


};

#endif // SOLDIER_H
