-#include <stdlib.h>
#include <stdio.h>

struct Node                             //node structure
{   int key;
    struct Node *next;
};

struct queue                             //creat queue
{   struct Node *front, *rear;
};
struct queue *creatQueue()                      //creat in queue
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

struct Node* newNode(int k)                     //creation d un node avec valeur
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->key = k;                          //affect valeur k sur node temp
    temp->next = NULL;

    return temp;
}


void enQueue(struct file *q, int k)
{
    struct Node *temp = newNode(k);         // Create a new node

    if (q->rear == NULL)        // If file is empty, then new node is front and rear both
    {
       q->front = q->rear = temp;
       return;
    }

    q->rear->next = temp;        // Add the new node at the end of queue and change rear
    q->rear = temp;
}


struct Node *deQueue(struct queue *q)
{
    if (q->front == NULL)          // If queue is empty, return NULL.
       return NULL;


    struct Node *temp = q->front;       // Store previous front and move front one node ahead
    q->front = q->front->next;


    if (q->front == NULL)            // If front becomes NULL, then change rear also as NULL
       q->rear = NULL;
    return temp;
}

int main()
{
    struct queue *q = creatQueue();      //action to creat new queue

    int T[6] = {3,56,0,26,23,2,5};

    struct Node *n;   //creat n as node to hold the result of deQueue

    for(int i = 0;i < T[3]%10;i++)
    {
            enQueue()
    }

    return 0;
}



