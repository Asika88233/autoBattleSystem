#ifndef REGULATIONS_H
#define REGULATIONS_H


//全局常量值
const int EXP_INCREMENT              = 5; //经验增加值
const int SP_INCREMENT               = 50;    //体力增加值
const int HP_INCREMENT               = 50;    //喝一瓶药水所增加的生命值
const int SP_DECREMENT               = 20;    //攻击后体力减少值
const int DAMAGE_INCREMENT           = 20;    //攻击力增加值
const int MAXHP_INCREMENT            = 100;   //最大生命增加值
const int MAXSP_INCREMENT            = 100;   //最大体力增加值
const int MAXMP_INCREMENT            = 100;   //最大内力增加值
const int GROUP_SIZE                 = 3; //组队成员数
const int ROUND_INTERVAL             = 1000; //回合时间间隔
const int ATTACK_INTERVAL            = 500;   //队员攻击时间间隔
const int MASTER_STROKE_RATE         = 3; //绝杀使用频率1/5
const int LOSE_TARGET_RATE           = 4; //没打中对方频率
const int ATTACK_SIZE                = 3;    //魔法攻击的人数范围 3人
const double MP_ROUND_RECOVER        = 0.2;   //每一回合内力恢复%
const double MP_ALLOW_MASTERSTROKE   = 0.3;   //内力恢复至百分比后允许绝杀
const double SP_ALLOW_MASTERSTROKE   = 0.3;   //体力恢复至百分比后允许绝杀
const double REST_CONDITION          = 0.3;   //休息指标
const double HAVE_DRUG_CONDITION     = 0.5;   //吃药底线指标
const int LUCKY_NUMBER               = 7; //随机数的幸运数字

#endif // REGULATIONS_H
