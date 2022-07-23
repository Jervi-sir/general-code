#include <stdio.h>
#include <stdlib.h>

int a[20];

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert_list(Node *current, int data) {
    Node *head = current;  //keep track of first node

    while(current->next != head) {
        current = current->next;
    }
    current->next = (Node*)malloc(sizeof(Node));
    current = current->next;
    current->data = data;
    current->next = head;
}


void print_list(Node *current) {

    Node *head = current;
    current = current->next;
    while(current != head){
        printf(" %d ", current->data);
        current = current->next;
    }

}



int main() {

    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head;

    int data = 0 ;
    int usr_input = 0;
    int i;
    int m;



        printf("enter number of node   ");
        scanf("%d",&usr_input);

        for (i=0; i<usr_input; i++) {
            printf("%d..    ",i);
            scanf("%d",&data);
            insert_list(head, data);

        }


            printf("The list is ");
            print_list(head);
            printf("\n\n");

    return 0;
}
