#include<stdio.h>

void test(int,int);

int main()
{	int n,x,e,a;
	printf("1 odd\n2 even\n\n\n");
	scanf("%d",&e);
	printf("from  ");
	scanf("%d",&a);

	printf("\nto    ");
	scanf("%d",&n);
	
	printf("\n\n\n");
	for(x=a;x<=n;x++)
	{	
		test(e,x);
	}
}

 void test(int e,int x)
 
 {
 	switch(e)
 	{case 1 :if(x%2!=0)	{printf("%d\n",x);}break;
 	 case 2 :if(x%2==0)	{printf("%d\n",x);}break;
 	 default:printf("invalid");}
 	  }
