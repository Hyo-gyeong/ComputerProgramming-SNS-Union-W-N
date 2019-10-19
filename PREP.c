#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
#include <stdio.h>
// set �� element �� ������ 1 �� ������ 0 �� ��ȯ�Ѵ�
int hasElement(int set[], int size, int element)
{
	 int i;

	 for( i = 0; i < size; i++)
		if(set[i] == element)
			return HAVE_ELEMENT; // we found it!
	 return DO_NOT_HAVE_ELEMENT;
}
void printSet(int set[], int size)
{
	int i;

	printf("<");
	for (i = 0; i < size - 1; i++)
		printf("%2d,", set[i]);
	printf("%2d >", set[size-1]);	

	return;
}
// set1 �� set2 �� ������ 1 �� �ٸ��� 0 �� ��ȯ
int isSetEqual(int set1[], int size1, int set2[], int size2)
{
	int i;

	for (i = 0; i < size2; i++)
		if(set1[i] != set2[i])
			return DO_NOT_HAVE_ELEMENT;
	return HAVE_ELEMENT;

}
// ���Ұ� ���տ� �������� ������ �߰�, �̹� �����ϸ� redundant ��� ����ϰ� ���� ���� ũ�⸦ ��ȯ
int addOneElement(int set[], int size, int element)
{
	int i;

	for (i = 0; i < size; i++) {
		if ( set[i] == element ) {
			printf("It is redundant. Please retry\n");
			return size;
		}	
	}
	set[size] = element;
	return size+1;

}
int main(void)
{
	int setA[MAX_SET_SIZE] ={1, 2, 3};
	int setB[MAX_SET_SIZE] = {3, 2, 1, 4};
	int num;
	int sizeA = 3, sizeB = 4;

	printf("A:"); printSet(setA, sizeA);
	printf("\nB:"); printSet(setB, sizeB);

	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("\n���� A �� B �� ����\n");
	else
		printf("\n���� A �� B �� �ٸ���\n\n");
	
	printf("A �� 3 �� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 3); // 3 �� SetA �� �߰��Ѵ�
	printf("���� A:"); printSet(setA, sizeA);

	printf("\nA �� 4 �� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 4); // 4 �� SetA �� �߰��Ѵ�
	printf("���� A:"); printSet(setA, sizeA);

	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("\n���� A �� B �� ����\n");
	else
		printf("\n���� A �� B �� �ٸ���\n");
} 