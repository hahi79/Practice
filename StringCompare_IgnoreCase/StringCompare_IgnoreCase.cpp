//=========================================================
//	文字列比較 IgnoreCase
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
#include <ctype.h> // toupper(), tolower()

// 関数プロトタイプ
int str_cmp_IgnoreCase(const char* str1, const char* str2);
int str_ncmp_IgnoreCase(const char* str1, const char* str2, size_t n);

int main()
{
	const char* fixStr = "String";
	const int COMPARE_SIZE = 3;
	char str[256];
	int result;

	puts("大文字/小文字を区別しない比較");
	while (true) {
		printf("\"%s\"と比較します\n", fixStr);
		printf("文字列:");
		scanf("%s", str);

		result = str_cmp_IgnoreCase(fixStr, str);
		printf("str_cmp_IgnoreCase(\"%s\",\"%s\") = %d\n", fixStr, str,result);
		putchar('\n');

		printf("\"%s\"の先頭 %d文字と比較します\n", fixStr, COMPARE_SIZE);
		printf("文字列:");
		scanf("%s", str);

		result = str_ncmp_IgnoreCase(fixStr, str, COMPARE_SIZE);
		printf("str_ncmp_IgnoreCase(\"%s\",\"%s\",%d) = %d\n", fixStr, str, COMPARE_SIZE, result);
		putchar('\n');
	}
	return 0;
}

int str_cmp_IgnoreCase(const char* str1, const char* str2)
{
	unsigned char c1;
	unsigned char c2;
	while (true) {
		c1 = toupper(*str1);
		c2 = toupper(*str2);
		if (c1 != c2) {
			break;
		}
		if (c1 =='\0') {
			return 0;
		}
		str1++;
		str2++;
	}
	return c1 - c2;
}

int str_ncmp_IgnoreCase(const char* str1, const char* str2, size_t n)
{
	while (n > 0 && *str1 != '\0' && *str2 != '\0') {
		unsigned char c1 = toupper(*str1);
		unsigned char c2 = toupper(*str2);
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
	else if (*str1!= '\0') {
		return 1;
	}
	else { // *str2!='\0'
		return -1;
	}
}

