//컴퓨터학과 20190975 신효경
#include <stdio.h>
#define WORD_LEN 100
int main(void)
{
	char str[WORD_LEN], word[WORD_LEN];
	int i, temp = 0, result = 0, k= 0;

	printf("Enter a word: ");
	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9'){
			temp += str[i] - '0';
			if (str[i+1] >= '0' && str[i+1] <= '9'){
				temp *= 10;
			}
			else {
				result += temp;
				temp = 0;
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z')  
		{
			word[k] = str[i];
			k++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			word[k] = str[i];
			k++;
		}
		else
			continue;
	}
	word[k] = '\0';
	printf("%d\n%s\n", result, word);

}