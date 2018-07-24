#ifndef SOLDIER_H
#define SOLDIER_H
//��ɫ�࣬Ϊ���������������ͣ�����Ϊ��������������
#include "Regulations.h"//������
#include "MyRandom.h" //�������
#include "Log.h"       //��־��
#include <string>

using namespace std;
class soldier
{
	public:
		soldier();
		virtual ~soldier();
		virtual void attack(soldier *)=0;//���麯����������������ʵ�ַ����������ڼ̳е�������Ӧ�ø�����Ӧ��ʵ�ַ�����
		virtual void rest(void)=0;     //���麯��,��Ϣ
		virtual void restAgain(void)=0;//���麯��,������Ϣ
		virtual void haveDrug(void)=0;//��ҩ������������ͬ���Ǵ��麯�����ָ�������
		virtual bool die(void)=0;  //���麯��,����
		virtual void makeDecision(soldier **)=0;//���麯��,����,��һ������н��о���
		virtual string getName()=0;//�������
                        virtual void setHP(int)=0;
                        virtual int getDrug()=0;
                        virtual int getHP()=0;
                        friend void Log::print(soldier *) const;
                        friend void Log::print(string message) const;
	            //��Ԫ����,ʹ��Log���ܹ�����soldier����
	protected:
	           int maxHP;             //�������    health
                       int HP;                //��ǰ����
                       int maxSP;             //�������    strength
                       int SP;                //��ǰ����
                       int MP;                //ֻ�з�ʦ��ħ����Դ������Ϊ����ʾ��ͳһ�ԣ���ͨ�û�����ͬ������mp����
                       int maxMP;
                       int damage;            //������
                       int EXP;           //����
                       int level;             //�ȼ�
                       string name;       //����
	           int drugNum;       //ҩƷ��
	           myRandom random;   //���������
	           Log log;           //��־����


};

#endif // SOLDIER_H
