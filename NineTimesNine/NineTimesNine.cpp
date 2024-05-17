//==========================================================
//	九九表を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// 関数プロトタイプ

int main(int argc, char* argv[])
{
	const int TOP = 1;
	const int END = 9;
	int i, j;
	// 最上段の表示
	printf("    |");
	for (j = TOP; j <= END; j++) printf("%4d", j);
	printf("\n");
	//  区切りの表示
	printf("----+");
	for (j = TOP; j <= END; j++)printf("----");
	printf("\n");
	//  表の表示
	for (i = TOP; i <= END; i++) {
		printf("%4d|", i);
		for (j = TOP; j <= END; j++) {
			printf("%4d", i * j);
		}
		printf("\n");
	}

	return 0;
}
