#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}*root,*first=NULL,*temp=NULL,*x;

void create()
{
	int n, c = 0,data;
	struct tree *newnode;
	printf("Enter no of elements in binary tree");
	scanf_s("%d", &n);
	while (c < n)
	{
		newnode = (struct tree *)malloc(sizeof(struct tree));
		printf("\nEnter element");
		scanf_s("%d", &newnode->data);
		newnode->left = NULL;
		newnode->right = NULL;
		printf("Address of newnode is %d\n", newnode);
		if (root == NULL)
		{   
			root = newnode;
			first = root;
	    }
		else
		{
			while (root != NULL)
			{
				temp = root;
				if (newnode->data <= root->data)
					root = root->left;
				else
					root = root->right;
				//printf("%d|%d|%d add is %d   ", temp->left, temp->data, temp->right,temp);
			}
			//root = newnode;
			if (temp->data >= newnode->data)
				temp->left = newnode;
			else
				temp->right = newnode;
			//printf("After inserting ");
			//printf("%d|%d|%d add is %d   ", temp->left, temp->data, temp->right, temp);
		}
		c++;
		root = first;
	}
}

void display(struct tree *temp1)
{
	if (temp1 == NULL)
		return;
	display(temp1->left);
	printf("%d ", temp1->data);
	display(temp1->right);
}

int main()
{
	int n;
	printf("create a binary tree");
	create();
	printf("The elements present inorder are ");
	display(first);
	printf("Address of first node is %d", first);
	scanf_s("%d", &n);
    return 0;
}

