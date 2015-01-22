#include <iostream>
using namespace std;

class Demostrate
{
public:
    Demostrate()
    {
        cout << "--->Constructor---" << endl;
    }
    ~Demostrate()
    {
        cout << "++++>Destructor+++" << endl;
    }
};

int main()
{
    const int NUM = 2;

    Demostrate* p1 = new Demostrate[NUM];
    delete p1;  //只是调用一次析构函数；
    cout<<"=====Sepration delete p1 and delete []p1===="<<endl;
    Demostrate* p2 = new Demostrate[NUM];
    delete[] p2; //调用NUM次析构函数；
    return true;
}
/*
The answer as follow---->

--->Constructor---
--->Constructor---
++++>Destructor+++
=====Sepration delete p1 and delete []p1====
--->Constructor---
--->Constructor---
++++>Destructor+++
++++>Destructor+++

Process returned 1 (0x1)   execution time : 0.062 s
Press any key to continue.
--------------------------
解释：1-delete p1 只是调用一次析构函数；
      2-delete []p2 .调用[n]次析构函数；

*/