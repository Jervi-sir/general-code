#include <stdio.h>

int main ()
{ 
int r=0,n,i;
for (i = 10; i< 1000;i++)
{   n = i;
	while ( i != 0)
	{  r = r * 10;
	   r = r + n%10;
	   i =i / 10;
	}
	printf (" %d" , r );
	i=n;
}
}