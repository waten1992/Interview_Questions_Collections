#include<stdio.h>
#include<malloc.h>
#define MaxSize 20
#define ElemType char
/*
    Author : waten
    Date   : 2014-9-3 20:32
    程序描述:判断字符串符号串[] {}是否匹配 ；
    方法：  1-当遇到 '[' 或者 '{' , 则入栈；
            2-当遇到 ']' 或者 '{' ，则判断栈顶是否与 '[' '{' 相同，若是则POP，否者break 报错；
*/
struct SqStack
{
  ElemType data[MaxSize];
  int top ;
};
int StackEmpty (SqStack *&s)
{
    return (s->top == -1);
}
void InitStack(SqStack *&s)
{
    s = (SqStack *) malloc(sizeof( SqStack ));
    s->top = -1 ;
}
int Push(SqStack *S , ElemType &e)
{
    if (S->top == MaxSize -1 )
       {
          printf("It IS FULL OF THIS STACK \n");
          return 1;
       }
    S->top++;
    S->data[S->top] = e ;
    printf("Success Push new Elements : %c \n" , e );
    return 0 ;
}
int Pop_ALL_Stack(SqStack *S) //弹出栈内所有的元素
{
    while( S->top != -1 )
    {
        printf("%c \t" , S->data[S->top]);
        S->top--;
    }
    printf("ALL of Stack Elements pop of !\n");
    return 1;
}
int Pop(SqStack *S ,ElemType &e)
{
    if (S->top == -1)
        {
            printf("It is Empty for this Stack ! \n");
            return 0;
        }
    e = S->data[S->top] ;
    //S->top--;
    printf("It is success pop %c \n" , e );
    S->top--;
    return 1 ;
}

ElemType GetTop(SqStack *S , ElemType &e)
{
    if (S->top == -1)
        {
            printf("It is Empty for this Stack ! \n");
            return 0;
        }
    e = S->data[S->top];
    return e ;
}
int main()
{
    int e = 1 ,the_top ;
    SqStack *s ;
    InitStack(s);
    #if 0  //for test !
    if(s->top == -1 )
        printf("It is InitStack !!! \n");
    Push(s,e);
    the_top =GetTop(s,e);
    printf("the top is : %d \n",the_top);
    //Pop_ALL_Stack(s);
    Pop(s,e);
    #endif
    char Str[] = "{[waten }d";
    char Char_Top ;
    printf("The original string : %s \n",Str);
    char *p;
    p = Str ;
    while(*p != NULL)
    {
        printf("\n\tThe current element --->%c \n",*p); //做为调试信息
        if (*p == '{') //遇到左括号进栈
            Push(s,*p);
        if (*p == '[') //遇到左括号进栈
            Push(s,*p);
        if (*p == '}') //遇到'}' POP
            {
               if( GetTop(s,Char_Top) == '{' ) //若栈顶是 '{' 则与之匹配
                 Pop(s,*p);
               else
                 break ; //跳出循环，报错！！ ，后面的字符不再处理了
            }
        if (*p == ']') //遇到 ']' POP
            {
               if( GetTop(s,Char_Top) == '[' )  //若栈顶是 '[' 则与之匹配
                 Pop(s,*p);
               else
                 break ;
            }
        p++; //吃进下一个字符
    }
    if (GetTop(s,Char_Top) == 0) //如果栈 为空 表明成功匹配 否者不匹配
        printf("ALL SYMBOL SUCCESS Match !\n");
    else if ( GetTop(s,Char_Top) == '[' )
        printf(" [] didn't Match \n");
    else if (GetTop(s,Char_Top) == '{')
        printf(" {} didn't Match \n");
    else
        printf("all symbol didn't match\n");

    return 0 ;
}
/*
The Answer as follow ----->

The original string : {[waten }d

        The current element --->{
Success Push new Elements : {

        The current element --->[
Success Push new Elements : [

        The current element --->w

        The current element --->a

        The current element --->t

        The current element --->e

        The current element --->n

        The current element --->

        The current element --->}
 [] didn't Match

Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.



*/
