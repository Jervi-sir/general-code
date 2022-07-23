#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node                                 //creation d un noed
{
    char data;
    struct node *suiv;
};

struct node *top;                       //declaration top pour pile

void empiler(char value)                        //empilement
    {
        struct node *tmp;                       //declaration pointer pour le nouveau noed
        tmp = (struct node *)malloc(sizeof(struct node));   //allocation memoir pour le nouveau noed
        tmp->data = value;                      //affect-val(*tmp,value)        //noed prend la valeur
        tmp->suiv = top;                        //affect-adr(*tmp,top)      //tmp entre dans la pile
        top = tmp;                              //*top <- *tmp          //sommet de la pile pointe le nouveau noed
    }


char depiler()                          //depilement
    {
        struct node *tmp;               //nouveau noed
        char n;                         //pour la return
        tmp = top;                      //nouveau noed prend somment de pile
        n = tmp->data;                  //n va prend les donne -->>> n = val(tmp)
        top = top->suiv;                //top qui pointer le noed lu, va pointe vers les suivvant noed
        free(tmp);                      //libere noed
        return n;                       //return data
    }

int main()
{

    empiler('M');
    empiler('D');
    empiler('E');
    empiler('J');
    empiler('E');
    empiler('L');
   while(top != NULL)
   {
    printf("%c",depiler());
   }

return 0;
}
