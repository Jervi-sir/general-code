#include<stdio.h>
#include<stdlib.h>

struct pile
{
    int valeur;
    struct pile *suivant;
};

struct pile *pile1 = NULL;
struct pile *pile2 = NULL;

void empiler(struct pile *sommet,int x)
    {
        struct pile *nouveau;
        nouveau = (struct pile *)malloc(sizeof(struct pile));
        nouveau->valeur = x;

        nouveau->suivant = sommet;

        sommet = nouveau;
    }

int depiler(struct pile *sommet)
    {
        struct pile *nouveau;
        int n;
        nouveau = sommet;

        n = nouveau->valeur;
        sommet = sommet->suivant;

        free(nouveau);

        return n;
    }

void transfaire(struct pile *sommet1,struct pile *sommet2,int x)           //sommet1 ==>pile1          //sommet2 ==>pile2
{
    int n;

	while(sommet1!=NULL)
	{
		if((n=depiler(sommet1)) != x)
        {
            empiler(sommet2,n);
        }
	}
}

void empilerlapile()                    //just pour remplier la pile 1
{   int T[8]={1,5,7,10,5,3,7,10};
    empiler(pile1,T[i]);
    for(int i = 0; i < 8;i++)
    {
        empiler(pile1,T[i]);
    }

}

void afficher(struct pile *sommet)
{
	struct pile *current;
	current = sommet;

    if(current!= NULL)
    {
        printf("Stack: ");
        do
        {
            printf("%d ",current->valeur);
            current = current->suivant;
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }


}

int main()
{
	int x;
	empilerlapile();
	afficher(pile1);                 //activer le remplissement de la pile1
	printf("rentrait le nombre a retitre    {1,5,7,10,5,3,7,10}\n");
	scanf("%d",&x);
	transfaire(pile1,pile2,x);
	afficher(pile2);
}

