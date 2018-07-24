#include "Warrior.h"

Warrior::Warrior(string _name)
{
	name = _name; //姓名
	drugNum = 5; //药品数
	maxHP = 200;//最大生命
	HP = 100; //生命
	maxSP = 100;//最大体力
	SP       = 100;        //体力
            maxMP    = 0;        //最大魔法值
            MP       = 0;        //魔法值
            damage   = 20;         //攻击力
            level    = 1;     //等级
            EXP      = 0;     //经验
            restComplete = true;//刚开战不是休息状态}
}

Warrior::~Warrior()
{
	//析构函数
}
void Warrior::attack(soldier *enemy)
{
     log.print(" 攻击" + enemy->getName());
     if (random.number(1, LOSE_TARGET_RATE)==3)

     {
        cout<<this->name;
        log.print(" 打偏了\n");
     }

     else

     {
         log.print(" 成功命中,造成了");
         log.print(this->damage);
         log.print("点物理伤害");
         log.print("\n");

         enemy->setHP(this->damage);

          if (enemy->die())
               {
              log.print(", " + enemy->getName() + " 被打死,提前退出战斗");
              log.print("\n");
              int num=enemy->getDrug();
              this->drugNum += num;
              log.print(this->getName() +" 获得" );
              log.print(num);
              log.print(" 瓶药水!");
                    }
              log.print("\n");

              if (this->SP-SP_DECREMENT>0)
	          {
	       this->SP-=SP_DECREMENT;
	               }
              else
                   {
                  this->SP = 0;
	            }
             this->EXP+=EXP_INCREMENT;
                  if ((this->EXP)/20+1>level)
                  {
	         this->level += 1;
                     this->maxHP+=MAXHP_INCREMENT;
                     this->maxSP+=MAXSP_INCREMENT;
                     this->maxMP+=MAXMP_INCREMENT;
                     this->damage+=DAMAGE_INCREMENT;
	             }
     }
}
void Warrior::rest()
{

     log.print("休息\n");//开始休息，机制为休息一回合即恢复所有属性，但是要等到第三回合才可以行动
     restComplete = false;//玩家开始休息，将该属性设置为未休息完成
     this->HP = maxHP;//恢复生命
     this->SP = maxSP;//恢复体力
     this->MP = maxMP;//恢复内力
}

void Warrior::restAgain()//继续休息，持续两个回合
{
     log.print(" 继续休息\n");
     restComplete = true; //结束休息
}

void Warrior::haveDrug()
{
     log.print(" 吃药\n");
     this->drugNum-=1;
      if (this->SP+SP_INCREMENT<maxHP)
      {
      	this->SP+=SP_INCREMENT;//吃一瓶药水所加的体力值是固定的
      }

                 else
	     {
                       this->SP=maxSP;
	     }

}

bool Warrior::die()
//判断是否死亡
{
     if (this->HP<=0)
     {
       this->HP = 0;//生命清零
       return true;
     }
     else
       return false;
}

string Warrior::getName()
{return "[" + this->name + "]";}//加个括号而已

void Warrior::setHP(int losePoints)

{
      log.print(", 伤害点数:");
      log.print(losePoints);
      this->HP -= losePoints;
}

int Warrior::getDrug()
{return this->drugNum;}

bool Warrior::enemyGroupDefeated(soldier **group)
//判断敌方是否全灭，如果全灭返回真，仍有残存返回假
{
     bool defeated=true;
     for (int i=0;i<GROUP_SIZE;i++)

     {
         if (group[i]->die()==false)
         {
              defeated=false;
              break;
              }
   }
           return defeated;
}

void Warrior::makeDecision(soldier **enemyGroup)
{
     if (!this->die() && !this->enemyGroupDefeated(enemyGroup))//若自己没有死且对方全组没死光,本回合继续参战
     {
        log.print(this->getName());
        this->MP += MP_ROUND_RECOVER * (this->maxMP);
         if ((this->MP)>(this->maxMP))
         {
         	this->MP = this->maxMP;
         }
         if (!restComplete)//若上回合rest,本回合继续休息
                      {
         	this->restAgain();
                      }
         else
         {
         	if (1.0*(this->SP)/(this->maxSP) < HAVE_DRUG_CONDITION && this->drugNum>0)
                           {
                	this->haveDrug();
                	   }

                      else if (1.0*(this->HP)/(this->maxHP) < REST_CONDITION||this->SP<SP_DECREMENT)
                                 //生命低于最大值的/3,或者体力小于一次攻击所需要的数值，强制休息
                                     {
                              	 this->rest();
		                 }
                      else
                                      while(1)
                                               {
		    int target = random.number(1,GROUP_SIZE)-1;
                            if (!enemyGroup[target]->die())

                                                     {
                            	this->attack(enemyGroup[target]);//攻击
                                          break;
		                              }
				}
	}
     }
}
int Warrior::getHP()
{
	return this->maxHP;
}
