#include <stdio.h>
#include <ctype.h>

#define MAX_CHARS 1000

int isValid(char c)
{
	return isalpha(c) || isdigit(c);
}

int isSame(char c1, char c2)
{
	return (islower(c1) && islower(c2)) || (isupper(c1) && isupper(c2)) || (isdigit(c1) && isdigit(c2));
}

void expand(char s1 [], char s2 [])
{
	//a-f   abcdef
	//A-G   ABCDEFG
	//3-9   3456789
	int i, j = 0;
	char c1, op, c2, c;
	for (i = 0; s1[i] != '\0'; i++)
	{
		c1 = s1[i];
		op = s1[i + 1];
		c2 = s1[i + 2];
		if (i != 0 && c1 == '-' && isSame(s1[i - 1], op)) //to handle a-b-c
		{
			c1 = s1[i - 1];
			op = '-';
			c2 = s1[i + 1];
			i--;
			j--;
		}
		if (isValid(c1) && op == '-' && c2 != '\0' && isSame(c1, c2))//guaranteed after i there are two characters. (c1)(-)(c2)
		{
			if (c1 < c2)
				for (c = c1; c <= c2; c++)
					s2[j++] = c;
			else
				for (c = c1; c >= c2; c--)
					s2[j++] = c;
			i += 2;
		}
		else
		{
			s2[j++] = c1;
		}
	}
	s2[j] = '\0';
}

/*
  Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 
  into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, 
  and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
*/
void ex3_3()
{
	char s1 [] = "-i-z-aA-S-A S-A 0--9-0-3", s2[MAX_CHARS];
	int c, i = 0;

	expand(s1, s2);
	printf("%s\n", s1);
	printf("%s", s2);
}

main()
{
	ex3_3();
	printf("\nPress ENTER to continue. . .\n");
	getchar();
}