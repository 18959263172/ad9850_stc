/************************************************************
*					AD9850.c								*
*					AD9850的驱动程序C文件					*
*					Copyright (c)2009---MJC 				*
*					Free to Copy and Modify.				*
*					Author:Worrior							*
*					Date:2009-9-1							*
************************************************************/

#include<intrins.h>
#include"AD9850.h"

/********************
**函数:AD9850Reset
**功能:AD9850的复位函数
**作者:Worrior
**日期:2009-9-1
********************/
void AD9850Reset(void)
{
	AD9850WCLK = 0;
	AD9850FQUD = 0;
	AD9850ReSet = 0;
	AD9850ReSet = 1;//复位脚置高电平(10个AD9850的时钟周期)


	AD9850ReSet = 0;//复位完成,再拉低
}

void delay2()
{
	char x=25;
	for(;x>0;x--) ;
}
/********************
**函数:AD9850SetFre
**功能:AD9850设定频率控制字函数
**参数:Fre,float型,要设定的频率,单位Hz
**作者:Worrior
**日期:2009-9-1
********************/
void AD9850SetFre(float Fre)
{
	unsigned long FTW = 0;//要写入的32位频率控制字(AD9850一次需要写入40位控制字)
	unsigned char part1,part2,part3,part4;
	if(Fre > 30000000)
		Fre = 30000000;
	FTW = (unsigned long) (Fre * AD9850_125M);//计算频率控制字(公式:FTW=(2^32/fosc)*Fre)
	/*以下将32位频率控制字分解*/
	part1 = (unsigned char) (FTW>>24);//取32~25位
	part2 = (unsigned char) (FTW>>16);//取24~17位
	part3 = (unsigned char) (FTW>>8); //取16~9位
	part4 = (unsigned char) (FTW);	  //取8~1位
	/*以上将32位频率控制字分解*/

	AD9850FQUD = 0;
	AD9850WCLK = 0;
	AD9850DATAPORT = 0x00;//寄存器最高的八位只送0x00
	AD9850WCLK = 1;//WCLK上升沿送数据
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part1;
	AD9850WCLK = 1;//WCLK上升沿送数据
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part2;
	AD9850WCLK = 1;//WCLK上升沿送数据
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part3;
	AD9850WCLK = 1;//WCLK上升沿送数据
	delay2();

	AD9850WCLK = 0;
	AD9850DATAPORT = part4;
	AD9850WCLK = 1;//AD9850WCLK上升沿送数据
	delay2();

	AD9850FQUD = 1;//AD9850FQUD上升沿将AD9850缓冲区的40位数据送入DDS Core

}
