#include "Wizard.h"

Wizard::Wizard(string _name):Warrior(_name)
{
	name = _name; //姓名
	drugNum = 5; //药品数
	maxHP = 100;//最大生命
	HP = 100; //生命
	maxSP = 100;//最大体力
	SP       = 100;        //体力
            maxMP    = 100;        //最大魔法值
            MP       = 100;        //魔法值
            damage   = 20;         //攻击力
            level    = 1;     //等级
            EXP      = 0;     //经验
            restComplete = true;//刚开战不是休息状态}
}

Wizard::~Wizard()
{
	//dtor
}
void Wizard::wizard_attack(soldier **enemyGroup)

{    //攻击人数

          for(int i=0;i<ATTACK_SIZE;i++)

    {         int target = random.number(1,GROUP_SIZE)-1;

         if (!enemyGroup[target]->die())

         {

              this->wizardStroke(enemyGroup[target]);//攻击

         }
     }
}
void Wizard::wizardStroke(soldier *enemy)

{
     log.print("\t实施魔法攻击" + enemy->getName() + " 受到攻击");
     enemy->setHP(this->damage);


     if (enemy->die()) //判断对手是否已死

{
	log.print(", " + enemy->getName() + " 被打死,提前退出战斗\n");
            int num=enemy->getDrug();
	this->drugNum += num;
            log.print(this->getName() +" 获得" );
            log.print(num);
            log.print(" 瓶药水!");     }
            log.print("\n");
            if ((this->SP)-2*SP_DECREMENT>0)//体力减少双倍
                {
         	          this->SP-=(2*SP_DECREMENT);
	    }
            else
                  {
     	       this->SP = 0;
                  }
     this->EXP+=EXP_INCREMENT;//EXP增加
     if ((this->EXP)/20+1>level)//当EXP累计增加了,级别提升
     {
         this->level += 1;//level提升
         this->maxHP+=MAXHP_INCREMENT; //HP,SP,MP增加
         this->maxSP+=MAXSP_INCREMENT;
         this->maxMP+=MAXMP_INCREMENT;
         this->damage+=DAMAGE_INCREMENT; //damage增加
         }
       this->MP -=25;
     if(this->MP<0)//内力全部消耗殆尽
     {
     	this->MP=0;
     }
        this->SP-=10;
        if(this->SP<0)//体力全部消耗殆尽
        {
         this->SP=0;
         }
}

void Wizard::makeDecision(soldier **enemyGroup)
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
int Wizard::getHP()
{
	return this->maxHP;
}

