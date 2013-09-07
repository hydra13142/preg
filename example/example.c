#include <stdio.h>
#include "..\preg.h"

int main()
{
	const char s[]="12.343e3";
	regex *reg;
	int i;
	reg=preg_make("[-+]?\\d+(\\.\\d+)?([eE][-+]?\\d+)?");
	preg_show(reg,1);
	if((i=preg_more(reg,s))>0)
	{
		printf("%d\n",i);
	}
	preg_free(reg);
	return 0;
}
