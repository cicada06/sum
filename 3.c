#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 10;
int k = 3;
int cnt = 0;
int *flag;

void dfs(int i, int s)
{
    int j;
    int amount;

    if(s == n) {
        amount = 0;
        for(j = 0; j < i; j++) {
            amount += flag[j];  
        }
        if(amount == k) {
            printf("%d: %d = ", ++cnt, n);
            for(j = 0; j < i; j++) {
                if(flag[j]) {
                    printf("%d + ", j+1);
                }
            }
            printf("\b\b  \n");
        }
    } else if(s < n) {
        amount = 0;
        for(j = 0; j < i; j++) {
            amount += flag[j];  
        }
        if(amount >= k) {
            return;
        }
        if(i > n) {
            return;
        }
        flag[i] = 1;
        dfs(i+1, s+i+1);
        flag[i] = 0;
        dfs(i+1, s);
    }
}


int main(void)
{
    flag = (int *)malloc(n * sizeof(int));
    memset(flag, 0, n*sizeof(int));

    dfs(0, 0);
}
