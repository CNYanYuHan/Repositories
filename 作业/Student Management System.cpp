#include <iostream>
#include <numeric> // for std::accumulate
#include <string>
#include <vector>

using namespace std;

#define MAX 60

enum Gender { MALE, FEMALE };

struct Date {
  int year;
  int month;
  int day;
};

struct Student {
  string name;
  int age;
  int id;
  Gender sex;
  Date birthDate;
  vector<double> scores; // 各科成绩
  double averageScore;   // 平均成绩
};

struct ClassRoom {
  Student st[MAX];
  int n; // 当前班级的人数
};

void printMenu() {
  cout << "        学生管理系统        " << endl;
  cout << "----------------------------" << endl;
  cout << "|1、添加学生信息            |" << endl;
  cout << "|2、显示所有学生信息        |" << endl;
  cout << "|3、查询学生信息            |" << endl;
  cout << "|4、删除学生信息            |" << endl;
  cout << "|5、修改学生信息            |" << endl;
  cout << "|6、退出                    |" << endl;
  cout << "----------------------------" << endl;
  cout << "请输入相应的序号选择!       " << endl;
}

void addStudent(ClassRoom &cr) {
  if (cr.n >= MAX) {
    cout << "班级已满，无法添加更多学生。" << endl;
    return;
  }
  cout << "请输入学生的姓名：" << endl;
  cin >> cr.st[cr.n].name;
  cout << "请输入学生的年龄：" << endl;
  cin >> cr.st[cr.n].age;
  while (cr.st[cr.n].age < 0) {
    cout << "年龄不能为负，请重新输入：" << endl;
    cin >> cr.st[cr.n].age;
  }
  cout << "请输入学生的id：" << endl;
  cin >> cr.st[cr.n].id;
  while (cr.st[cr.n].id < 0) {
    cout << "ID不能为负，请重新输入：" << endl;
    cin >> cr.st[cr.n].id;
  }
  cout << "请输入学生的性别 (0 for male, 1 for female): " << endl;
  int gender;
  cin >> gender;
  while (gender != MALE && gender != FEMALE) {
    cout << "无效的性别输入，请重新输入 (0 for male, 1 for female): " << endl;
    cin >> gender;
  }
  cr.st[cr.n].sex = static_cast<Gender>(gender);

  cout << "请输入学生的出生日期 (yyyy mm dd): " << endl;
  cin >> cr.st[cr.n].birthDate.year >> cr.st[cr.n].birthDate.month >>
      cr.st[cr.n].birthDate.day;

  cr.st[cr.n].scores.resize(10);
  double totalScore = 0.0;
  for (int i = 0; i < 10; ++i) {
    cout << "请输入第 " << i + 1 << " 门课的成绩: " << endl;
    cin >> cr.st[cr.n].scores[i];
    while (cr.st[cr.n].scores[i] < 0 || cr.st[cr.n].scores[i] > 100) {
      cout << "成绩必须在0到100之间，请重新输入: " << endl;
      cin >> cr.st[cr.n].scores[i];
    }
    totalScore += cr.st[cr.n].scores[i];
  }
  cr.st[cr.n].averageScore = totalScore / 10;

  cr.n++;
}

void showStudent(const ClassRoom &cr) {
  for (int i = 0; i < cr.n; i++) {
    cout << "the " << i + 1 << " student name is " << cr.st[i].name << endl;
    cout << "the " << i + 1 << " student age is " << cr.st[i].age << endl;
    cout << "the " << i + 1 << " student id is " << cr.st[i].id << endl;
    cout << "the " << i + 1 << " student sex is "
         << (cr.st[i].sex == MALE ? "Male" : "Female") << endl;
    cout << "the " << i + 1 << " student birth date is "
         << cr.st[i].birthDate.year << "-" << cr.st[i].birthDate.month << "-"
         << cr.st[i].birthDate.day << endl;
    cout << "the " << i + 1 << " student scores are: ";
    for (double score : cr.st[i].scores) {
      cout << score << " ";
    }
    cout << endl;
    cout << "the " << i + 1 << " student average score is "
         << cr.st[i].averageScore << endl;
  }
}

