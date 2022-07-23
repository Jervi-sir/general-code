#include<stdio.h>

int char_to_int (char x)
{
	return x-48;
}


int main()
{
	char exp[2];
	char *e;

	printf("enter number\n");
	gets(exp);
	e = exp;
	printf("%d",char_to_int(*e)+1);
}
