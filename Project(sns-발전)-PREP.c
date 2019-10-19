//////컴퓨터학과 20190975 신효경
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 4

int isAllOnes(int a[ROW][3], int size) // Project(sns-발전)에서 check_links 함수와 같음 
{
	int i, j;


	for (i = 0 ; i < ROW; i++){
		for (j = 0; j < 3; j++){
			if (a[i][j] < 9)
				a[i][j] = 1;
			else
				a[i][j] = 0;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for (i = 0 ; i < ROW; i++)
		for (j = 0; j < 3; j++)
			if (a[i][j] == 0)
				return 0;

	return 1;

} 
int main(void) 
{ 
	int arr[ROW][3];
	int i, j;
	srand(time(NULL));

	for (i = 0 ; i < ROW; i++)
		for (j = 0; j < 3; j++)
			arr[i][j] = rand() % 10;
	
	if (isAllOnes(arr, 3) == 0)
		printf("모두 1이 아니다\n");
	else
		printf("모두 1이다.\n");
}