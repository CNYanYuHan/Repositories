#include <bits/stdc++.h>
using namespace std;
class Father{
    public:
    int n = 1;
    virtual void func(){cout << "F" << get_n();}
    int get_n(){return n;}
};
class Son : public Father{
    public:
    int n = 2;
    void func(){cout << "S" << get_n();}
};

int main(){
    Son obj;
    Father* p1=&obj;
    Son*p2=&obj;
    obj.func();
    p1->func();
    p2->func();


}