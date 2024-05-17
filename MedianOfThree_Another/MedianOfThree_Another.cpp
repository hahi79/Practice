//==========================================================
//	3値の中央値　別解と速度比較
//==========================================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
//  関数プロトタイプ
int MedianOfThree(int a, int b, int c);
int MedianOfThree_Another1(int a, int b, int c);
int MedianOfThree_Another2(int a, int b, int c);
float MeasureTime(int count, int(*func)(int, int, int));

int main()
{
    const int COUNT = 20000000;
	srand(time(NULL));
    float time1 = MeasureTime(COUNT, MedianOfThree);
    float time2 = MeasureTime(COUNT, MedianOfThree_Another1);
    float time3 = MeasureTime(COUNT, MedianOfThree_Another2);

	printf("MedianOfThree()の時間:%f秒\n", time1);
	printf("MedianOfThree_Another1()の時間:%f秒\n", time2);
    printf("MedianOfThree_Another2()の時間:%f秒\n", time3);
    return 0;
}

float MeasureTime(int count, int(*func)(int, int, int))
{
    clock_t start = clock();
    for (int i = 0; i < count; i++) {
        int a = rand() % 100;
        int b = rand() % 100;
        int c = rand() % 100;
        int ans = func(a, b, c);
    }
    clock_t end = clock();
    float time = (float)(end - start) / CLOCKS_PER_SEC;
    return time;
}
// ListC1-1 のまま
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
// 演習1-5 のまま
int MedianOfThree_Another1(int a, int b, int c)
{
    if ((b >=a && c <= a) || (b <= a && c >= a)) {
        return a;
    }
    else if ((a > b && c < b) || (a < b && c > b)) {
        return b;
    }
    return c;
}
// 演習1-5 を判りやすく修正
int MedianOfThree_Another2(int a, int b, int c)
{
    if ((b <= a && a <= c) || (c <= a && a <= b)) {
        // aが真ん中になる条件は
        // b<=a<=c または c<=a<=b
        return a;
    }
    else if ((a <= b && b <= c) || (c <= b && b <= a)) {
        // bが真ん中になる条件は
        // a<= b<=c または c<=b<=a
        return b;
    }
    // それ以外はc
    return c;
}