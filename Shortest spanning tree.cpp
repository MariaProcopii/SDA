#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100
int smallestKey(int* mstArr, int* key, int n) {
    int smal = INT_MAX;
    int smal_index = 0;
    for (int i = 0; i < n; i++) {
        if (mstArr[i] == false && key[i] < smal) {
            smal = key[i];
            smal_index = i;
        }
    }
    return smal_index;
}
void smallestMst(int arr[N][N], int n) {
    int key[N];
    int mstArr[N];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstArr[i] = false;
    }
    key[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        int m = smallestKey(mstArr, key, n);
        mstArr[m] = true;
        for (int i = 0; i < n; i++) {
            if (arr[m][i] && mstArr[i] == false && arr[m][i] < key[i]) {
                key[i] = arr[m][i];
            }
        }
    }
    int smal = 0;
    for (int i = 0; i < n; i++) {
        smal += key[i];
    }
    printf("%d", smal);
}
int main()
{
    int i, j, n = 0;
    int arr[N][N];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    smallestMst(arr, n);
    return 0;
}