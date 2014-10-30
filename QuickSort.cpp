#include<stdio.h>
#define cutoff 3
void Swap(int *a ,int *b)
{
    int *temp ;
    *temp = *a;
    *a = *b;
    *b = *temp;
}
int Median3(int a[] ,int Left , int Right)
{
    int Center ;
    Center = (Left + Right )/2 ;

    if (a[Left] > a[Center])
        Swap(&a[Left] , &a[Center]);
    if (a[Left] > a[Right])
        Swap(&a[Left] , &a[Right]);
    if (a[Center] > a[Right])
        Swap(&a[Center] , &a[Right]);
    Swap(&a[Center] , &a[Right-1]);//把枢纽元素和放在倒数第二个位置  ，Left < Center , Right > Center ; 所以开始比较就不用从Left && Righr开始
    return a[ Right-1 ] ;
}

void InsertionSort( int A[ ], int N ) //直接插入排序
{
    int j, P;
    int  Tmp;

    for( P = 1; P < N; P++ )
    {
        Tmp = A[ P ];

        for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
            A[ j ] = A[ j - 1 ];

        A[ j ] = Tmp;
    }
}
void Qsort(int a[] , int Left , int Right )
{
    int i , j ;
    int Pivot ;
    if ( Left + cutoff <= Right ) //小数组 尽量用直接插入法，而非用快速排序,因为递归的使用会使效率下降
    {
        Pivot = Median3(a,Left,Right); //三值的选择
        i = Left ; j = Right -1 ;
        for( ; ; )
        {
            while( a[++i] < Pivot ){}
            while( a[--j] > Pivot ){}
            if ( i < j )
                Swap(&a[i] , &a[j]);
            else
                break;
        }
        Swap(&a[i] , &a[Right-1]) ;
        Qsort(a,Left,i-1) ; //递归调用前半部
        Qsort(a,i+1,Right) ; //递归调用后半部
    }
    else
    {
             InsertionSort(a+Left , Right - Left + 1) ;
             printf("using InsertionSort ! \n");
    }

}
        /* Places the kth smallest element in the kth position */
        /* Because arrays start at 0, this will be index k-1 */
void Qselect( int A[ ], int k, int Left, int Right )
        {
            int i, j;
            int Pivot;

/* 1*/      if( Left + cutoff <= Right )
            {
/* 2*/          Pivot = Median3( A, Left, Right );
/* 3*/          i = Left; j = Right - 1;
/* 4*/          for( ; ; )
                {
/* 5*/              while( A[ ++i ] < Pivot ){ }
/* 6*/              while( A[ --j ] > Pivot ){ }
/* 7*/              if( i < j )
/* 8*/                  Swap( &A[ i ], &A[ j ] );
                    else
/* 9*/                  break;
                }
/*10*/          Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */

/*11*/          if( k <= i )
/*12*/              Qselect( A, k, Left, i - 1 );
/*13*/          else if( k > i + 1 )
/*14*/              Qselect( A, k, i + 1, Right );
            }
            else  /* Do an insertion sort on the subarray */
/*15*/          InsertionSort( A + Left, Right - Left + 1 );
        }
/* END */
/*
main function 是阿里巴巴2015校园招聘笔试题目：
描述：编写一个函数，输入一个二叉树，返回二叉树的最大值和最小值的  差值的绝对值
方法：
1-用快速排序算法排序
2-选择最大的和最小的差值绝对值
3-输出
时间复杂度为:O(NlogN)
当然作为纯算法题求解还有更优的，
1-先进行一次大根堆选择 选出最大的保存MAX；
2-在进行一次小根堆选择 选出最小的保存MIN;
3-返回fabs(MAX - MIN) 即是说求的
时间复杂度为 ： O(logN)
不过缺点是：有新的需求时，有需要更改代码，扩展性差；
*/
int main()
{
   int i,a[] = {31,41,59,26,53,58,97,-1,100,3,43,53,75,24,63}; //测试数组
   int len = sizeof(a)/sizeof(int);
  // Qsort( a , 0 , len );
Qselect( a, 5, 0, len );
    printf("The top k problem : \n");
   for( i = 0 ; i < 5 ; i++ )
        printf("%d \t " ,a[i] );
    printf("\n");

  Qsort( a , 0 , len );

   printf("The sort after : \n");
   for( i = 0 ; i < len ; i++ )
        printf("%d \t " ,a[i] );
    printf("\n");
    printf("The vuale of largest and smaller is : %d ", a[len-1] - a[0] );
    return 0;
}
