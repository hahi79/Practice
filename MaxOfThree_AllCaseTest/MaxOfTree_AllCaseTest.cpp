//================================================
//  3値の最大値 全ケーステスト
//================================================
#include <stdio.h>
// 関数プロトタイプ
int MaxOfThree(int a, int b, int c);


int main()
{
	int value[] = { 1,2,3 };
	int valueSize = sizeof(value) / sizeof(value[0]);
	int i, j, k;
	int a, b, c;
	for (i = 0; i < valueSize; i++) {
		a = value[i];
		for (j = 0; j < valueSize; j++) {
			if (j == i) continue;
			b = value[j];
			for (k = 0; k < valueSize; k++) {
				if (k == i) continue;
				if (k == j) continue;
				c = value[k];
				int ans = MaxOfThree(a, b, c);
				printf("MaxOfThree(%d, %d, %d) => %d\n", a, b, c, ans);
			}
		}
	}
	return 0;
}
int MaxOfThree(int a, int b, int c)
{
	int max = a;
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	return max;
}
