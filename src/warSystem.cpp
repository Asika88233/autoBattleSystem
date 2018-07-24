#include"myRandom.h";
#include "warSystem.h"



warSystem::warSystem(soldier *groupA[],soldier *groupB[])//���캯��
{
     _pWarriorA=groupA;
     _pWarriorB=groupB;
}



warSystem::~warSystem(void)
{
   //��������
}

//ս����ʼ����

void warSystem::startWar(void)

{
     int round=1;
     do
     {
         log.print("==��");
         log.print(round++);
         log.print("�غ�===\n");
         if (round%2==0)
              startRound(_pWarriorA,_pWarriorB);
         else
              startRound(_pWarriorB,_pWarriorA);
     }
     while(!groupDefeated(_pWarriorA)&&!groupDefeated(_pWarriorB));//��һ���������˳�ս��
}

//�غϿ�ʼ����

void warSystem::startRound(soldier **groupAttack,soldier **groupDefend)
{
     int i;
     for (i=0;i<GROUP_SIZE;i++)
     {
         Sleep(ATTACK_INTERVAL);
         groupAttack[i]->makeDecision(groupDefend);
     }



     log.print("\t����������������������������������������������������������������������\n");

     //������ط�ͳ��ֵ

     for (i=0;i<GROUP_SIZE;i++)

     {

         log.print("\t");

         log.print(groupDefend[i]);

     }

     log.print("\t�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E\n");

     //���������ͳ��ֵ

     for (i=0;i<GROUP_SIZE;i++)

     {

         log.print("\t");

         log.print(groupAttack[i]);

     }

     log.print("\t����������������������������������������������������������������������\n");



}


bool warSystem::groupDefeated(soldier **group)//�ж�Warrior���Ƿ񱻻��ܺ���

{
     bool defeated=true;    //�����Ѿ�������
     for (int i=0;i<GROUP_SIZE;i++)
     {
         if (group[i]->die()==false)
         {
              defeated=false;    //��i��Warriorû����
              break;
         }
     }
      //ȫ��������
     if (defeated)
     {
         for (int i=0;i<GROUP_SIZE;i++)
         {
              log.print(group[i]->getName() + ",");
         }
         log.print("\b�Ѿ�ȫ��������,��Ϸ����.\n");

     }
     return defeated;
}
