//==========================================================
//	���\��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// �֐��v���g�^�C�v

int main(int argc, char* argv[])
{
	const int TOP = 1;
	const int END = 9;
	int i, j;
	// �ŏ�i�̕\��
	printf("    |");
	for (j = TOP; j <= END; j++) printf("%4d", j);
	printf("\n");
	//  ��؂�̕\��
	printf("----+");
	for (j = TOP; j <= END; j++)printf("----");
	printf("\n");
	//  �\�̕\��
	for (i = TOP; i <= END; i++) {
		printf("%4d|", i);
		for (j = TOP; j <= END; j++) {
			printf("%4d", i * j);
		}
		printf("\n");
	}

	return 0;
}
