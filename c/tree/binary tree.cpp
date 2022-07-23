#include<stdio.h>
#include<stdlib.h>
struct node
{	int key;
	struct node *left;
	struct node *right;
};

struct node root;

struct node* newNode(int data)
{
	struct node* node;
    node = (struct node*)malloc(sizeof(struct node));
	node -> left = NULL;
	node -> right = NULL;

	return(node);
}

struct node* insert(struct node* node,int key)
{
	if(node == NULL) return newNode(key);

	if(key < node->key )
			node->left 	= insert(node->left, key);
	else if(key > node->key)
			node->right = insert(node->right, key);


	return node;
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root -> left);
		printf("%d\n",root->left);
		inorder(root -> right);
	}
}

int main()
{	int a[]={30,20,40,70,60,80}
	struct node* root = NULL;
	root = insert(root,50);
	for(int i = 0; i < 6; i++)
		insert(root,a[0]);

    inorder(root);

    return 0;
}


#include<stdio.h>             
int main()                      
{
	int a[4],n,i,j;
	
      for(i=0;i<4;i++)
        scanf("%d",&a[i]);
		for (i = 0; i < 4; i++)                  
			for (j = 0; j < 4; j++)             
				if (a[j] > a[i])               
				{
					int tmp = a[i];         
					a[i] = a[j];            
					a[j] = tmp;             
				}  
			
	
	printf("Ascending : ");                    
	for (int i = 0; i < 4; i++)                     
		printf(" %d ", a[i]);
	
	for (int i = 0; i < 4; i++)                    
		for (int j = 0; j < 4; j++)            
			if (a[j] < a[i])              
			{
			int tmp = a[i];       
			a[i] = a[j];            
			a[j] = tmp;            
			}
		
	
	printf("Descending : ");                 
	for (int i = 0; i < 4; i++)                     
		printf(" %d ", a[i]);                 
	

	return 0;                                      
}
