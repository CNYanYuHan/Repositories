#include<stdio.h>

typedef struct Birthday{
    int year;
    int month;
    int day;
}Birthday;

typedef struct Student {
    int id;
    char *name;
    int age;
    float score;
    Birthday birthday;
}Student;

void prointStdentInfo(Student *pStu,int len){
    for(int i = 0;i < len;++i){
        printf("学号:%d\t姓名:%s\t年龄:%d\t成绩:%.2f\t生日:%d-%d-%d\n",(pStu+i)->id,(pStu+i)->name,(pStu+i)->age,(pStu+i)->score,(pStu+i)->birthday.year,(pStu+i)->birthday.month,(pStu+i)->birthday.day);
    }
}
int main(){
    Student students[] = {
        {1001,"yyh",18,.100,{2005,10,18}},
        {1001,"ypy",19,83,{2004,11,14}},
        {1001,"yss",17,54,{2006,5,15}}
    };
    prointStdentInfo(students,sizeof(students)/sizeof(students[0]));
    return 0;
    }