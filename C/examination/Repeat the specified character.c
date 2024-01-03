#include <stdio.h>

void fun(char *s,char c){
int i,j,n;
for(i = 0;s[i] != '\0';i++){
    if(s[i] == c){
        n = 0;
        while(s[i + 1 + n] != '\0') n++;//求出s[i]后还有n个数据。
        for(j = i + n;j >= i;j--){
            s[j + 1] = s[j];
            }    
            i = i + 1;//跳过刚刚插入的字符c
    }
}
}
int main(){
char s[80],c;
gets(s);
scanf("%c",&c);
fun(s,c);
printf("The result is:%s",s);
return 0;
}