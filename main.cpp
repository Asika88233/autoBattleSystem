#include<iostream>
#include<string>
#include"myRandom.h";
#include "master.h";
#include "warSystem.h";
#include "Log.h";
#include "stdlib.h";
#include "Warrior.h"
#include "Wizard.h"
using namespace std;
int main()
{

system("color 3E");

using namespace std;

cout<<"◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n"

     <<"◆                                     简单回合制战斗系统                   ◆\n"

     <<"◆                               ——2016级计科系软件4班第11小组制作           ◆\n"

     <<"◆制作成员：张奕凡                                                           ◆\n"

     <<"◆使用说明：   游戏开始时，为让你输入军团每个组员的姓名，然后战斗为自动进行。                   ◆\n"
       <<"◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n";

    char s;

cout<<"你准备好了吗？（Y/N）\n\n\n"

<<"Y: 是的，准备好了，战斗开始吧            N：我还没有准备好，先退出战斗吧\n\n\n"

<<"现在请输入你的命令吧！\n\n";

cin>>s;

system("color E");

int i;

if(s=='y'||s=='Y')

{

cout<<"\n\n\n\n温馨提示：\n     本战斗系统个人为一组，共A、B两组，是不是等不及了喃？那下面开始吧！\n";

string a[3],b[3];

getline(cin,a[0]);

cout<<"请输入A组第1个人的姓名\n";

getline(cin,a[0]);

for(i=1;i<3;i++)

{

    cout<<"请输入A组第"<<i+1<<"个人的姓名\n";

    getline(cin,a[i]);

   }

cout<<"请输入B组第1个人的姓名\n";

   getline(cin,b[0]);

for(i=1;i<3;i++)

   {

    cout<<"请输入B组第"<<i+1<<"个人的姓名\n";

     getline(cin,b[i]);

   }

    system("color 2E");
     master  a1(a[0]);
     Wizard  a2(a[1]);
     Warrior  a3(a[2]);//第一组

     master   b1(b[0]);
     Wizard   b2(b[1]);
     Warrior  b3(b[2]);


     soldier *groupA[GROUP_SIZE]={&a1,&a2,&a3};
     //第二组
     soldier *groupB[GROUP_SIZE]={&b1,&b2,&b3};
         //将两组放入WarSystem
     warSystem war(groupA,groupB);
     war.startWar();
}

else if(s=='N'||s=='n')

    cout<<"你已经飞快的退出游戏了\n";

else

   cout<<"输入错误，请浏览说明哦！";

     system("color 1E");
     return 0;
}
