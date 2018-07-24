#ifndef WARSYSTEM_H
#define WARSYSTEM_H

#include "master.h"
#include "regulations.h"
#include "MyRandom.h"
#include "Log.h"
#include <windows.h>
#include "Warrior.h"
#include "Wizard.h"
#include "soldier.h"

using namespace std;
class warSystem
{
	public:
		warSystem(soldier *[],soldier *[]);
		virtual ~warSystem();
		void startWar(void);

	protected:

	private:
		 soldier ** _pWarriorA;
		 soldier ** _pWarriorB;
		 void startRound(soldier **, soldier**);
		 bool groupDefeated(soldier **);
		 Log log;
};


#endif // WARSYSTEM_H
