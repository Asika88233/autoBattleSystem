#include "MyRandom.h"

//构造函数

myRandom::myRandom()
{
srand( (unsigned)time(NULL));
}

//析构函数

myRandom::~myRandom(void)

{

}

//随机数函数,产生从range_min到range_max之间的整数随机数

unsigned myRandom::number(unsigned RANGE_MIN,unsigned RANGE_MAX)
{
     int num;
     num=(((double)rand()/(double)RAND_MAX)*RANGE_MAX+RANGE_MIN);
     return num;
}
