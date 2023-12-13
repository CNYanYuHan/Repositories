#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n <= 1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    int result =fibonacci(n);
    cout << "Fibonacci number at postion"<< n << " is :" << result << endl;

    return 0;
}