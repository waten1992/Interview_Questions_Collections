#include<iostream>
#include<string>
using namespace std;

class Person
{
    int id ;
    char name[100] ;
    public:
            Person() //构造函数不能是虚函数
            {
                cout<<"Create Person Object !"<<endl;
            }
            virtual void AboutMe()
            {
                cout<<"I am a person !"<<endl;
            }
            virtual  ~Person()
            {
                cout<< "Delete a person !"<<endl;
            }
            virtual bool addCourse(string s) = 0;

};

class student : public Person
{
    public:
            student()
            {
                cout<<"Create student Object !"<<endl;
            }

            void AboutMe()
            {
                cout<<"I am a student !"<<endl;
            }
            ~ student()
            {
                cout<<"Deleting a student !"<<endl;
            }
            bool addCourse(string s )
            {
                cout<<"Add course "<<s<<" to student !"<<endl;
                return true;
            }
};
int main()
{
    Person *p = new student();
    p->AboutMe(); //虚继承 基类的指针指向对象，访问派生类对象成员函数 ，实现多态！
    p->addCourse("chemistry");
    delete p ; // 释放内存  虚继承 先删除基类 在删除派生类
    return 0;
}


/*
The Answers as follow-------->
  
Create Person Object !
Create student Object !
I am a student !
Add course chemistry to student !
Deleting a student !
Delete a person !

Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.

*/
