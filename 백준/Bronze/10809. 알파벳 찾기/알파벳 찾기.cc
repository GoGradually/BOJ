#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)


int main(void) {
	char word[100];
	int count[26];
	for (int i = 0; i < 26; i++) {
		count[i] = -1;
	}

	scanf("%s", word);
	getchar();
	for (int i = 0; i < strlen(word); i++) {
		if (count[word[i] - 97] == -1)
			count[word[i] - 97] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", count[i]);
	}
}
