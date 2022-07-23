 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>

 void Insert();
 void DisplayList();

 struct Student
	 {
	 char Name[10];
	 int Marks;
	 struct Student *Next;
	 } *Start;

 int main()
   {
	 Start = NULL;
	 int Choise;
	 while (1)
	 {
		 printf("enter number to choose ");
		 scanf_s("%d", &Choise);
	 switch (Choise)
	 	{
		 case 1:Insert();break;
		 case 3:DisplayList();break;
		 default:printf("Incorrect assignment Press relevant key :");
		}
	}
  }
		    
 void Insert()
{
	struct Student *Temp, *current=NULL;
	Temp = (struct Student *) malloc(sizeof(struct Student));
	printf("Enter Name Of Student");
	scanf("%s",&Temp->Name);
	
	printf("Enter Marks Of Student");
	scanf("%d", &Temp->Marks);
	
	Temp->Next = NULL;
	if (Start == NULL)
		{
		 Start = Temp;
		 Temp->Next = NULL;
		}
	else current = Start;
	
	while (current->Next != NULL)
	{
		current = current->Next;
		current->Next = Temp;
	}

}

void DisplayList()
{
    struct Student *current, *Temp;
    current = Start->Next;
    
    if (Start == NULL) printf("No Element in the list");
    
    else for (current = Start; current != NULL; current = current->Next)
        {
            printf("The List are\n");
            printf_s("%d",current->Marks);
        }

}