#include "Log.h"
#include "Soldier.h"

Log::Log(void)

{

}

Log::~Log(void)

{

}


void Log::print(string message) const// ����ַ���
{
       cout << message;
}

void Log::print(soldier *warrior) const//�������
{
    if (!warrior->die())
    {
        cout << warrior->getName()
             << "����(" << warrior->HP << "/" << warrior->maxHP << ")"<< endl
             << "����(" << warrior->SP << "/" << warrior->maxSP << ")"<< endl
             << "ħ��(" << warrior->MP << "/" << warrior->maxMP << ")"<< endl
             << "ҩƷ(" << warrior->drugNum << ")"<< endl
             << "����(" << warrior->EXP << ")"<< endl
             << "�ȼ�(" << warrior->level << ")"<< endl
             << "����(" << warrior->damage << ")" << endl;

    }
    else
    {
        cout << warrior->getName()
             << "���ɵ���" <<endl;
    }
}
void Log::print(int n)

{
    cout << n;
}
//�������
