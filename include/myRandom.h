#ifndef _MYRANDOM_H
#define _MYRANDOM_H

extern "C"
{
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//��׼c�ĺ�����,��Ҫ��extern "C"����˵��
}
#include "Log.h"//�������

class myRandom

{
public:
    myRandom(void);//���캯��
    virtual ~myRandom(void); //��������
    unsigned int number(unsigned int,unsigned int);//���������,����ָ����Χ�ڵ������

};

#endif //_MYRANDOM_H
