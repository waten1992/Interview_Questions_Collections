/*
  描述：总共有N 阶梯 ， 有人向上爬  ，一次只能爬 1 或者 2 阶 ； 求最多有多少种方法？ 
  解法： 通过归纳有递推公式  F(n) = F(n-1) + F(n-2) ;
  当N = 1 ----1                      --->1种
    N = 2 ----11 、2                 --->2种
    N = 3 ----111 12 21              --->3种  = 2 + 1 
    N = 4 ----1111 112 121 211 22    --->5种  = 3 + 2 
    -----接下来你懂的
    
  EXAMPLE:
           Input : 5
          Output : 8
*/
 
#include <iostream>
using namespace std;
 
#if 0
// 爬楼梯 归纳  F(n) = F(n-1) + F(n-2) ; 迭代实现
int Climb_Stairs(int n)
{
    int f0 , f1 , f2 ;
    f0 = 1 ;
    f1 = 2 ;
    if ( n == 1 ) //排出为 1 的时候
        return 1;
    if ( n == 2 ) //排出为 2 的时候
        return 2 ;
    while ( n > 2 ) //开始迭代
    {
        f2 = f0 + f1 ;
        f0 = f1 ;
        f1 = f2 ;
        n--;
    }
    return f2;
}
 
int main()
{
    int n ;
    cout<<"Please Input A Number :";
    cin>>n ;
    cout<<"The Answer is :"<<Climb_Stairs(n)<<endl;
    return 1;
}
#endif
/*
 
  结果：
        Please Input A Number :5
        The Answer is :8
 
*/


/*
  动态规划-------->至顶向下方案
*/
#if 1
int fib_array[50] = {0}; //至顶向下 用一个数组记录已经计算出来的值
int Mem_fib(int n)
{
    int t ;
    if ( fib_array[n] != 0 )
        return fib_array[n];
    if ( n == 1 )
        t = 1 ;
    if ( n == 2 )
        t = 2 ;
    if ( n > 1 )
    {
        t = Mem_fib(n-1) + Mem_fib(n-2) ;
    }
    return fib_array[n] = t;
}

int main()
{
    int n ;
    cout<<"Please Input A Number :";
    cin>>n ;
    cout<<"The Answer is :"<<Mem_fib(n)<<endl;
    return 1;
}
#endif 

/*
  The Answer as follow ---------->
            
            Please Input A Number :5
            The Answer is :8

            Process returned 0 (0x0)   execution time : 2.180 s
            Press any key to continue.

*/
