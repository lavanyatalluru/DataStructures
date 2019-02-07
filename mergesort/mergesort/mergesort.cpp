// mergesort.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

void merge_sort(int *left, int *right, int *a)
{
	int nl, nr,i=0,j=0,k=0;
	nl = sizeof(left) / sizeof(left[0]);
	nr = sizeof(right) / sizeof(right[0]);
	while (i < nl && j < nr)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < nl)
	{
		a[k] = left[i]; i++; k++;
	}
	while (j < nr)
	{
		a[k] = right[j]; j++; k++;
	}

}
void merge(int *a)
{
	int l,mid,left[BUFSIZ],right[BUFSIZ],i;
	l = sizeof(a) / sizeof(a[0]);
	if (l == 1)
		return;
	mid = l / 2;
	for (i = 0; i < mid ; i++)
	{
		left[i] = a[i];
	}
	for (i = mid; i < l; i++)
	{
		right[i] = a[i];
	}
	merge(&left);
	merge(&right);
	merge_sort(&left, &right, a);

}


int main()
{
	int i,a[] = { 7,1,4,2,3 };
	/*printf("Enter no of elements in array");
	scanf_s("%d", &n);
	printf("Enter elements");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}*/
	merge(&a[0]);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
    return 0;
}

