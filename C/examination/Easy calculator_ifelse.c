#include <stdio.h>
int main(){
float a,b;
char c;

scanf("%f%c%f",&a,&c,&b);
if(c == '+'){
    printf("%f",a+b);
}
else if(c == '-'){
    printf("%f",a-b);
}
else if(c == '*'){
    printf("%f",a*b);
}
else if(c == '/'){
    printf("%f",a/b);
}
else printf("Input is error");
}