#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 100

void get_lps(char *pattern, int *lps, int n);
int kmp(char *text, char *pattern, int *indexes);

int main(void)
{
	char text[BUFF_SIZE];
	char pattern[BUFF_SIZE];
	
	printf("Text: ");
	scanf("%s", text);
	printf("Pattern: ");
	scanf("%s", pattern);

	int indexes[BUFF_SIZE];

	int ni = kmp(text, pattern, indexes);
	if (ni <= 0)
	{
		printf("Pattern not exist in text\n");
		exit(0);
	}

	int i;
	for (i = 0; i < ni; i ++)
		printf("Pattern exist at text[%d]\n", indexes[i]);

	exit(0);
}

void get_lps(char *pattern, int *lps, int n)
{
	if (n <= 0)
		return;

	int i, j = 0;
	lps[0] = 0;

	for (i = 1; i < n; i ++)
	{
		if (pattern[j] == pattern[i])
		{
			lps[i] = lps[i-1] + 1;
			j ++;
		}
		else if (j > 0)
		{
			j = lps[j - 1];
			i --;
		}
		else
		{
			lps[i] = 0;
		}
	}
}

int kmp(char *text, char *pattern, int *indexes)
{
	int n = strlen(pattern);
	int m = strlen(text);

	int *lps = malloc(n * sizeof(int));
	get_lps(pattern, lps, n);

	int i = 0, j = 0;
	int k = 0;

	while (i < m)
	{
		if (pattern[j] == text[i])
		{
			i ++;
			j ++;
		}

		if (j >= n)
		{
			indexes[k ++] = i - j;
			j = lps[j - 1];
		}
		if (i < m && text[i] != pattern[j])
		{
			if (j > 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i ++;
			}
		}
	}

	free(lps);

	return k;
}


