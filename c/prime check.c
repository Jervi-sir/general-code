#include<stdio.h>

int main()
{int n,i, flag=0;
do 
{
	printf ("enter a positif intiger    ");
scanf("%d",&n);

for (i=2; i<= n/2 ; i++)
{/* non prime */
if (n%i==0)
{flag = 1;break;}
}
if (flag==0)
printf ("%d is prime\n",n);
else printf ("%d not prime\n",n);
}
while (n!=0);
return 0;
}