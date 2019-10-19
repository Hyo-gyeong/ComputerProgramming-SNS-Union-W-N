#define NUM_OF_MEMBERS 15
 //나중에 70,100,300,500,1000으로 바꿔서 실행해보기
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//여기서는 함수 정의를 앞부분에 배치한다. 즉 원형은 불필요하다.
void print_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;

	for (i = 0; i < NUM_OF_MEMBERS; i++){
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			printf("%3d", data[i][j]);
		printf("\n");
	}

	return;
}

void matrix_multiplication(int data1[][NUM_OF_MEMBERS], int data2[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS])
{
	int i, j, k;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			for (k = 0; k < NUM_OF_MEMBERS; k ++)
				if (data1[i][k] == 1 && data2[k][j] == 1) {
					result[i][j] = 1; 
					break;
				}
	return;
}

void matrix_copy(int dest[][NUM_OF_MEMBERS], int src[][NUM_OF_MEMBERS])
{
	int i, j;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			dest[i][j] = src[i][j];
	return;
}

int check_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;

	for (j = 0; j < NUM_OF_MEMBERS; j++)
		for (i = 0; i < NUM_OF_MEMBERS; i++)
			if (data[j][i] == 0)
				return 0;
	return 1;

}

int main(void)
{
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};
	int link_data2[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};

	int i = 0, j = 0;
	int num_of_steps = 0;
	int ALL_ONES = 0;
	int count = 0;

	srand((unsigned int)time(NULL));
	//srand(100);
	for (i = 0; i < NUM_OF_MEMBERS; i++)
		link_data[i][i] = 1; // 역 대각선 셀들은 모두 1로 (자신은 자기 자신과 1촌)
	for (i = 0; i < NUM_OF_MEMBERS; i++)
	{
		j = 0;
		while (j < 1)
		{
			int new_link = rand() % NUM_OF_MEMBERS;//0~14
			if (new_link != i)
			{
				link_data[i][new_link] = 1;
				link_data[new_link][i] = 1;
				j++;
			}
		}		
	}
	
	printf("\n초기 1촌 상태: \n");
	print_links(link_data); //사용자가 70명 이상이면 출력이 매끄럽지 않으니 주석문으로 처리한다.
	matrix_copy(link_data2, link_data);
	while(1)
	{
		num_of_steps++;

		matrix_multiplication(link_data, link_data2, link_result);

		printf("\n%d steps:\n", num_of_steps);
		print_links(link_result); //사용자가 70명 이상이면 주석처리

		ALL_ONES = check_links(link_result);
		if (ALL_ONES) 
			break;

		matrix_copy(link_data2, link_result);
	}
	printf("It takes %d steps.\n", num_of_steps);
}

