#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "soldier.h"
using namespace std;
//սʿ��


class Warrior:public soldier
{
	public:
                   Warrior(string);//���캯��
	       virtual ~Warrior(void);//��������
                   void attack(soldier *);//����
	       void rest();//��Ϣ
	       void restAgain(); //��ս
                   void haveDrug(); //��ҩ,��ҩ�ָ�����
	       bool die();//����
	       virtual void makeDecision(soldier **);//����,��һ������н��о��� ÿ����ɫ�ľ���
                   bool enemyGroupDefeated(soldier **);//�ж��Ƿ��Ѿ����ܶԷ�ȫ��
	       virtual string getName();//��ȡ����
                   virtual void setHP(int);//��ɱ����������
	       int getDrug();//���ҩ��
                   bool restComplete; //�Ƿ���Ϣ����
                   virtual int getHP();
};

#endif // WARRIOR_H
