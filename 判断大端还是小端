#include<stdio.h>
typedef unsigned char * byte_pointer;

void show_byte(byte_pointer start , int len)
{
    int i ;
    for(i = 0 ; i < len ; i++ )
       {
           printf("%.2x ",start[i]); //数组引用指针
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
    show_byte((byte_pointer)&s , sizeof(s)); //按字节输出内容
return 0;
}
