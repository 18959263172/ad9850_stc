/************************************************************
*					AD9850.h								*
*					AD9850����������ͷ�ļ�					*
*					Copyright (c)2009---MJC 				*
*					Free to Copy and Modify.				*
*					Author:Worrior							*
*					Date:2009-9-1							*
************************************************************/

#ifndef _AD9850_H_
#define _AD9850_H_
#include"stc11fx.h"

#define AD9850_125M 42.94967296//34.359738368//2^32���Ծ���Ƶ��(125,000,000)

#define AD9850DATAPORT P1		//AD9850��8λ���ݿ�(MSB->LSB:25-28,1-4)
sbit AD9850WCLK = P0^3;   		//AD9850д������ʱ��(��ӦAD9850��7��)
sbit AD9850FQUD = P0^5;   		//AD9850�źŸ�������(��ӦAD9850��8��)
sbit AD9850ReSet = P2^5;		//AD9850��λ(��ӦAD9850��22��)

//AD9850�ĸ�λ����
extern void AD9850Reset(void);

//AD9850�趨Ƶ���ֺ���
extern void AD9850SetFre(float Fre);

#endif