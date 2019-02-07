// stack.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int arr[5];
	int top;
}s;

void init(struct stack *st)
{
	st->top = -1;
}
void push(struct stack *st)
{
	int n;
	if (st->top == 4)
		printf("stack is full\n");
	else
	{
		st->top++;
		printf("Enter number to be stacked");
		scanf_s("%d", &n);
		st->arr[st->top] = n;
	}
}

void pop(struct stack *st)
{
	int num;
	if (st->top == -1)
		printf("stack is empty\n");
	else
	{
		num = st->arr[st->top];
		printf("deleted element is %d \n", num);
		st->top--;
	}

}

void display(struct stack *st)
{
	int i;
	if (st->top == -1)
		printf("stack is empty");
	else
	{
		printf("\nThe elements in the stack are ");
			for (i = 0; i <= st->top; i++)
				printf("%d ", st->arr[i]);
	}

}

int main()
{
	int n;
	struct stack *st=&s;
	init(st);
	do
	{
		printf("1.push,2.pop,3.display,4.exit");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1: push(st);
			break;
		case 2: pop(st);
			break;
		case 3:display(st);
			break;
		case 4: printf("DONE BYE");
			break;
		default:printf("ERROR");
		}
	} while (n != 4);
    return 0;
}

