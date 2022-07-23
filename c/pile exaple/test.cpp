#include<stdio.h>
#include<stdlib.h>

typedef struct pile
{
    char valeur;
    struct pile *suivant;
}pile;
struct Pile *init()
{
	Pile *sommet;
	sommet=NULL;
	return sommet;
}
typedef struct pile2
{
    char valeur;
    struct pile *suivant;
}pile2;
struct Pile2 *init2()
{
	Pile2 *queux;
	queux=NULL;
	return queux;
}

void empiler(char x)
    {
    	  pile *sommet;
         pile *nouveau;
        nouveau = (pile *)malloc(sizeof( pile));
        nouveau->valeur = x;

        nouveau->suivant = sommet;

        sommet = nouveau;
    }
void empiler2(char x)
    {
    	  pile2 *queux;
         pile2 *nouveau;
        nouveau = (pile2 *)malloc(sizeof( pile2));
        nouveau->valeur = x;

        nouveau->suivant= queux;

        queux = nouveau;
    }


char depiler()
    {
    	 pile *sommet;
         pile *nouveau;
        char n;
        nouveau = sommet;

        n = nouveau->valeur;
        sommet = sommet->suiv;

        free(nouveau);

        return n;
    }

int transfaire(pile *sommet,int x)
{
	pile *sommet;
	pile *p=sommet;
	while(sommet!=NULL)
	{
		if(p->valeur!=x)
		{
			pile2=empiler2(p->valeur);
			depiler(p->valeur);
			p=p->suivant;
		}
		else{
			depiler(x);
				p=p->suivant;
		}
	}
	return pile2();
}
int main()
{
pile *sommet;
	pile *p=sommet;
	int x;
	printf("rentrait le nombre a retitre");
	scanf("%d",&x);
	transfaire(sommet,x);
}