#include "master.h"

master::master(string _name):Wizard(_name)
{
	name = _name; //姓名
	drugNum = 5; //药品数
	maxHP = 200;//最大生命
	HP = 200; //生命
	maxSP = 200;//最大体力
	SP       = 200;        //体力
            maxMP    = 100;        //最大魔法值
            MP       = 100;        //魔法值
            damage   = 20;         //攻击力
            level    = 1;     //等级
            EXP      = 0;     //经验
            restComplete = true;//刚开战不是休息状态}
}

void master::masterAttack(soldier *enemy)
{
	log.print(this->getName());
	log.print("使用大师攻击"+enemy->getName());
	enemy->setHP(50);
	 if (this->MP-50>0)
              this->SP-=50;
         else
              this->SP = 0;
              if (this->SP-30>0)
              this->SP-=30;
         else
              this->SP = 0;
	   if (enemy->die())

         {
              log.print("," + enemy->getName() + " 被打死,提前退出战斗");
              log.print("\n");

              int num=enemy->getDrug();
              this->drugNum += num;

              log.print(this->getName() +" 获得" );
              log.print(num);
              log.print(" 瓶药水!");
         }

              log.print("\n");

                 if (this->SP-SP_DECREMENT>0)
              this->SP-=SP_DECREMENT;
         else
              this->SP = 0;
                 this->EXP+=EXP_INCREMENT;
        if ((this->EXP)/20+1>level)

         {     this->level += 1;
               this->maxHP+=MAXHP_INCREMENT;
               this->maxSP+=MAXSP_INCREMENT;
               this->maxMP+=MAXMP_INCREMENT;
               this->damage+=DAMAGE_INCREMENT;
         }
}
master::~master()
{
	//dtor
}

void master::makeDecision(soldier **enemyGroup)
{
     if (!this->die() && !this->enemyGroupDefeated(enemyGroup))//若自己没有死且对方全组没死光,本回合继续参战
     {
     	log.print(this->getName());//每回合开始恢复内力
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
                                       else if (1.0*(this->HP)/(this->maxHP) < REST_CONDITION) //生命低于最大值的/3,休息
                                        {
                                        	this->rest();
			    }
                                          else
			       {
			       	if(this->MP>50&&this->SP>30)
				{
					while(1)
                                                            {
				              int target = random.number(1,GROUP_SIZE)-1;
                                                                  if (!enemyGroup[target]->die())
                                                                       { this->masterAttack(enemyGroup[target]);//攻击
                                                                                              break;
					           }

				             }
				}
	                  if ((this->MP) >ATTACK_SIZE*25 /*内力>30%*/
		           &&(this->SP)>ATTACK_SIZE*15)/*体力>30%*/
		           {
		           	  this->wizard_attack(enemyGroup);//魔法攻击
		           }

                                                  else//没蓝了就普通攻击
				  {
				  	while(1)
                                                            {
				              int target = random.number(1,GROUP_SIZE)-1;
                                                                  if (!enemyGroup[target]->die())
                                                                       { this->attack(enemyGroup[target]);//攻击
                                                                                              break;
					           }

				             }


		                          }
			        }
}
}
}

int master::getHP()
{
	return this->HP;
}
