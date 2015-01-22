
/*
描述：编写一个函数判断一个机器是大端还是小端表示；

解法：1-把int s 强制转成char* ,再用char * 迭代遍历 int 的地址
      2-判断最低位是否和值的最低位相等 ，若是则是小端，否者，是大端；
*/
#include<stdio.h>
typedef unsigned char * byte_pointer;

void show_byte(byte_pointer start , int len)
{
    int i ;
    for(i = 0 ; i < len ; i++ )
    {
        printf("the int address distribution--> %.2x \n",start[i]); //数组引用指针
        if ( start[0] == 0x8)
        {
            printf("THIS IS LittleEND ! THE FIRST ADDR--> 0x%.2x\n",start[0]);//验证大端还是小端
            break;
        }
    }
    printf("\n");
}
int main()
{
    int s = 8; // 测试用例
    printf("The int address--->0x%.8x\n",s);
    show_byte((byte_pointer)&s , sizeof(s)); //按字节输出内容
    return 0;
}

/*
The answer as follow ----->

The int address--->0x00000008
the int address distribution--> 08
THIS IS LittleEND ! THE FIRST ADDR--> 0x08


Process returned 0 (0x0)   execution time : 0.022 s
Press any key to continue.

*/