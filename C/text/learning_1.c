#include <stdio.h>
int main()
{
    int a, b,i,power=1,sum=0;
    scanf("%d%d",&a,&b);
    for (i = 1; i <= b; i++)
    {
        power *= a;
    }
    printf("%d", power);
    return 0;
}