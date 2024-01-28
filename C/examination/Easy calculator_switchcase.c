#include<stdio.h>
int main(){
    float a, b;
    char c;
    scanf("%f%c%f",&a,&c,&b);
    switch(c)
    {
    case '+':printf("%f",a+b);break;
    case '-':printf("%f",a-b);break;
    case '*':printf("%f",a*b);break;
    case '/':printf("%f",a/b);break;
    default:printf("Input is error");
    }


}