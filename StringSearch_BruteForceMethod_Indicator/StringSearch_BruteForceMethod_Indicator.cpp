//=========================================================
//	������T���@�͂܂����@ �o�ߕ\��
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// �֐��v���g�^�C�v
int bf_match(const char* txt, const char* pat);
void Indicate(const char* txt, const char* pat, int cmpStart, int pt, int pp);

const int NOT_FOUND = -1;

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("�͂܂����@");
		printf("�e�L�X�g:");
		scanf("%s", str1);

		printf("�p�^�[��:");
		scanf("%s", str2);

		int idx = bf_match(str1, str2);
		if (idx == NOT_FOUND) {
			puts("�e�L�X�g���Ƀp�^�[���͑��݂��܂���");
		}
		else {
			printf("%d�����ڂɃ}�b�`���܂���\n", idx + 1);
		}
		putchar('\n');
	}
	return 0;
}

int bf_match(const char* txt, const char* pat)
{
	int cmpStart = 0;
	int pt = cmpStart;
	int pp = 0;
	int pStart = pt;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		Indicate(txt, pat, cmpStart, pt, pp);
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			cmpStart++;
			pt = cmpStart;
			pp = 0;
		}
	}
	if (pat[pp] == '\0') {
		return cmpStart;
	}
	return NOT_FOUND;
}

void Indicate(const char* txt, const char* pat, int cmpStart, int pt, int pp)
{
	printf("%s\n", txt);
	char mark = txt[pt] == pat[pp] ? '+' : '|';
	printf("%*s%c\n", pt, "", mark);
	printf("%*s%s\n", cmpStart, "", pat);
	putchar('\n');
}