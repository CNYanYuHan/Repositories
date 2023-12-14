#include <stdio.h>

int main()
{
    int line = 0;
    while (line < 30)
    {
        printf("写代码：%d\n", line);
        line++;
    }
    if (line == 30)
    {
        printf("好offer");
    }
    return 0;
}
