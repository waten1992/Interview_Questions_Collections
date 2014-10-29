/*
--描述：A 字符串 “hello world”  ， B 字符串 "er" ,默认都是小写字母 ， 要求写一个函数在A中除去B字符，返回A
--INPUT: hello world , er
--OUTPUT:hllowold
--要求空间复杂度为O(1),时间复杂度越低越好；
----方法：1-先对A HASH 到 一个临时int变量check中，相应位置1
----------2-在对B HASH 的相应的位和check相与 ，把A置1的清零
----------3-扫描A串 同时HASH 和check相与，判断是否为零，若是直接跳过. 若不是则赋值给一个临时串保存；
----------4-把A串的指针，指向临时串。同时return A串的指针；
*/

#include <iostream>
using namespace std;

void Print_Binary_Num(int Num) //输出二进制 ， 按照小端序列输出
{
    int i = 32 ;
    while(i)
    {
        cout<<(Num&0X1); //总是输出第一个数
        Num = Num>>1; //不断的右移
        i--;
        if (i%4 == 0)
            cout<<'\t';
    }
}

char * Handler(char *s1 , char *s2)
{
    int  i = 0 , Tmp = 0 , check = 0 , index = 0;
    char *Tmp_String = new char [10]; //临时数组
    while (s1[i]) //HASH --- A 相应的位置1
    {
        Tmp = (s1[i] - 'a') % 32 ; // HASH

        if (Tmp >= 0 && Tmp <=25) //排出其他字符
            check = (1<<Tmp)|check;
#if 0
        cout<<"-----"<<check<<endl;
        Print_Binary_Num(check);
#endif
        i++;
    }
    i = 0; //再次初始化
    while (s2[i]) //HASH ---B ----把A 和 B中都存在的字符 都置0
    {
        Tmp = (s2[i] - 'a') % 32 ;

        if (Tmp >= 0 && Tmp <=25) //排出其他字符
            check = (~(1<<Tmp))&check;//---1 两种方式都可以，都是把相应的为清零 ； 推荐用第一种
          //check = (1<<Tmp)^check;  //----2 但是第二种有副作用，假若A不存在,而B存在；
                                    // 则check的相应位被置1，不过在本例中，没有影响，后面是相与
#if 0
        cout<<"-----"<<check<<endl;
        Print_Binary_Num(check);
#endif
        i++;
    }
    i = 0; //第3次初始化
    while(s1[i]) //再次 扫描A 和check 位相与 。赋值给临时数组
    {
        Tmp = (s1[i] - 'a') % 32 ;

        if ((1<<Tmp)&check)
        {
            Tmp_String[index] = s1[i];
#if 0
            cout<<"This is --->"<<Tmp_String[index]<<endl;
#endif
            index++;
        }
        i++;
    }
    s1 = Tmp_String;
    return s1;
}

int main()
{
    char *s1 , *s2 ;
    s1 = "hello world " ;
    s2 = "re";
    s1 = Handler(s1 , s2);
    cout<<s1<<endl;

    return 0;
}


/*
THE Answer as follows---->

hllowold

Process returned 0 (0x0)   execution time : 0.029 s
Press any key to continue.
*/
