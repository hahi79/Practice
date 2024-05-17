//==========================================================
//	a�`b�̑��a
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
#include <stdlib.h> // exit()
// �֐��v���g�^�C�v
int SumOfFromTo(int from,int to);
void calcSum(int a,int b);

int main(int argc, char* argv[])
{
	int a,b;
	if (argc >= 2) {
		sscanf(argv[1], "%d", &a);
		sscanf(argv[2], "%d", &b);
		calcSum(a,b);
	}
	else {
		while (true) {
			printf("a�̒l:");
			scanf("%d", &a);
			printf("b�̒l:");
			scanf("%d", &b);
			calcSum(a,b);
		}
	}
	return 0;
}
void calcSum(int a,int b)
{
	int sum = SumOfFromTo(a,b);
	printf("%d�`%d�̑��a��%d\n", a, b, sum);
}

int SumOfFromTo(int from,int to)
{
	if (from > to) {
		// from>to�̂Ƃ� ����ւ���.
		int tmp = from;
		from = to;
		to = tmp;
	}

	int sum = 0;
	for (int i = from; i <= to; i++) {
		sum += i;
	}
	return sum;
}


int SumOfN_GaussMethod(int n)
{
	int median = (n % 2 != 0) ? (n + 1) / 2 : 0;
	int sum = (1 + n) * (n / 2) + median;
	return sum;
}
