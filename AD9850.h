/************************************************************
*					AD9850.h								*
*					AD9850的驱动程序头文件					*
*					Copyright (c)2009---MJC 				*
*					Free to Copy and Modify.				*
*					Author:Worrior							*
*					Date:2009-9-1							*
************************************************************/

#ifndef _AD9850_H_
#define _AD9850_H_
#include"stc11fx.h"

#define AD9850_125M 42.94967296//34.359738368//2^32除以晶振频率(125,000,000)

#define AD9850DATAPORT P1		//AD9850的8位数据口(MSB->LSB:25-28,1-4)
sbit AD9850WCLK = P0^3;   		//AD9850写控制字时钟(对应AD9850第7脚)
sbit AD9850FQUD = P0^5;   		//AD9850信号更新申请(对应AD9850第8脚)
sbit AD9850ReSet = P2^5;		//AD9850复位(对应AD9850第22脚)

//AD9850的复位函数
extern void AD9850Reset(void);

//AD9850设定频率字函数
extern void AD9850SetFre(float Fre);

#endif