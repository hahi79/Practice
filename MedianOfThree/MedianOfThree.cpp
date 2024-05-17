//==========================================================
//	3値の中央値
//==========================================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
//  関数プロトタイプ
int MedianOfThree(int a, int b, int c);

int main()
{
    srand(time(NULL));
    int a = rand() % 100;
    int b = rand() % 100;
    int c = rand() % 100;
    int ans = MedianOfThree(a, b, c);
    printf("MedianOfThree(%d, %d, %d): %d\n", a, b, c, ans);
    return 0;
}

int MedianOfThree(int a, int b, int c)
{
    if (a >= b) {
        if (b >= c) {
            return b; //【A】【B】【F】【G】
        }
        else if (a <= c) {
            return a; //【D】【E】【H】
        }
        else {
            return c; //【C】
        }
    }
    else if (a > c) {
        return a; //【I】
    }
    else if (b > c) {
        return c; //【J】【K】
    }
    else {
        return b; //【L】【M】
    }
}
