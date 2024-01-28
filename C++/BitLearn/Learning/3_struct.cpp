#include<bits/stdc++.h>
using namespace std;
struct employee{
    char name[12];
    char addr[40];
    long zip;
    long tel;
};
int main(){
    struct employee teacher = {"liming","blue",333456,464556};
    cout<<teacher.addr<<teacher.name<<teacher.tel<<teacher.zip<<endl;
return 0;
}