//=====================================
//	3’l‚Ì’†‰›’l
//=====================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
//  ŠÖ”ƒvƒƒgƒ^ƒCƒv
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
            return b; //yAzyBzyFzyGz
        }
        else if (a <= c) {
            return a; //yDzyEzyHz
        }
        else {
            return c; //yCz
        }
    }
    else if (a > c) {
        return a; //yIz
    }
    else if (b > c) {
        return c; //yJzyKz
    }
    else {
        return b; //yLzyMz
    }
}
