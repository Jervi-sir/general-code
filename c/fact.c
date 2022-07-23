#include <stdio.h>


long int fact(int);

main ()
{	
	int n;
	printf("enter\n");
	scanf("%d",&n);

	printf("factproam %ld",fact(n));

}

long int fact(int n)
{
    if (n >= 1)
        return n*fact(n-1);
    else
        return 1;
}
