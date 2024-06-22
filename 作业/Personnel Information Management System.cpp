#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
  string name;           // 姓名
  int individualEmpNo;   // 个人编号
  int grade;             // 级别
  double accumPay;       // 月薪总额
  static int employeeNo; // 本公司职员编号目前最大值
public:
  Employee();                       // 构造函数
  virtual ~Employee();              // 析构函数
  virtual void pay() = 0;           // 计算月薪函数
  void promote(int);                // 升级函数
  virtual void displayStatus() = 0; // 显示人员信息
};

int Employee::employeeNo = 1000; // 员工编号基数为1000

Employee::Employee() {
  cout << "请输入本雇员的姓名：";
  cin >> name;
  individualEmpNo = employeeNo++; // 新输入的员工，编号为目前最大编号加1
  grade = 1;                      // 级别初值为1
  accumPay = 0.0;                 // 月薪总额初值为0
}

Employee::~Employee() {}

void Employee::promote(int increment) {
  grade += increment; // 升级，提升的级数由increment指定
}

class Technician : public Employee {
private:
  float hourlyRate; // 每小时酬金
  int workHours;    // 当月工作时数
public:
  Technician();         // 构造函数
  void pay();           // 计算月薪函数
  void displayStatus(); // 显示人员信息
};

Technician::Technician() : hourlyRate(100) {}

void Technician::pay() {
  cout << "请输入" << name << "本月的工作时数：";
  cin >> workHours; // 计算月薪，按小时计酬
  accumPay = hourlyRate * workHours;
  cout << "兼职技术人员" << name << "编号" << individualEmpNo << "本月工资"
       << accumPay << endl;
}

void Technician::displayStatus() {
  cout << "兼职技术人员" << name << "编号" << individualEmpNo << "级别为"
       << grade << "级，已付本月工资" << accumPay << endl;
}

class Salesman : virtual public Employee {
protected:
  double CommRate; // 按销售额提取酬金的百分比
  double sales;    // 当月销售额
public:
  Salesman();           // 构造函数
  void pay();           // 计算月薪函数
  void displayStatus(); // 显示人员信息
};

Salesman::Salesman() : CommRate(0.04) {}

void Salesman::pay() {
  cout << "请输入" << name << "本月的销售额：";
  cin >> sales;
  accumPay = sales * CommRate; // 月薪=销售提成
  cout << "推销员" << name << "编号" << individualEmpNo << "本月工资"
       << accumPay << endl;
}

void Salesman::displayStatus() {
  cout << "推销员" << name << "编号" << individualEmpNo << "级别为" << grade
       << "级，已付本月工资" << accumPay << endl;
}

class Manager : virtual public Employee {
protected:
  float monthlyPay; // 固定月薪数
public:
  Manager();            // 构造函数
  void pay();           // 计算月薪函数
  void displayStatus(); // 显示人员信息
};

Manager::Manager() : monthlyPay(8000) {}

void Manager::pay() {
  accumPay = monthlyPay; // 月薪总额即固定月薪数
  cout << "经理" << name << "编号" << individualEmpNo << "本月工资" << accumPay
       << endl;
}

void Manager::displayStatus() {
  cout << "经理" << name << "编号" << individualEmpNo << "级别为" << grade
       << "级，已付本月工资" << accumPay << endl;
}

class SalesManager : public Manager, public Salesman {
public:
  SalesManager();       // 构造函数
  void pay();           // 计算月薪函数
  void displayStatus(); // 显示人员信息
};

SalesManager::SalesManager() : Manager(), Salesman() {
  monthlyPay = 5000;
  CommRate = 0.005;
}

void SalesManager::pay() {
  cout << "请输入" << name << "所管辖部门本月的总额：";
  cin >> sales;
  accumPay = monthlyPay + CommRate * sales; // 月薪＝固定月薪+销售提成
  cout << "销售经理" << name << "编号" << individualEmpNo << "本月工资"
       << accumPay << endl;
}

void SalesManager::displayStatus() {
  cout << "销售经理" << name << "编号" << individualEmpNo << "级别为" << grade
       << "级，已付本月工资" << accumPay << endl;
}

int main() {
  cout << "这是一个经理：";
  Manager m1;
  m1.promote(3); // 经理提升３级
  m1.pay();
  m1.displayStatus();

  cout << "\n这是一个兼职技术人员：";
  Technician t1;
  t1.promote(2); // t1提升2级
  t1.pay();
  t1.displayStatus();

  return 0;
}
