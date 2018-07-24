#ifndef MASTER_H
#define MASTER_H
#include <string>
#include "Wizard.h"
using namespace std;

class master:public Wizard
{
	public:
		master(string);
		virtual ~master();
		void masterAttack(soldier *);
		virtual int getHP();
		void makeDecision(soldier **);
	protected:

	private:
};

#endif // MASTER_H
