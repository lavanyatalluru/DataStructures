// reversestring.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

int main()
{
	char s[100]; 
	//char *s;
	int l = 0, i = 0, n;
	printf("Enter string");
	/*while (s != '\0')
	{
		scanf_s("%c", s);
		s--;
	}*/
	gets(s);
	printf("reverse of a string is ");
	while (s[i] != '\0')
	{
		l++; i++;
	}
	i = l-1;
	while (i >=0)
	{
		printf("%c", s[i]);
		i--;
	}
	printf("\nLength of the string is %d", l);
	scanf_s("%d", &n);
    return 0;
}

