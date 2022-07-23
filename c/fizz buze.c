#include <stdio.h>
#include <stdlib.h>

void in(int n)
{  if (n%3==0 && n%5==0) printf("fizz buzz\n");
    else if(n%3==0) printf("fizz\n");
    else if(n%5==0) printf("buzz\n");
                   else printf("%d\n",n);
                   
}
int main ()
{
	int n; 
	for (int i=1;i<100;i++)
	{in(i);
	}
}