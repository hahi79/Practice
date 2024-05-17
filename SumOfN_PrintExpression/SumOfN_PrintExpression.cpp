//==========================================================
//	1〜Nの総和　式を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// 関数プロトタイプ
int SumOfN(int n);
void calcSum(int N);

int main(int argc, char* argv[])
{
	int N;
	if (argc >= 2) {
		sscanf(argv[1], "%d", &N);
		calcSum(N);
	}
	else {
		while (true) {
			printf("nの値:");
			scanf("%d", &N);
			calcSum(N);
		}
	}
	return 0;
}
void calcSum(int N)
{
	int sum = SumOfN(N);

	for (int i = 1; i <= N; i++) {
		char op = i != N ? '+' : '=';
		printf("%d %c ", i, op);
	}
	printf("%d\n", sum);
}


int SumOfN(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}
