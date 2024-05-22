//==========================================================
//	素数　改良版2
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
    const int N = 1000;
    unsigned long counter = 0;
    int prime[N/2];
    int primePtr = 0;

    prime[primePtr++] = 2;
    prime[primePtr++] = 3;
    for (int n = 5; n <= N; n += 2) {
        int i;
        bool isPrimeNumber = true;
        for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if (n % prime[i] == 0) {
                isPrimeNumber = false;
                break;
            }
        }
        if (isPrimeNumber) {
            prime[primePtr++] = n;
        }
    }
    for (int i = 0; i < primePtr; i++) {
        printf("%d ", prime[i]);
    }
    printf("\n乗除算を行った回数:%lu\n", counter);
    return 0;
}