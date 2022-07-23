#include<stdio.h>

int main()
{
	int r,e,n,i=1;
	int t[10];
	
	printf ("enter n ");
	scanf("%d",&n);
	
	while (n != 0)
{
	r=n%10;
	t[i]=r;
	e=e+t[i];
	if (n%100==0) {t[i+1]=n/10;break;}
	else {i++;
	        n=n/10;}
}
printf ("%d",e);
}