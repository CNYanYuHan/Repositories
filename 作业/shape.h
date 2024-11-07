#include "string.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

/********Begin*****/
// 允许在Begin
// -End之间任何位置添加代码，允许在现有代码（包括类的定义）中添加内容，但不允许删除或替换现有代码
class Animal {
public:
  Animal(string name = "Animal",int age = 0); //缺省构造函数,默认名字为Animal，年龄为0
  void move();         // 空操作，仅供继承
  void shout();        // 空操作，仅供继承
  string getName() { return name; }         //返回name
  void setName(string s) { name = s; }      // 给name赋值
  int getAge() { return age; }              // 返回age
  static int getNum() { return animalNum; } // 返回各种类型动物总数

protected:
  string name; //名字

private:
  int age;              //年龄
  static int animalNum; //记录各种类型动物对象的总数
};

class Dog : public Animal {
public:
  Dog(string =
          "Dog"); // 缺省构造函数，默认名字为Dog，年龄为当前Dog对象的总数（含自己）
  void move();    // 输出 "run X feet! "  其中X为 5+0.1*age
  void
  shout(); // 输出"wang wang, It is XX age #"  其中XX为自己的name, #为自己的age
  static int getNum() { return dogNum; } //返回Dog总数
private:
  static int dogNum; //记录Dog对象的总数
};

class Frog : public Animal {
public:
  Frog(
      string name ="Frog"); // 缺省构造函数，默认名字为Frog，年龄为当前Frog对象的总数（含自己）
  void move();     // 输出 "jump X feet! "  其中X为 1+0.1*age
  void shout(); // 输出"gua gau, It is XX age #"  其中XX为自己的name, #为自己的age
  int getNum() { return frogNum; }
private:
  static int frogNum; //记录Frog对象的总数
};

class Bird : public Animal {
public:
  Bird(
      string name =
          "Bird"); // 缺省构造函数，默认名字为Bird，年龄为当前Bird对象的总数（含自己）
  void move();     // 输出 "fly X feet! "  其中X为 10+0.1*age
  void shout(); // 输出"qiu qiu, It is XX age #"  其中XX为自己的name, #为自己的age
  int getNum() { return birdNum; } //返回Bird对象的总数
private:
  static int birdNum; //记录Bird对象的总数
};
// 你可以在此处补充必要的代码，以实现上述类中定义的功能

// 初始化静态成员变量
int Animal::animalNum = 0;
int Dog::dogNum = 0;
int Frog::frogNum = 0;
int Bird::birdNum = 0;

// 类成员函数定义
Animal::Animal(string name, int age) : name(name), age(age) { animalNum++; }

Dog::Dog(string name) : Animal(name, rand() % 10 + 1) { dogNum++; }

Frog::Frog(string name) : Animal(name, rand() % 10 + 1) { frogNum++; }

Bird::Bird(string name) : Animal(name, rand() % 10 + 1) { birdNum++; }

void Animal::move() {
  // do nothing
}

void Animal::shout() {
  // do nothing
}

void Dog::move() { cout << "run " << 5 + 0.1 * getAge() << " feet! " << endl; }

void Dog::shout() {
  cout << "wang wang, It is " << getName() << " age " << getAge() << endl;
}

void Frog::move() {
  cout << "jump " << 1 + 0.1 * getAge() << " feet! " << endl;
}

void Frog::shout() {
  cout << "gua gau, It is " << getName() << " age " << getAge() << endl;
}

void Bird::move() {
  cout << "fly " << 10 + 0.1 * getAge() << " feet! " << endl;
}

void Bird::shout() {
  cout << "qiu qiu, It is " << getName() << " age " << getAge() << endl;
}

/*******End**********/

//  以下代码不需要做任何改动，但你可以阅读并学习如何实现应用程序的功能，包括如何编写通用的showAnimal函数
void showAnimal(Animal *pa) {
  pa->move();
  pa->shout();
}

int main() {
  // 动物园中有10只dog,5只frog，15只bird
  Dog dogList[10];
  Frog frogList[5];
  Bird birdList[15];

  Animal
      *animalList[10]; // animal类型的指针数组，用于存放随机挑选出的动物的地址

  int seeds;
  cin >> seeds;
  srand(seeds); // 随机数种子

  int totalnum = Animal::getNum();
  cout << "There are " << totalnum << " animals in the zoo" << endl;
  cout << Dog::getNum() << " dogs, " << Frog::getNum() << " frogs, "
       << Bird::getNum() << " birds\n\n";

  // 随机挑选10只动物, 将其地址放入animalList指针数组
  for (int i = 0; i < 10; i++) {
    int n = rand() % (Animal::getNum()); //随机生成动物ID
    if (n < Dog::getNum())
      animalList[i] = dogList + n;
    else if (n < Dog::getNum() + Frog::getNum())
      animalList[i] = frogList + (n - Dog::getNum());
    else
      animalList[i] = birdList + (n - Dog::getNum() - Frog::getNum());
  }

  cout << "Let's study!" << endl;

  //用前5只动物让小朋友学习
  for (int i = 0; i < 5; i++) {
    showAnimal(animalList[i]);
  }

  // 用后5只动物来测试，为了达到测试效果，先将他们的名字统一改为animal,
  // 再开始测试
  for (int i = 5; i < 10; i++) {
    animalList[i]->setName("Animal");
  }

  cout << "\nLet's have a test!" << endl << endl;
  int score = 0;
  // 开始测试，依次显示后5只动物，让小朋友猜
  for (int i = 5; i < 10; i++) {
    showAnimal(animalList[i]); //显示
    cout << "Guess! What type of animal is It?" << endl;
    char ns[10];

    cin >> ns; //让小朋友回答动物类型  Dog Frog 或者Bird

    if (strstr(typeid(*animalList[i]).name(), ns)) {
      cout << "You are right!\n" << endl;
      score += 20;
    } else
      cout << "You are wrong!\n" << endl;
  }
  cout << "Your score: " << score << endl;

  return 0;
}
