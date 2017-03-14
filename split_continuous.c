/*
 * 将整数n划分为一系列连续的整数之和即：
 * 15=7+8
 *   =4+5+6
 *   =1+2+3+4
 * 这里我们假设划分之后最小的整数位x ，那么 x+(x+1)+(x+2)......+(x+m)假设一共有i个整数，整理得：
 * x*i+i*(i-1)/2=n
 * i=1,2,3.....其中i的限制条件为：s1=i*(i-1)/2<=n，只有当x为整数时才有可能。
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int s, m;
    int k = 15;
    int i, j;

    for(i = 2; (i-1)*i/2 <= k; i++) {
        s = (k-(i-1)*i/2)/i;
        m = (k-(i-1)*i/2)%i;

        if(!m && (s>0)) {
            printf("%d = ", k);
            for(j = 0; j < i; j++) {
                printf("%d + ", s+j);
            }
            printf("\b\b  \n");
        }
    }

    return 0;
}


