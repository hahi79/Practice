//==========================================================
//	1�`N�̑��a�@while��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// �֐��v���g�^�C�v
int SumOfN(int n);
void calcSum(int N);

int main(int argc,char *argv[])
{
	int N;
	if (argc >= 2) {
		sscanf(argv[1],"%d", &N);
		calcSum(N);
	}
	else {
		while (true) {
			printf("n�̒l:");
			scanf("%d", &N);
			calcSum(N);
		}
	}
	return 0;
}
void calcSum(int N)
{
	int sum = SumOfN(N);
	printf("1�`%d�̑��a��%d\n", N, sum);
}


int SumOfN(int n)
{
	int sum = 0;
	int i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	return sum;
}
