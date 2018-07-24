#include "Log.h"
#include "Soldier.h"

Log::Log(void)

{

}

Log::~Log(void)

{

}


void Log::print(string message) const// 输出字符串
{
       cout << message;
}

void Log::print(soldier *warrior) const//输出对象
{
    if (!warrior->die())
    {
        cout << warrior->getName()
             << "生命(" << warrior->HP << "/" << warrior->maxHP << ")"<< endl
             << "体力(" << warrior->SP << "/" << warrior->maxSP << ")"<< endl
             << "魔力(" << warrior->MP << "/" << warrior->maxMP << ")"<< endl
             << "药品(" << warrior->drugNum << ")"<< endl
             << "经验(" << warrior->EXP << ")"<< endl
             << "等级(" << warrior->level << ")"<< endl
             << "攻击(" << warrior->damage << ")" << endl;

    }
    else
    {
        cout << warrior->getName()
             << "被干掉了" <<endl;
    }
}
void Log::print(int n)

{
    cout << n;
}
//输出数字
