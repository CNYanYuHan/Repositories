# Question

定义Boat与Car两个类，二者都有weight属性（int 类型，private访问控制），有一个带参数的构造函数，定义二者的一个友元函数getTotalWeight(),计算并返回二者的重量。在main()函数中进行测试。
样例输入：
10 20
样例输出：
30

# Answer

```cpp
#include <iostream>

class Car;  // forward declaration

class Boat {
private:
    int weight;

public:
    Boat(int w) : weight(w) {}
    friend int getTotalWeight(Boat b, Car c);
};

class Car {
private:
    int weight;

public:
    Car(int w) : weight(w) {}
    friend int getTotalWeight(Boat b, Car c);
};

int getTotalWeight(Boat b, Car c) {
    return b.weight + c.weight;
}

int main() {
    int boatWeight, carWeight;
    std::cin >> boatWeight >> carWeight;

    Boat myBoat(boatWeight);
    Car myCar(carWeight);

    std::cout << getTotalWeight(myBoat, myCar) << std::endl;

    return 0;
}
```
```plaintext
输入：
10 20
输出：
30
```