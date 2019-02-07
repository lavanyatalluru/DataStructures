// quicksort.cpp : Defines the entry point for the console application

#include<stdio.h>

void exchange(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int *a, int n)
{
	int front, rear, key;
	if (n < 0)
		printf("Error");
	if (n <= 1)
		return;
	if (n == 2)
	{
		if (a[0] > a[1])
		{
			exchange(&a[0], &a[1]);
		}
		return;
	}
	if (n >= 3)
	{

		front = 0; rear = n - 1;
		key = a[n / 2];

		while (front <= rear)
		{
			while (a[front] <= key && front <= rear)
				front++;
			while (a[rear] >= key && front <= rear)
				rear--;
			if (front <= rear)
			{
				exchange(&a[front], &a[rear]);
				front++;
				rear--;
			}

		}
			quicksort(&a[0], rear + 1);
			quicksort(&a[front], n - front);
	}

}

void main()
{
	int a[100],i, n,rn;
	printf("Enter no of elements");
	scanf_s("%d", &n);
	printf("Enter elements");
	for (i = 0; i < n; i++)
	scanf_s("%d", &a[i]);
	quicksort(&a[0],n);
	printf("Sorted elements are ");
	for (i = 0; i < n; i++)
    printf("%d ", a[i]);
	printf("done...!");
	scanf_s("%d",&rn);
}
