#include <stdio.h>
int main()
{
    int line = 0;
    while(line < 100)
    {
        printf("好好写代码%d\n",line);
        line++;
    }
    if(line == 100)
    {
        printf("恭喜您获得好OFFER");
    }

    return 0;
}