//=========================================================
//	文字列比較 strncmp互換
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
int str_ncmp(const char* str1,const char *str2,size_t n);

int main()
{
	const char* fixStr = "STRING";
	const int COMPARE_SIZE = 3;
	char str[256];

	while (true) {
		printf("\"%s\"の先頭%d文字と比較します\n",fixStr,COMPARE_SIZE);
		printf("文字列:");
		scanf("%s", str);

		int result = str_ncmp(fixStr, str, COMPARE_SIZE);
		printf("str_ncmp(\"%s\",\"%s\",%d) = %d\n", fixStr, str, COMPARE_SIZE, result);
		putchar('\n');
	}
	return 0;
}

int str_ncmp(const char* str1, const char* str2, size_t n)
{
	while (n > 0 && *str1 != '\0' && *str2 != '\0') {
		unsigned char c1 = *str1;
		unsigned char c2 = *str2;
		if (c1 != c2) {
			return c1 - c2;
		}
		str1++;
		str2++;
		n--;
	}
	if (n == 0) {
		return 0;
	}
	if (*str1 != '\0') {
		return 1;
	}
	else { // *str2!='\0'
		return -1;
	}

}