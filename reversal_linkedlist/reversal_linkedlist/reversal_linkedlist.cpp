// reversal_linkedlist.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node* head;

void create_linkedlist(int n)
{
	int i;
	struct Node *new_node, *prev;
	printf("Enter elements");
	head = (struct Node*)malloc(sizeof(struct Node));
	scanf_s("%d", &head->data);
	prev = head;
	for (i = 0; i < n-1; i++)
	{
		new_node = (struct Node*)malloc(sizeof(struct Node));
		scanf_s("%d", &new_node->data);
		prev->next = new_node;
		new_node->next = NULL;
		prev = new_node;
	}
}

void display()
{
	struct Node* temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void reverse_list()
{
	struct Node *temp, *prev, *current;
	prev = head;
	current = prev->next;
	prev->next = NULL;
	while (current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
}


void reverse_list_recursion(struct Node *p)
{
	struct Node *q;
	if (p->next == NULL)
	{
		head = p;
		return;
	}
	reverse_list_recursion(p->next);
	q = p->next;
	q->next = p;
	p->next = NULL;
};

int main()
{
	int n, i, j;
	printf("Enter number of elements in linkedlist");
	scanf_s("%d", &n);
	create_linkedlist(n);
	printf("The elements entered in linkedlist are ");
	display();
	reverse_list();
	printf("\nThe reversed linkedlist is ");
	display();
	reverse_list_recursion(head);
	printf("\nThe reversed linkedlist is (recursion) ");
	display();
	scanf_s("%d", &j);
    return 0;
}

