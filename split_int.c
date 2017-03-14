/*
 * 定义 f(n,m)为将整数n划分为一系列整数之和，其中加数
 * 最大不超过m。
 * 得到下面的递推关系式：
 *  当n==1 || m==1 只有一种划分，即 1 或者 1+1+1......+1
 *  当m>n 显然，等价于 f(n,n)
 *  当m==n 此时：我考虑加数包含m与否的两种情况：
 *  1）划分不包含m，即f(n,m-1)---所有m-1的划分
 *  2)划分包含 m，此时只有一种即 m
 *  所以当m==n时，有 f(n,m)=f(n,m-1)+1
 *  当m<n时，
 *  1）包含m时，{m,x1,x2,x3....xi}此时 等价于 f(n-m,m)
 *  2）不包含m时，显然f(n,m-1)
 *  所以f(n,m)=f(n,m-1)+f(n-m,m)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split_recursive(int n, int m)
{
    if((n < 1)||(m < 1)) {
        return -1;
    }

    if(n==1 || m==1) {
        return 1;
    }

    if(n <= m) {
        return split_recursive(n, n-1)+1;
    } else {
        return split_recursive(n,m-1)+split_recursive(n-m,m);
    }
}

int split_dp(int n, int m)
{
    static int *r;
    static int flag = 0;
    static int width;

    if(!flag) {
        r = (int *)malloc(n * m * sizeof(int));
        width = m;
        memset(r, -1, n*m*sizeof(int));
    }

    if((n < 1)||(m < 1)) {
        return -1;
    }

    if(n==1 || m==1) {
        *(r+(n-1)*width+(m-1)) = 1;
        return 1;
    }

    if(n <= m) {
        if(*(r+(n-1)*width+(n-1)) == -1) {
            *(r+(n-1)*width+(n-1)) = split_recursive(n, n-1)+1;
        }
        return *(r+(n-1)*width+(n-1));
    } else {
        if(*(r+(n-1)*width+(m-1)) == -1) {
            *(r+(n-1)*width+(m-1)) = split_recursive(n,m-1)+split_recursive(n-m,m);
        }
        return *(r+(n-1)*width+(m-1));
    }
}

int main(void)
{
    int n = 4;
    int m = 4;
    //printf("split(%d, %d) = %d\n", n, m, split_recursive(n, m));
    printf("split(%d, %d) = %d\n", n, m, split_dp(n, m));
    return 0;
}
