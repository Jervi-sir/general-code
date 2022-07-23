#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>

typedef struct postfixe
{
	char valeur;
	struct postfixe *suivant;
}PF;

PF* init()
{
	PF *sommet;
	sommet=NULL;
	return sommet;
}
void empiler(char X)
    {
        PF *nouveau,*sommet;
        nouveau= (PF *)malloc(sizeof( PF));
        nouveau->valeur = X;
        nouveau->suivant =sommet;
        sommet = nouveau;
    }

char depiler()                  //modifiée
{
    PF*courrant,*sommet;
    char n;                     //prend la valeur du depilement
    courrant=sommet;
    n = courrant->valeur;       //affectation
	sommet=sommet->suivant;
    free(courrant);
    return n;                   //retoure
}
int operateur(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int propriter(char symbol)
{
	if(symbol == '^')   return(3);
    if(symbol == '*' || symbol == '/')  return(2);
	if(symbol == '+' || symbol == '-')  return(1);
	if(symbol == '(' || symbol == ' ')  return(0);
}

int main()
{
	char exp[100];
	PF *sommet;
    char *e;
    char *v;
    char x;
    int i = 0;

     printf("enter l'expression\n");
    gets(exp);
      e = exp;
      v = exp;
          while(*v != '\0')                 //error check
    {
        if(*v == '(')   i++;
        if(*v == ')')   i--;
        v++;
    }

    empiler(' ');

if(i == 0)  {
    while(*e != '\0')
    {
        if(isalnum(*e)) printf("%c",*e);
            else    if(*e == '(')   empiler(*e);
                    else    if(*e == ')')
                            {
                                while((x = depiler()) != '(')
                                    printf("%c",x);
                            }

                            else
                                {
                                    while(propriter(sommet->valeur) >= propriter(*e))
                                          printf("%c",depiler());
                                    empiler(*e);
                                }

        e++;
    }

    while(sommet != NULL)
        {
            printf("%c",depiler());
        }

    }

else    printf("syntax error\n");

return 0;
}

