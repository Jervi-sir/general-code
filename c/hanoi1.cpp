//	|		|		|
//-----------------------
//	L		M 		R

#include<stdio.h>

void tower(int n,char L,int M,int R)
	{
		if(n==1)
			printf("Move %d   from %c to %c\n",n,L,R);
		else
		{
			tower(n-1,L,R,M);
			tower(1,L,M,R);
			tower(n-1,M,L,R);
		}
	}
int main()
{
	int n;
	printf("enter number of Disk\n");
	scanf("%d",&n);

	tower(n,'A','B','C');
	return 0;
}