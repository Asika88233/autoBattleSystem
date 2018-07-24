#include "master.h"

master::master(string _name):Wizard(_name)
{
	name = _name; //����
	drugNum = 5; //ҩƷ��
	maxHP = 200;//�������
	HP = 200; //����
	maxSP = 200;//�������
	SP       = 200;        //����
            maxMP    = 100;        //���ħ��ֵ
            MP       = 100;        //ħ��ֵ
            damage   = 20;         //������
            level    = 1;     //�ȼ�
            EXP      = 0;     //����
            restComplete = true;//�տ�ս������Ϣ״̬}
}

void master::masterAttack(soldier *enemy)
{
	log.print(this->getName());
	log.print("ʹ�ô�ʦ����"+enemy->getName());
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
              log.print("," + enemy->getName() + " ������,��ǰ�˳�ս��");
              log.print("\n");

              int num=enemy->getDrug();
              this->drugNum += num;

              log.print(this->getName() +" ���" );
              log.print(num);
              log.print(" ƿҩˮ!");
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
     if (!this->die() && !this->enemyGroupDefeated(enemyGroup))//���Լ�û�����ҶԷ�ȫ��û����,���غϼ�����ս
     {
     	log.print(this->getName());//ÿ�غϿ�ʼ�ָ�����
                 this->MP += MP_ROUND_RECOVER * (this->maxMP);
                      if ((this->MP)>(this->maxMP))
	          {
	          	this->MP = this->maxMP;
	          }
                          if (!restComplete)//���ϻغ�rest,���غϼ�����Ϣ
                                     {
			  this->restAgain();
			 }
                          else
		      {
                               	if (1.0*(this->SP)/(this->maxSP) < HAVE_DRUG_CONDITION && this->drugNum>0)
		        {
			this->haveDrug();
		        }
                                       else if (1.0*(this->HP)/(this->maxHP) < REST_CONDITION) //�����������ֵ��/3,��Ϣ
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
                                                                       { this->masterAttack(enemyGroup[target]);//����
                                                                                              break;
					           }

				             }
				}
	                  if ((this->MP) >ATTACK_SIZE*25 /*����>30%*/
		           &&(this->SP)>ATTACK_SIZE*15)/*����>30%*/
		           {
		           	  this->wizard_attack(enemyGroup);//ħ������
		           }

                                                  else//û���˾���ͨ����
				  {
				  	while(1)
                                                            {
				              int target = random.number(1,GROUP_SIZE)-1;
                                                                  if (!enemyGroup[target]->die())
                                                                       { this->attack(enemyGroup[target]);//����
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
