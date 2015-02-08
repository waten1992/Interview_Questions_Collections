#if 1
/*
描述：求在一个数组内是否存在A和B ---使得 A+B = X 成立 ，请编写一个函数，若存在则返回1 ，否者返回-1（携程笔试题）

方法：先用堆排序 排好序 ，用最左边加最右边 和 输入进来的比较

伪代码：---> int  Left = 0 , Right = len -1 ; //这里需要注意的地方
        ---> 边界的检测--数组的长度是否是大于1
                            ------>若不是则break；
        利用排好序后的夹逼，若target  > 最大+最小，则小的向后移动。否者大的向前移动；
        ---> while(Left < Right)
            {
                int cuurent = a[Left] + a[Right] ;
                if (x == cuurent)
                    return 1 ;
                else if ( x > cuurent )
                    Left++;
                else
                    Right++;
            }
        --->return -1 ;
*/
#include<stdio.h>
#include<stdlib.h>
#define LeftChild(i) ( 2*i + 1 ) //为左孩子，因为数组的下标从0开始的，当 i = 0 ，2×i+1 = 1 ,所以是成立的
// 下标 i = 0 存储是最大的值 ， 所以leftchild 是 2×i + 1 ；
void  PercUp(int a[] , int i , int len) //使最小的上滤 ，选出最小的节点
{
    int child , temp  ,index = i ;
    for( temp = a[i] ; LeftChild(i) < len ; i = child )
    {
        child = LeftChild(i);
        if ( (child != len -1) && (a[child+1] < a[child]) ) // 选择最小的节点 若右孩子小于左孩子，所以要用右孩子去和根节点比较
            child++;
        if( temp > a[child] ) //始终把孩子节点和root节点比较，如果 孩纸节点  比父节点更小
            a[i] = a[child] ;//把最小的孩子  赋值给父节点
        else
            break;
    }
    a[i] = temp ; //把原始root节点 赋值给当前的子的节点
#if 0 //for test
    printf("THIS time of heap most smaller---> %d \n" , a[index]);
#endif
}

void PercDown(int a[] , int i , int n) //最小的下滤，求最大的堆
{
    int child , temp ;
    for( temp = a[i] ; LeftChild(i) < n ; i = child )
    {
        child = LeftChild(i); //孩子节点
        if ( (child != n -1) && (a[child+1] > a[child]) ) //选择最大的孩子节点，
            child++;
        if( temp < a[child] ) // 始终把孩子节点和root节点比较，如果 孩子节点大于 父节点
            a[i] = a[child] ; //把孩子节点赋值给  父节点
        else
            break;
    }
    a[i] = temp ;// 如果 存在孩子节点大于原始root节点  就把root节点赋值给孩子节点  因为i目前变成孩子节点的下标； 如果不存在  也就保持不变
}

void Swap(int *a , int *b)
{
    int *Tmp ;
    *Tmp = *a ;
    *a = *b ;
    *b = *Tmp ;
}

int HeapSort(int a[] ,int n )
{
    int i , Tmp_Larger ,Tmp_Smaller ;
    for(i = n/2 ; i >= 0 ; i-- ) // n/2 标号最大分支节点，即最大的非叶子节点标号 ；
        PercDown(  a , i , n ); //求最小堆，采用上滤，使最小的浮上来
#if 0 //内部测试
    printf("The first build smaller heap:\n");
    for(i = 0 ; i < n ; i++ )
        printf("%d \t" , a[i]);
    printf("\n");
#endif
    Tmp_Larger = a[0];

#if 1 //this code for heap sort

    for(i = n -1 ; i > 0 ; i-- ) //按升序排序
    {
        Swap( &a[0] , &a[i] ) ;
        PercDown(a , 0 , i ) ;
    }
#endif
    return Tmp_Larger;
}


int Find_Here(int a[] , int len , int x)
{
    int Left = 0 , Right = len-1  ;

    if (len <= 1)
        return -1 ;
    else
    {
        if ( x < a[Left] + a[Left+1]  || x > a[Right] + a[Right-1] )
            return -1 ;
    }

    while(Left < Right )
    {
        int  current = a[Left] + a[Right] ;
        if ( x == current)
            return 1;
        else if ( x > current )
            Left++;
        else
            Right--;
    }
    return -1 ;
}

int main()
{
    int a[] = {0,-7,9,67}; //测试数组
    int len , i , x = 53  , index = 0;

    len = sizeof(a)/sizeof(int);
    HeapSort( a , len );  //建立堆排序

#if 1 //遍历排好序的数组
    for(i = 0 ; i < len ; i++ ) //遍历已经拍好序的数组
        printf("%d \t" , a[i]);
    printf("\n");
#endif

    index = Find_Here(a , len , x) ;  // 检测返回值

   if(index == 1 )
        printf("---%d is FIND----> \n",target);
    else
        printf("---%d IS NOT FIND \n",target) ;
    return 0;
}
#endif

/*
The Answer as follow--->


-7      0       9       67
---2 is FIND---->

Process returned 1 (0x1)   execution time : 0.016 s
Press any key to continue.


*/
