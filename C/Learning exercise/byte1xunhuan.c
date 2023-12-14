// f(x,y) = x + y
#include <stdio.h>
Add(int x, int y)
{
    int z = x + y;
    return z;
}
int main()
{
    int num1, num2;
    scanf("%d%d", &num1, &num2);

    /*int sum = num1 + num2;*/
    int sum = Add(num1, num2);
    printf("sum = %d\n", sum);

    return 0;
}