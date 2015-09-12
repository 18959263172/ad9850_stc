/************************************************************
*					AD9850.c								*
*					AD9850����������C�ļ�					*
*					Copyright (c)2009---MJC 				*
*					Free to Copy and Modify.				*
*					Author:Worrior							*
*					Date:2009-9-1							*
************************************************************/

#include<intrins.h>
#include"AD9850.h"

/********************
**����:AD9850Reset
**����:AD9850�ĸ�λ����
**����:Worrior
**����:2009-9-1
********************/
void AD9850Reset(void)
{
	AD9850WCLK = 0;
	AD9850FQUD = 0;
	AD9850ReSet = 0;
	AD9850ReSet = 1;//��λ���øߵ�ƽ(10��AD9850��ʱ������)


	AD9850ReSet = 0;//��λ���,������
}

void delay2()
{
	char x=25;
	for(;x>0;x--) ;
}
/********************
**����:AD9850SetFre
**����:AD9850�趨Ƶ�ʿ����ֺ���
**����:Fre,float��,Ҫ�趨��Ƶ��,��λHz
**����:Worrior
**����:2009-9-1
********************/
void AD9850SetFre(float Fre)
{
	unsigned long FTW = 0;//Ҫд���32λƵ�ʿ�����(AD9850һ����Ҫд��40λ������)
	unsigned char part1,part2,part3,part4;
	if(Fre > 30000000)
		Fre = 30000000;
	FTW = (unsigned long) (Fre * AD9850_125M);//����Ƶ�ʿ�����(��ʽ:FTW=(2^32/fosc)*Fre)
	/*���½�32λƵ�ʿ����ַֽ�*/
	part1 = (unsigned char) (FTW>>24);//ȡ32~25λ
	part2 = (unsigned char) (FTW>>16);//ȡ24~17λ
	part3 = (unsigned char) (FTW>>8); //ȡ16~9λ
	part4 = (unsigned char) (FTW);	  //ȡ8~1λ
	/*���Ͻ�32λƵ�ʿ����ַֽ�*/

	AD9850FQUD = 0;
	AD9850WCLK = 0;
	AD9850DATAPORT = 0x00;//�Ĵ�����ߵİ�λֻ��0x00
	AD9850WCLK = 1;//WCLK������������
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part1;
	AD9850WCLK = 1;//WCLK������������
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part2;
	AD9850WCLK = 1;//WCLK������������
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part3;
	AD9850WCLK = 1;//WCLK������������
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part4;
	AD9850WCLK = 1;//AD9850WCLK������������
	delay2();

	AD9850FQUD = 1;//AD9850FQUD�����ؽ�AD9850��������40λ��������DDS Core

}
