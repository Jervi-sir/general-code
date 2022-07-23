#include<stdio.h>

int main()
{	
	int a;
	int i;

	for(i=1; i<600;i++)
	{	
			//test conditions
		if(i%3==0)	a=1;	
		if(i%5==0)	a=2;	
					
		if(i%3==0 && i%5==0)	a=3;	
		if(i%3!=0 && i%5!=0)	a=4;

			//make decision
		switch(a)
		{
			case 1 :	printf("%d   fizz\n",i);break;
			case 2 :	printf("%d   buzz\n",i);break;
			case 3 :	printf("%d    fizz buzz\n",i);break;
			default :	printf("%d\n",i);break;	

		}	
	}

}