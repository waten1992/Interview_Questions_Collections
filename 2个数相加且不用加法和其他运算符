/*
描述：写一个函数，2个数相加，但是不能使用加法和其他运算符；

解题方法： 1-用异或 得到二进制相加 但不进位；
           2-用与且移1位 得到的二进制 只进位 但不会相加；
           3-递归调用，直到进位为0 ，到达递归出口；完成任务！！

*/

#include <stdio.h>
int add( int a , int b )
{
	if ( b == 0 )
		return a;
	int sum = a^b ; //just add not move
	int carry = (a&b)<<1 ; // just move not add
	return add(sum , carry); //recursion call , until unmove ;
}

int main()
{
	int a , b , vaule ;
	printf("Please Input two int number:\n");
	scanf("%d %d",&a,&b);
	vaule = add(a,b);
	printf("\nThe Answer :%d",vaule);
	return 0;
}

/*
The Answer as follows ------->

Please Input two int number:
3 4

The Answer :7
Process returned 0 (0x0)   execution time : 2.153 s
Press any key to continue.

*/
