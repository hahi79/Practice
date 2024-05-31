//=========================================================
//	Recur3 非再帰化
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()
#include "IntStack.h"

// 関数プロトタイプ
void recur3(int n);
void recur3_notRecursive(int n);

int main()
{
    while (true) {
        int n;
        do {
            printf("数値:");
            scanf("%d", &n);
        } while (n < 0);

        recur3(n);
        puts("-----------");
        recur3_notRecursive(n);
    }
    return 0;
}

void recur3(int n)
{
    if (n > 0) {
        recur3(n - 1);
        recur3(n - 2);
        printf("%d\n", n);
    }
}

void recur3_notRecursive(int n)
{
    IntStack stk;
    Initialize(&stk, 100);

    int phase = 0;
    while (true) {
        if (n > 0) {
            Push(&stk, n);
            Push(&stk, phase);
            switch (phase) {
            case 0:
                n = n - 1;
                continue;
            case 1:
                n = n - 2;
                phase = 0;
                continue;
            }
        }
        do {
            Pop(&stk, &phase);
            Pop(&stk, &n);
            phase++;
            if (phase == 2) {
                printf("%d\n", n);
                if (IsEmpty(&stk)) {
                    goto End;
                }
            }
        } while (phase == 2);
    }
    End:
    Terminate(&stk);
}
