/*
 * 部分和问题
 * 给定整数a1、a2、.......an，判断是否可以从中选出若干数，使它们的和恰好为K
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d[] = {3, 5, 8};
int m[] = {3, 2, 2};
int n;
int k = 17;
int *flag;
int cnt = 0;

void dfs(int i, int sum)
{
    int j;

    if(sum == k) {
        printf("%d: %d = ", ++cnt, k);
        for(j = 0; j < n; j++) {
            if(flag[j]) {
                printf("%d*%d + ", flag[j], d[j]);
            }
        }
        printf("\b\b  \n");
    } else if(sum < k) {
        if(i >= n) {
            return;
        }
        for(j = 0; j <= m[i]; j++) {
            flag[i] = j;
            dfs(i+1, sum+j*d[i]);
        }
    }
}

int main(int argc, char **argv)
{
    n = sizeof(d)/sizeof(d[0]);

    flag = (int *)malloc(n*sizeof(int));
    memset(flag, 0, n*sizeof(int));

    dfs(0, 0);

    return 0;
}
