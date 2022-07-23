#include<stdio.h>
#include<stdlib.h>
struct pile
{
	int data;
	struct pile *suiv;
};

struct pile *pile1;
struct pile *pile2;


void empiler_pile1(int x)
{
	struct pile *tmp;
	tmp = (struct pile*)malloc(sizeof(struct pile));
	tmp->data =  x;
	tmp->suiv = pile1;
	pile1 = tmp;
}
void empiler_pile2(int x)
{
	struct pile *tmp;
	tmp = (struct pile*)malloc(sizeof(struct pile));
	tmp->data =  x;
	tmp->suiv = pile2;
	pile2 = tmp;
}


int depiler_pile1()
{
	struct pile *tmp;
	int n;
	tmp = pile1;
	n = tmp->data;
	pile1 = pile1->suiv;

	free(tmp);
	return n;
}
int depiler_pile2()
{
	struct pile *tmp;
	int n;
	tmp = pile2;
	n = pile2->data;
	pile2 = pile2->suiv;

	free(pile2);
	return n;
}





void affect(int x)
{	int n;
	for(int i = 0;i <5; i++)
	{	n = depiler_pile1();
		if(n != x)	empiler_pile2(n);
	}
}


void afficher_pile2()
{
	for(int i = 0;i < 4; i++)
	{
		printf("%d,",depiler_pile2());
	}
}

void addpile()
{
	int T[5] = {0,5,8,3,4};
	for(int i = 0;i < 5; i++)	empiler_pile1(T[i]);
}


int main()
{
	int x;
	addpile();
	printf("delete from		{0,5,8,3,4}\n");
	scanf("%d",&x);

	affect(x);
	afficher_pile2();
}














































