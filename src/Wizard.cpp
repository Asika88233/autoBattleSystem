#include "Wizard.h"

Wizard::Wizard(string _name):Warrior(_name)
{
	name = _name; //����
	drugNum = 5; //ҩƷ��
	maxHP = 100;//�������
	HP = 100; //����
	maxSP = 100;//�������
	SP       = 100;        //����
            maxMP    = 100;        //���ħ��ֵ
            MP       = 100;        //ħ��ֵ
            damage   = 20;         //������
            level    = 1;     //�ȼ�
            EXP      = 0;     //����
            restComplete = true;//�տ�ս������Ϣ״̬}
}

Wizard::~Wizard()
{
	//dtor
}
void Wizard::wizard_attack(soldier **enemyGroup)

{    //��������

          for(int i=0;i<ATTACK_SIZE;i++)

    {         int target = random.number(1,GROUP_SIZE)-1;

         if (!enemyGroup[target]->die())

         {

              this->wizardStroke(enemyGroup[target]);//����

         }
     }
}
void Wizard::wizardStroke(soldier *enemy)

{
     log.print("\tʵʩħ������" + enemy->getName() + " �ܵ�����");
     enemy->setHP(this->damage);


     if (enemy->die()) //�ж϶����Ƿ�����

{
	log.print(", " + enemy->getName() + " ������,��ǰ�˳�ս��\n");
            int num=enemy->getDrug();
	this->drugNum += num;
            log.print(this->getName() +" ���" );
            log.print(num);
            log.print(" ƿҩˮ!");     }
            log.print("\n");
            if ((this->SP)-2*SP_DECREMENT>0)//��������˫��
                {
         	          this->SP-=(2*SP_DECREMENT);
	    }
            else
                  {
     	       this->SP = 0;
                  }
     this->EXP+=EXP_INCREMENT;//EXP����
     if ((this->EXP)/20+1>level)//��EXP�ۼ�������,��������
     {
         this->level += 1;//level����
         this->maxHP+=MAXHP_INCREMENT; //HP,SP,MP����
         this->maxSP+=MAXSP_INCREMENT;
         this->maxMP+=MAXMP_INCREMENT;
         this->damage+=DAMAGE_INCREMENT; //damage����
         }
       this->MP -=25;
     if(this->MP<0)//����ȫ�����Ĵ���
     {
     	this->MP=0;
     }
        this->SP-=10;
        if(this->SP<0)//����ȫ�����Ĵ���
        {
         this->SP=0;
         }
}

void Wizard::makeDecision(soldier **enemyGroup)
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
int Wizard::getHP()
{
	return this->maxHP;
}

