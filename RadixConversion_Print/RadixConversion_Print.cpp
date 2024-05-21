//==========================================================
//	基数変換 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int card_convert(char* buff, int num, int radix);
// 関数マクロ
#define SWAP(type, x, y) do{ type tmp=x; x=y; y=tmp; }while(false)

int main()
{
    srand(time(NULL));
    const int BUFF_SIZE = 128;
    char buff[BUFF_SIZE];
    int yes;
    do {
        int num = rand();
        int radix = rand() % 34 + 2;  // radix=2〜36
        card_convert(buff, num, radix);

        printf("%d を基数%3d で表示すると %s\n", num, radix, buff);

        printf("\nもう一度しますか?(1:はい/0:いいえ)");
        scanf("%d", &yes);
    } while (yes==1);
    return 0;
}

int card_convert(char* buff, int num, int radix)
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    if (num == 0) {
        buff[digits++] = dchar[0];
    }
    else
    {
        while (num != 0) {
            printf("%3d|%6d   ...%3d\n",radix,num,num%radix);
            printf("   +---------\n");

            buff[digits++] = dchar[num % radix];
            num /= radix;
        }
        printf("    %6d\n", num);
    }
    for (int i = 0; i < digits / 2; i++) {
        SWAP(char, buff[i], buff[digits - 1 - i]);
    }
    buff[digits] = '\0';
    return digits;
}