int findStudent(const ClassRoom &cr) {
  int id;
  cout << "请输入要查找的学生id：" << endl;
  cin >> id;

  for (int i = 0; i < cr.n; i++) {
    if (id == cr.st[i].id) {
      cout << "the student is exist!" << endl;
      cout << "the " << i + 1 << " student name is " << cr.st[i].name << endl;
      cout << "the " << i + 1 << " student age is " << cr.st[i].age << endl;
      cout << "the " << i + 1 << " student id is " << cr.st[i].id << endl;
      cout << "the " << i + 1 << " student sex is "
           << (cr.st[i].sex == MALE ? "Male" : "Female") << endl;
      cout << "the " << i + 1 << " student birth date is "
           << cr.st[i].birthDate.year << "-" << cr.st[i].birthDate.month << "-"
           << cr.st[i].birthDate.day << endl;
      cout << "the " << i + 1 << " student scores are: ";
      for (double score : cr.st[i].scores) {
        cout << score << " ";
      }
      cout << endl;
      cout << "the " << i + 1 << " student average score is "
           << cr.st[i].averageScore << endl;
      return i;
    }
  }
  cout << "the student is not exist!" << endl;
  return -1;
}

void removeStudent(ClassRoom &cr) {
  int ret = findStudent(cr);

  if (ret != -1) {
    for (int i = ret; i < cr.n - 1; i++) {
      cr.st[i] = cr.st[i + 1];
    }
    cr.n--;
  }
  cout << "该学生已经删除成功！" << endl;
}

void changeStudent(ClassRoom &cr) {
  int ret = findStudent(cr);
  if (ret != -1) {
    int choose;
    bool done = false;
    while (!done) {
      cout << "修改学生信息的哪一项？" << endl;
      cout << "1、姓名" << endl;
      cout << "2、年龄" << endl;
      cout << "3、id" << endl;
      cout << "4、性别" << endl;
      cout << "5、出生日期" << endl;
      cout << "6、各科成绩" << endl;
      cout << "7、退出修改" << endl;
      cin >> choose;

      switch (choose) {
      case 1:
        cout << "请输入新的学生姓名：" << endl;
        cin >> cr.st[ret].name;
        break;
      case 2:
        cout << "请输入新的学生年龄：" << endl;
        cin >> cr.st[ret].age;
        while (cr.st[ret].age < 0) {
          cout << "年龄不能为负，请重新输入：" << endl;
          cin >> cr.st[ret].age;
        }
        break;
      case 3:
        cout << "请输入新的学生id：" << endl;
        cin >> cr.st[ret].id;
        while (cr.st[ret].id < 0) {
          cout << "ID不能为负，请重新输入：" << endl;
          cin >> cr.st[ret].id;
        }
        break;
      case 4:
        cout << "请输入新的学生性别 (0 for male, 1 for female): " << endl;
        int gender;
        cin >> gender;
        while (gender != MALE && gender != FEMALE) {
          cout << "无效的性别输入，请重新输入 (0 for male, 1 for female): "
               << endl;
          cin >> gender;
        }
        cr.st[ret].sex = static_cast<Gender>(gender);
        break;
      case 5:
        cout << "请输入新的学生出生日期 (yyyy mm dd): " << endl;
        cin >> cr.st[ret].birthDate.year >> cr.st[ret].birthDate.month >>
            cr.st[ret].birthDate.day;
        break;
      case 6: {
        double totalScore = 0.0;
        for (int i = 0; i < 10; ++i) {
          cout << "请输入第 " << i + 1 << " 门课的新成绩: " << endl;
          cin >> cr.st[ret].scores[i];
          while (cr.st[ret].scores[i] < 0 || cr.st[ret].scores[i] > 100) {
            cout << "成绩必须在0到100之间，请重新输入: " << endl;
            cin >> cr.st[ret].scores[i];
          }
          totalScore += cr.st[ret].scores[i];
        }
        cr.st[ret].averageScore = totalScore / 10;
        break;
      }
      case 7:
        done = true;
        break;
      default:
        cout << "输出错误，请重新输入！" << endl;
      }
    }
  }
}

int main() {
  ClassRoom cr;
  cr.n = 0;

  while (true) {
    printMenu();
    int choose;
    cin >> choose;

    switch (choose) {
    case 1:
      addStudent(cr);
      break;
    case 2:
      showStudent(cr);
      break;
    case 3:
      findStudent(cr);
      break;
    case 4:
      removeStudent(cr);
      break;
    case 5:
      changeStudent(cr);
      break;
    case 6:
      return 0;
    default:
      cout << "输出错误，请重新输入！" << endl;
    }
  }
}
