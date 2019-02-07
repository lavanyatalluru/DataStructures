// queue.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue *next;
}*f = NULL, *r = NULL;
int c = 0;
void insert()
{
	struct queue *newnode;
	printf("Enter an element");
	newnode = (struct queue *)malloc(sizeof(struct queue));
	scanf_s("%d", &newnode->data);
	newnode->next = NULL;
	//printf("data in newnode is %d at add %d after using queue ", newnode->data, newnode);
	if (f == NULL && r == NULL)
	{
		f = r = newnode;
		c++;
	}
	else if (c == 5)
		printf("Queue is full");
	else
	{
		r->next = newnode;
		r = newnode;
		c++;
	}
	printf("element is at address %d and next node of f is %d", r, f->next);
}

void del()
{
	struct queue *temp = f;
	//printf("f is at address %d and deleted element is %d", f, f->data);
	if (f == NULL && r == NULL)
		printf("stack is empty");
	else if (f == r)
	{
		printf("deleted element %d is at address %d", f->data, f);
		f = r = NULL;
		free(temp);
	}
	else
	{
		printf("deleted element %d is at address %d", f->data, f);
		f = f->next;
		free(temp);
	}
}

void display()
{
	printf("%d ", f);
	if (f == NULL)
		printf("Queue is empty");
	else
	{
		printf("The elements in the queue are ");
		while (f != NULL)
		{
			printf("%d ", f->data);
			f = f->next;
		}
	}
}

int main()
{
	int n;
	do
	{
		printf("\n1.Insert, 2.Delete, 3. display, 4.Exit");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:insert();
			//printf("f is at %d and r is at %d\n", f, r);
			break;
		case 2:del();
			break;
		case 3:display();
			break;
		case 4:printf("done...!");
			break;
		default:printf("Error");
		}
	} while (n != 4);
	return 0;
}

