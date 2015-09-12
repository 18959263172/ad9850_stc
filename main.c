
#include"AD9850.h"

#include"stc11fx.h"
void main()
{
	AD9850Reset();

	AD9850SetFre(1000.0);//设定AD9850频率为1000Hz
	while(1){}
}
