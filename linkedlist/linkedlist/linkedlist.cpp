// linkedlist.cpp : Defines the entry point for the console application.
//

// pointers.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}x;

struct node *add_begin(struct node *head)
{
	//int n;
	struct node *temp = &x, *newnode;
	newnode = (node *)malloc(sizeof(struct node));
	printf("Enter data");
	scanf_s("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
	return(head);
}
struct node *delete_node(struct node *head)
{
	int n, i;
	struct node *temp = &x;
	printf("Enter the position of node that has to be deleted");
	scanf_s("%d", &n);
	temp = head;
	if (n == 1)
	{
		temp = temp->next;
		head = temp;
	}
	else
	{
		for (i = 0; i < n - 2; i++)
		{
			temp = temp->next;

		}
		temp->next = temp->next->next;
	}
	return(head);
}

void add_end(struct node *head)
{
	int n;
	struct node *temp = &x, *newnode;
	newnode = (node *)malloc(sizeof(struct node));
	printf("Enter data");
	scanf_s("%d", &newnode->data);
	newnode->next = NULL;
	//newnode->data = n;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	//temp->data = n;
}

void add_middle(struct node *head)
{
	int n, pos, i;
	struct node *temp = &x, *newnode;
	newnode = (node *)malloc(sizeof(struct node));
	printf("Enter the pos of data");
	scanf_s("%d", &pos);
	printf("Enter data");
	scanf_s("%d", &newnode->data);
	temp = head;
	for (i = 0; i<pos - 2; i++)
	{
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

int main()
{
	struct node *temp = &x, *newnode, *head;
	int n, i, e, h;
	printf("number of elements:");
	scanf_s("%d", &n);
	head = NULL;
	for (i = 0; i < n; i++)
	{
		newnode = (node *)malloc(sizeof(struct node));
		scanf_s("%d", &newnode->data);
		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode; temp = head;
		}
		else
		{
			temp->next = newnode;
			temp = temp->next;
		}

	}

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		printf("%d\n", temp);
	}
	//scanf_s("%d", &n);

	printf("\n1.add at beginning, 2.add at the end, 3.add a node in middle, 4.delete a node");
	scanf_s("%d", &e);
	switch (e)
	{
	case 1: head = add_begin(head);
		break;
	case 2:add_end(head);
		break;
	case 3:add_middle(head);
		break;
	case 4:head = delete_node(head);
		break;
	default:printf("Error");
	}
	temp = head;
	printf("\nData after entering is ");
	while (temp != NULL)
	{
		temp = temp->next;
	}
	scanf_s("%d", &h);
	return 0;
}

