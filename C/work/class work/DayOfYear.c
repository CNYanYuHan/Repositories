#include <stdio.h>
void main()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day, sum, i;
    printf("请输入日期（年-月-日）：");
    scanf("%d-%d-%d", &year, &month, &day);
    sum = day;
    for (i = 1; i < month; i++)
        sum = sum + days[i];
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        if (month > 2)
        {
            sum = sum + 1;
        }
    printf("%d年%d月%d日为%d年的第%d天\n", year, month, day, year, sum);
    return 0;
}