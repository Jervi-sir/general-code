#include<stdio.h>


int main()
{
	int i = 0;
	while(i<288)
	{
		printf("%d;%d;%d;%d\n",i+4,i+1,i+8,i+5);
		i = i + 8;
	}
	printf("\n");printf("\n");printf("\n");
	printf("\n");printf("\n");printf("\n");

	int a = 0;
	while(a<288)
	{
		printf("%d,%d;%d,%d\n",a+2,a+3,a+6,a+7);
		a = a + 8;
	}

}
