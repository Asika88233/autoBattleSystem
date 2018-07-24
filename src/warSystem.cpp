#include"myRandom.h";
#include "warSystem.h"



warSystem::warSystem(soldier *groupA[],soldier *groupB[])//构造函数
{
     _pWarriorA=groupA;
     _pWarriorB=groupB;
}



warSystem::~warSystem(void)
{
   //析构函数
}

//战斗开始函数

void warSystem::startWar(void)

{
     int round=1;
     do
     {
         log.print("==第");
         log.print(round++);
         log.print("回合===\n");
         if (round%2==0)
              startRound(_pWarriorA,_pWarriorB);
         else
              startRound(_pWarriorB,_pWarriorA);
     }
     while(!groupDefeated(_pWarriorA)&&!groupDefeated(_pWarriorB));//当一方被击败退出战斗
}

//回合开始函数

void warSystem::startRound(soldier **groupAttack,soldier **groupDefend)
{
     int i;
     for (i=0;i<GROUP_SIZE;i++)
     {
         Sleep(ATTACK_INTERVAL);
         groupAttack[i]->makeDecision(groupDefend);
     }



     log.print("\t▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉\n");

     //输出防守方统计值

     for (i=0;i<GROUP_SIZE;i++)

     {

         log.print("\t");

         log.print(groupDefend[i]);

     }

     log.print("\t‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥‥\n");

     //输出攻击方统计值

     for (i=0;i<GROUP_SIZE;i++)

     {

         log.print("\t");

         log.print(groupAttack[i]);

     }

     log.print("\t▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉\n");



}


bool warSystem::groupDefeated(soldier **group)//判断Warrior组是否被击败函数

{
     bool defeated=true;    //假设已经被击败
     for (int i=0;i<GROUP_SIZE;i++)
     {
         if (group[i]->die()==false)
         {
              defeated=false;    //第i个Warrior没有死
              break;
         }
     }
      //全部被消灭
     if (defeated)
     {
         for (int i=0;i<GROUP_SIZE;i++)
         {
              log.print(group[i]->getName() + ",");
         }
         log.print("\b已经全部被消灭,游戏结束.\n");

     }
     return defeated;
}
