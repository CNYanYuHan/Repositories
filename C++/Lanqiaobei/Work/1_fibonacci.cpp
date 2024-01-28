#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =1e5 + 9;
const ll p = 1e9 + 7;

//带备忘录的递归
ll dp[N];

ll fib(int n)
{
    if(dp[n])return dp[n];
    if(n <= 2)return 1;
    return dp[n] = (fib(n - 1) + fib(n - 2)) % p;
}
int main()
{
    int n;cin >> n;
    for(int i = 1;i <= n ;i++){
        cout << fib(i) <<'\n';
    }
    return 0;
}
// 这段代码实现了使用带备忘录的递归方法计算斐波那契数列的前n项，并输出结果。下面是对代码的详细解析：

//     1. `#include<bits /stdc++.h>`：这是一个常见的包含头文件，它包含了几乎所有STL库的内容。这样做是为了方便，因为这样就不需要单独包含每个STL库。

//     2. `using namespace std;
// `：使用`std`命名空间，这样就可以直接使用`cin`、`cout`等标准输入输出流，以及其他标准库中的函数和对象，而不需要加上`std::`前缀。

//     3. `using ll = long long;
// `：定义了`ll`为`long long`类型的别名，这样在代码中就可以使用`ll`代替`long long`类型。

//     4. `const int N = 1e5 + 9;
// `：定义了常量`N`，表示斐波那契数列的长度上限。

//     5. `const ll p = 1e9 + 7;
// `：定义了常量`p`，表示取模的值。

//     6. `ll dp[N];
// `：定义了一个数组`dp`，用于存储斐波那契数列的中间结果，以实现备忘录功能。

//     7. `ll
//     fib(int n)`：定义了一个函数`fib`，用于计算第`n`个斐波那契数。如果`dp
//         [n]`不为0，表示已经计算过第`n`个斐波那契数，直接返回`dp
//             [n]`的值。如果`n`小于等于2，直接返回1。否则，递归计算第`n`个斐波那契数，并将结果存储在`dp
//                 [n]`中，然后返回结果对`p`取模的值。

//     8. `int main()`：定义了主函数。

//     9. `int n;
// cin >> n;
// `：从标准输入流中读入一个整数`n`，表示要计算斐波那契数列的前`n`项。

//     10. `for (int i = 1; i <= n;
//               i++)`：循环`i`从1到`n`，计算并输出前`n`项的斐波那契数列。

//     11. `cout
//     << fib(i) << '\n';
// `：调用`fib`函数计算第`i`个斐波那契数，并将结果输出到标准输出流，每个结果占一行。

//     12. `return 0;
// `：返回0，表示程序正常结束。

//     这段代码使用了递归方法计算斐波那契数列，并通过备忘录技术避免了重复计算，提高了效率。
