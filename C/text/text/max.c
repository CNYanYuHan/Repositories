#include "stdio.h"
int fun(int n, int k)
{
    int power, sum = 0;
    int i, j;
    
    for (i = 1; i <= n; i++)
    {
        power = 1;
        for (j = 1; j <= k; j++)
        {
            power *= i;
        }
        
        printf("%d的%d次方=%d\n", i, k, power);
        sum += power;
    }
    return sum;
}
int main()
{
    int n, k, sum;
    scanf("%d%d", &n, &k);
    sum = fun(n, k);
    printf("The Sum is=%d", sum);
}