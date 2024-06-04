//=========================================================
//	qsortサンプル 文字列
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand(),qsort()
#include <string.h>  // strcmp()
// 関数プロトタイプ
int CompareString(const char a[], const char b[]);
int CompareStringPointer(const char **a, const char **b);

int main()
{
	//  
	//  a[]のメモリー　　　　　　p[]のメモリー
	//  +--+--+--+--+--+--+--+   +------------+
	//  |L |I |S |P |\0|. |. |   |ポインターa |   => "LISP"
	//  |C |\0|. |. |. |. |. |   |ポインターb |   => "C"
	//  |A |d |a |\0|. |. |. |   |ポインターc |   => "Ada"
	//  |P |a |s |c |a |l |\0|   |ポインターd |   => "Pascal"
    //  <----- 7 byte ------->   <--4or8byte-->
	//
	char a[][7] = { "LISP","C","Ada","Pascal" };
	const char* p[] = { "LISP","C","Ada","Pascal" };

	int aSize = sizeof(a) / sizeof(a[0]);
	int pSize = sizeof(p) / sizeof(p[0]);

	qsort(
		a,                   // 配列
		aSize,               // 配列の要素数
		sizeof(a[0]),        // 要素のサイズ
		(int(*)(const void*, const void*))CompareString // 比較関数
	);
	qsort(
		p,             // 配列
		pSize,         // 配列の要素数
		sizeof(p[0]),  // 要素のサイズ
		(int(*)(const void*, const void*))CompareStringPointer // 比較関数
	);
	printf("昇順にソートしました\n");

	printf("a[]:");
	for (int i = 0; i < aSize; i++) {
		printf("%s ", a[i]);
	}
	putchar('\n');

	printf("p[]:");
	for (int i = 0; i < pSize; i++) {
		printf("%s ", p[i]);
	}
	putchar('\n');
	return 0;
}

int CompareString(const char a[], const char b[])
{
	return strcmp(a, b);
}

int CompareStringPointer(const char **a,const char **b)
{
	return strcmp(*a, *b);
}

