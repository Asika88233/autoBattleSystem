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

cout<<"������������������������������������������������������������������������������������������������������\n"

     <<"��                                     �򵥻غ���ս��ϵͳ                   ��\n"

     <<"��                               ����2016���ƿ�ϵ���4���11С������           ��\n"

     <<"��������Ա�����ȷ�                                                           ��\n"

     <<"��ʹ��˵����   ��Ϸ��ʼʱ��Ϊ�����������ÿ����Ա��������Ȼ��ս��Ϊ�Զ����С�                   ��\n"
       <<"������������������������������������������������������������������������������������������������������\n";

    char s;

cout<<"��׼�������𣿣�Y/N��\n\n\n"

<<"Y: �ǵģ�׼�����ˣ�ս����ʼ��            N���һ�û��׼���ã����˳�ս����\n\n\n"

<<"�����������������ɣ�\n\n";

cin>>s;

system("color E");

int i;

if(s=='y'||s=='Y')

{

cout<<"\n\n\n\n��ܰ��ʾ��\n     ��ս��ϵͳ����Ϊһ�飬��A��B���飬�ǲ��ǵȲ�����ૣ������濪ʼ�ɣ�\n";

string a[3],b[3];

getline(cin,a[0]);

cout<<"������A���1���˵�����\n";

getline(cin,a[0]);

for(i=1;i<3;i++)

{

    cout<<"������A���"<<i+1<<"���˵�����\n";

    getline(cin,a[i]);

   }

cout<<"������B���1���˵�����\n";

   getline(cin,b[0]);

for(i=1;i<3;i++)

   {

    cout<<"������B���"<<i+1<<"���˵�����\n";

     getline(cin,b[i]);

   }

    system("color 2E");
     master  a1(a[0]);
     Wizard  a2(a[1]);
     Warrior  a3(a[2]);//��һ��

     master   b1(b[0]);
     Wizard   b2(b[1]);
     Warrior  b3(b[2]);


     soldier *groupA[GROUP_SIZE]={&a1,&a2,&a3};
     //�ڶ���
     soldier *groupB[GROUP_SIZE]={&b1,&b2,&b3};
         //���������WarSystem
     warSystem war(groupA,groupB);
     war.startWar();
}

else if(s=='N'||s=='n')

    cout<<"���Ѿ��ɿ���˳���Ϸ��\n";

else

   cout<<"������������˵��Ŷ��";

     system("color 1E");
     return 0;
}
