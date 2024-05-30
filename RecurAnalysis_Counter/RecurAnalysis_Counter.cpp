//=========================================================
//	再帰アルゴリズムの解析(カウンター)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <string.h>  // strcpy()
#include <memory.h>  // memset()

// 関数プロトタイプ
void recur_memo(int n);
void reset_memo();
void recur(int n);

static int counter;
static int counter_memo;

int main()
{
    while (true) {
        int n;
        do {
            printf("数値:");
            scanf("%d", &n);
        } while (n < 0);

        counter = 0;
        recur(n);
        printf("recur()の呼び出しは %d 回\n", counter);

        reset_memo();
        counter_memo = 0;
        recur_memo(n);
        printf("recur_memo()の呼び出しは %d 回\n", counter_memo);
    }
    return 0;
}

static char _memo[128][1024] = { 0 };
// memo[-1]も大丈夫
static char(*memo)[1024] = &_memo[1];

//_memo[]を初期化
void reset_memo()
{
    memset(_memo, 0, sizeof(_memo));
}

void recur_memo(int n)
{
    counter_memo++;

    if (memo[n][0] != '\0') {
        printf("%s", memo[n]);
    }
    else {
        if (n > 0) {
            recur_memo(n - 1);
            printf("%d\n", n);
            recur_memo(n - 2);
            sprintf(memo[n], "%s%d\n%s", memo[n - 1], n, memo[n - 2]);
        }
        else {
            strcpy(memo[n], "");
        }
    }
}

void recur(int n)
{
    counter++;

    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}