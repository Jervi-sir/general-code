#include<stdio.h>

main()
{	int i;
	for(i=0;i<600;i++)
	{	if (i%3!=0 || i%5!=0)	printf("%d\n",i);
			else {if(i%3==0)	printf("%d fizz",i);
				  printf("\n");
				  if(i%5==0)	printf("%d buzz",i);
				}

						}
}