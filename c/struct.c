#include <stdio.h>

typedef struct aa;
{
	float m1,m2,m3;
	int code;
	float moy;
};
void main ()
{
	float temp;
	int i,n;
	int j[i];
	printf("student numbers");
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
	printf("enter code");
	scanf("%d",&j[i].code);
	printf("m");
	scanf("%f",&j[i].m1,&j[i].m2,&j[i].m3);
	j[i].moy=(m1*m2*m3)/3;
    }	
    for (i=1;i<n;i++)
    {
    if (j[i].>j[i+1])
   { temp=j[i];
     j[i]=j[i+1];
     j[i+1]=temp;
   }
   }
   for (i=0;i<n;i++)
   printf("%d",j[i].code);
   
}