//=========================================================
//	配列による文字列
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
#include <string.h> // strlen()

int main()
{
	const int ST_SIZE=8;
	char st[ST_SIZE];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0';
	printf("文字列stには\"%s\"が格納されています\n", st);
	while (true) {
		char input[128];
		printf("文字列:");
		scanf("%s", input);
		int l = strlen(input);
		for (int i = 0; i < l && 5 + i < ST_SIZE; i++) {
			st[5 + i] = input[i];
			printf("st[%d] ='%c'\n", 5 + i, input[i]);
		}
		printf("文字列stには\"%s\"が格納されています\n", st);
	}

	return 0;
}
