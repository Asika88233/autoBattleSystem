#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include "Warrior.h"
using namespace std;

class Wizard:public Warrior
{
	public:
		Wizard(string);
		virtual ~Wizard(void);
		void wizard_attack(soldier **);//�·���ħ�������������ط�ȫ��
		void wizardStroke(soldier *);
		virtual void makeDecision(soldier **);
		virtual int getHP();
};

#endif // WIZARD_H
