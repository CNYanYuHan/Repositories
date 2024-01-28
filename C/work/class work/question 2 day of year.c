#include <stdio.h>

int main()
{

    int year, month, day;
    int DaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("请输入：年份 月份 日期");
    scanf("%d,%d,%d", &year, &month, &day);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {

        DaysInMonth[1] = 29;
    }
}