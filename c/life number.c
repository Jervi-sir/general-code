int check(int );
int recheck(int );
main(){
	
	int m,d,y;
	printf("enter d/m/y\n");
	scanf("%d%d%d",&d,&m,&y);
	y=check(y);
	int d1;
	d1=m+d+y;
	
	int d2;
	d2 = check(d1);
	printf("%d\n",d2);

		
	
}


int check(int yy){
	
int a1 = 0;
  while (yy != 0){
  	a1= a1 + yy%10;
  	yy/=10;
  }
 recheck(a1);
}

int recheck(int yyy){
	int b;
	if(yyy>=10) b=check(yyy);
	return b;
}