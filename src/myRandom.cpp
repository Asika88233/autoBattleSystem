#include "MyRandom.h"

//���캯��

myRandom::myRandom()
{
srand( (unsigned)time(NULL));
}

//��������

myRandom::~myRandom(void)

{

}

//���������,������range_min��range_max֮������������

unsigned myRandom::number(unsigned RANGE_MIN,unsigned RANGE_MAX)
{
     int num;
     num=(((double)rand()/(double)RAND_MAX)*RANGE_MAX+RANGE_MIN);
     return num;
}
