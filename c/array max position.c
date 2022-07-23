#include <stdio.h>
int main()
{
	int i,max,nax;
	int n[10];
	for(i=0;i<9;i++)
	{
		printf("a");
    	scanf("%d",&n[i]);
	}
	max=n[0];
	for(i=1;i<9;i++)
	{if (n[i]>max)
	{max=n[i];
	nax=i;
	}
	}
	printf("max =%d",max);
	printf("\n position =%d",nax);
	return 0;
	}
	