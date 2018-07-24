#ifndef _LOG_H

#define _LOG_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//日志类

class soldier;//提前声明soldier类,在cpp中再包含solder.h避免交叉包含

class Log

{
public:
    Log(void);//构造函数
    virtual~Log(void);//析构函数
    void print(soldier *) const;//输出对象
    void print(string message) const;//输出信息
    void print(int);//输出数字

};

#endif //_LOG_H
