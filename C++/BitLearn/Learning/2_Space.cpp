#include <iostream>
using namespace std;
int main()
{/*
    printf("hehe\n");
    printf("比特、n");
    printf("%d\n.100");//打印一个整数 - %d
    sizeof - 关键字 - 操作符 - 计算类型或者变量所占空间的大小

    sizeof的单位是什么？ 字节-bytb

    计算机中的单位：
    bit - 比特位（一个比特位存储一个二进制位）
    byte - 字节 = 8bit
    kb = 1024 byte
    mb = 1024 kb
    gb = 1024 mb
    tb =1024 gb
    pb =1024 tb


    计算机中识别二进制
    1
    0
    
*/
printf("%d\'\n",sizeof(char));
printf("%d\n",sizeof(short));
printf("%d\n",sizeof(int));
printf("%d\n",sizeof(long));
printf("%d\n",sizeof(long long));
printf("%d\n",sizeof(float));
printf("%d\n",sizeof(double));

return 0;
}