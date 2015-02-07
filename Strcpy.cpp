/*
  描述： 编写一个原型为char * Strcpy(char * Dest , const char * Src) 函数；

  需要考虑的问题： 
                  1-传进来的值是否为NULL;
                  2-src and  dest 指向的地址是否为相同，若是则返回；
                  3-设定2个指针 分别指向src and dest , 用while() 循环赋值 直到NULL，退出返回dest的首地址；
                  4-不能防止缓冲溢出，故要设置strlen(dest) >= strlen(src);
*/
#include <iostream>
#include <assert.h>
using namespace std;
char * Strcpy(char * Dest , const char * Src)
{
    char * Tmp_Dest = Dest ;
    const char * Tmp_Src = Src ;

    assert((Dest != NULL) && (Src != NULL));
    if (Dest == Src)
        return Dest ;
    while( (*Tmp_Dest++ = *Tmp_Src++) != NULL)
            ;
    return Dest;
}

int main()
{
    const char * src = "www.orderbf.com";
    char * dest = new char[30];
    Strcpy(dest , src);
    cout<<"This is ---> "<< dest<<endl;
    delete []dest;
    return 0;
}
/*
The answer as follow--->
This is ---> www.orderbf.com

Process returned 0 (0x0)   execution time : 0.027 s
Press any key to continue.

*/