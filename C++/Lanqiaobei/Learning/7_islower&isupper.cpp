//isupper和islower函数是C++标准库中的字符分类函数，用于检查一个字符是否为大写字母或者小写字母。islower和isupper函数需要引用头文件<ccytpe>，或万能头。
//toupper(char ch)如果ch是大写字母，则返回ch对应大写字母的ascii码，否则不进行操作。tolower同理。
#include<bits/stdc++.h>
using namespace std;
int main(){
char ch;
cin >> ch;
if(isupper(ch)){
    char ch1 = tolower(ch);
    cout << ch1;
}
else if(islower(ch)){
    char ch2 = toupper(ch);
    cout << ch2;
}
else{
    cout << "error";
}

return 0;
}