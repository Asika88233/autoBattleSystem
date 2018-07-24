#ifndef _MYRANDOM_H
#define _MYRANDOM_H

extern "C"
{
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//标准c的函数库,需要在extern "C"块内说明
}
#include "Log.h"//随机数类

class myRandom

{
public:
    myRandom(void);//构造函数
    virtual ~myRandom(void); //析构函数
    unsigned int number(unsigned int,unsigned int);//随机数函数,产生指定范围内的随机数

};

#endif //_MYRANDOM_H
