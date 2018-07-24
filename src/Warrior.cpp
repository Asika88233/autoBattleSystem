#include "Warrior.h"

Warrior::Warrior(string _name)
{
	name = _name; //����
	drugNum = 5; //ҩƷ��
	maxHP = 200;//�������
	HP = 100; //����
	maxSP = 100;//�������
	SP       = 100;        //����
            maxMP    = 0;        //���ħ��ֵ
            MP       = 0;        //ħ��ֵ
            damage   = 20;         //������
            level    = 1;     //�ȼ�
            EXP      = 0;     //����
            restComplete = true;//�տ�ս������Ϣ״̬}
}

Warrior::~Warrior()
{
	//��������
}
void Warrior::attack(soldier *enemy)
{
     log.print(" ����" + enemy->getName());
     if (random.number(1, LOSE_TARGET_RATE)==3)

     {
        cout<<this->name;
        log.print(" ��ƫ��\n");
     }

     else

     {
         log.print(" �ɹ�����,�����");
         log.print(this->damage);
         log.print("�������˺�");
         log.print("\n");

         enemy->setHP(this->damage);

          if (enemy->die())
               {
              log.print(", " + enemy->getName() + " ������,��ǰ�˳�ս��");
              log.print("\n");
              int num=enemy->getDrug();
              this->drugNum += num;
              log.print(this->getName() +" ���" );
              log.print(num);
              log.print(" ƿҩˮ!");
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

     log.print("��Ϣ\n");//��ʼ��Ϣ������Ϊ��Ϣһ�غϼ��ָ��������ԣ�����Ҫ�ȵ������غϲſ����ж�
     restComplete = false;//��ҿ�ʼ��Ϣ��������������Ϊδ��Ϣ���
     this->HP = maxHP;//�ָ�����
     this->SP = maxSP;//�ָ�����
     this->MP = maxMP;//�ָ�����
}

void Warrior::restAgain()//������Ϣ�����������غ�
{
     log.print(" ������Ϣ\n");
     restComplete = true; //������Ϣ
}

void Warrior::haveDrug()
{
     log.print(" ��ҩ\n");
     this->drugNum-=1;
      if (this->SP+SP_INCREMENT<maxHP)
      {
      	this->SP+=SP_INCREMENT;//��һƿҩˮ���ӵ�����ֵ�ǹ̶���
      }

                 else
	     {
                       this->SP=maxSP;
	     }

}

bool Warrior::die()
//�ж��Ƿ�����
{
     if (this->HP<=0)
     {
       this->HP = 0;//��������
       return true;
     }
     else
       return false;
}

string Warrior::getName()
{return "[" + this->name + "]";}//�Ӹ����Ŷ���

void Warrior::setHP(int losePoints)

{
      log.print(", �˺�����:");
      log.print(losePoints);
      this->HP -= losePoints;
}

int Warrior::getDrug()
{return this->drugNum;}

bool Warrior::enemyGroupDefeated(soldier **group)
//�жϵз��Ƿ�ȫ�����ȫ�𷵻��棬���вд淵�ؼ�
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
     if (!this->die() && !this->enemyGroupDefeated(enemyGroup))//���Լ�û�����ҶԷ�ȫ��û����,���غϼ�����ս
     {
        log.print(this->getName());
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

                      else if (1.0*(this->HP)/(this->maxHP) < REST_CONDITION||this->SP<SP_DECREMENT)
                                 //�����������ֵ��/3,��������С��һ�ι�������Ҫ����ֵ��ǿ����Ϣ
                                     {
                              	 this->rest();
		                 }
                      else
                                      while(1)
                                               {
		    int target = random.number(1,GROUP_SIZE)-1;
                            if (!enemyGroup[target]->die())

                                                     {
                            	this->attack(enemyGroup[target]);//����
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
