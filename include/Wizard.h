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
		void wizard_attack(soldier **);//新方法魔法攻击，攻击地方全体
		void wizardStroke(soldier *);
		virtual void makeDecision(soldier **);
		virtual int getHP();
};

#endif // WIZARD_H
