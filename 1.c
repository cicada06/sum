/*
 * 部分和问题
 * 给定整数a1、a2、.......an，判断是否可以从中选出若干数，使它们的和恰好为K
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d[] = {2, 5, 7, 9};
int n;
int k = 14;
int *flag;

void dfs(int i, int sum)
{
    int j;

    if(sum == k) {
        printf("%d = ", k);
        for(j = 0; j < n; j++) {
            if(flag[j]) {
                printf("%d + ", d[j]);
            }
        }
        printf("\b\b  \n");
    } else if(sum < k) {
        if(i >= n) {
            return;
        }
        flag[i] = 1;
        dfs(i+1, sum+d[i]);
        flag[i] = 0;
        dfs(i+1, sum);
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
