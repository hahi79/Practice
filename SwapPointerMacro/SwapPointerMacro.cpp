//=========================================================
//	ポインターの交換マクロ
//=========================================================
#include <stdio.h> // printf()
// マクロ定義
#define swap_ptr(type,x,y)	do{type*tmp=x; x=y; y=tmp;}while(false)

int main()
{
	const char* s1 = "ABCD";
	const char* s2 = "EFGH";

	printf("ポインタs1は\"%s\"を指しています\n", s1);
	printf("ポインタs2は\"%s\"を指しています\n", s2);

	swap_ptr(const char, s1, s2);
	puts("\nポインタs1とs2の値を交換しました");

	printf("ポインタs1は\"%s\"を指しています\n", s1);
	printf("ポインタs2は\"%s\"を指しています\n", s2);
	return 0;
}
