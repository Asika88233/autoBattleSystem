#ifndef _LOG_H

#define _LOG_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//��־��

class soldier;//��ǰ����soldier��,��cpp���ٰ���solder.h���⽻�����

class Log

{
public:
    Log(void);//���캯��
    virtual~Log(void);//��������
    void print(soldier *) const;//�������
    void print(string message) const;//�����Ϣ
    void print(int);//�������

};

#endif //_LOG_H
