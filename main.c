
#include"AD9850.h"

#include"stc11fx.h"
void main()
{
	AD9850Reset();

	AD9850SetFre(1000.0);//�趨AD9850Ƶ��Ϊ1000Hz
	while(1){}
}
