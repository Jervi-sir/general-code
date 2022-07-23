int ps(int,int);
int main()
{
	int i,j,r;
	printf("enter n");
	scanf("%d",&r);
	for (i=0;i<r;i++)
	{  for (j=0;j<=i;j++)
	     printf("%d    ",ps(i,j));
	printf("\n");
	}
	
return 0;
}

int ps(int a,int b)
{
	int i,res=1;
	if (b>a-b)
	    b=a-b;
	 for (i=0;i<b;i++)
	    {
	    	res*=(a-i);
	    	res/=(i+1);
	    }
	   return res;
}
