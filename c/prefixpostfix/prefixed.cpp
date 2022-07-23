#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *suiv;
};


struct node *top;


void initialize()
{
    top = NULL;
}

void EMP(int value)
{	//sreat 1 node
	struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> data = value;

    //add node to stack
    tmp -> suiv = top;

    //top with point the last added
    top = tmp;

}


int DEP()
{
	struct node *tmp;
	int n;
	tmp = top;				//as pointing

	n = tmp -> data;
	top = top ->suiv;		//next last one of stack

	free(tmp);
	return n;
}


int empty()
{
    return top==NULL;
}



int main()
{
	char exp[20];
	char *e;
	int num;
	int n1,n2,n3;

	printf("enter notion posfixé\n");
	gets(exp);

	e = exp;

	while(*e != '\0')
	{
		if(isalnum(*e))
			{  num = *e - 48;
               EMP(num);
            }
            else
                {       n1 = DEP();
                        n2 = DEP();
                        switch(*e)
                        {
                                case '+':n3 = n1 + n2;break;
                                case '-':n3 = n2 - n1;break;
                                case '*':n3 = n1 * n2;break;
                                case '/':n3 = n2 / n1;break;

                        }
                        EMP(n3);
                }
        e++;
    }
        printf("\nThe result of expression %s  =  %d\n\n",exp,DEP());
        return 0;
	}

