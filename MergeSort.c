#include<stdio.h>
#include<malloc.h>
/*
Lpos = start of left half ;     Rpos = start of right half ;
*/
void Merge(int a[] , int TmpArray[] ,int Lpos , int Rpos , int RightEnd )
{
    int i , LeftEnd , Num , TmpPos ;
    LeftEnd = Rpos -1 ;
    TmpPos = Lpos ;
    Num = RightEnd - Lpos + 1 ;

    while( Lpos <= LeftEnd && Rpos <= RightEnd )
    {
        if ( a[Lpos] <= a[Rpos] )
            TmpArray[TmpPos++] = a[Lpos++] ;
        else
            TmpArray[TmpPos++] = a[Rpos++] ;
    }

    while(Lpos <= LeftEnd ) //copy rest of first half
    {
        TmpArray[TmpPos++] = a[Lpos++];
    }

    while(Rpos <= RightEnd ) //copy rest of second half
    {
        TmpArray[TmpPos++] = a[Rpos++];
    }

    //copy TmpArray back to a[]
    for(i = 0 ; i < Num ; i++ , RightEnd-- )
        a[RightEnd] = TmpArray[RightEnd];

}
void Msort(int a[] , int TmpArray[] , int Left , int Right)
{
    int center ;
    if (Left < Right )
    {
        center = (Left + Right)/2 ;
        Msort(a,TmpArray,Left,center);
        Msort(a,TmpArray,center+1,Right);
        Merge(a,TmpArray,Left,center+1,Right);
    }
}

void MergerSort(int a[] ,int n)
{
    int *TmpArray ;
    TmpArray = (int *)malloc(sizeof(int)*n);
    if (TmpArray != NULL)
    {
        Msort(a,TmpArray,0,n-1);
        printf("Aready alloc space for Temp array! \n");
        free(TmpArray) ; //释放掉临时数组
    }
    else
    {
        printf("No space for temp array! \n");
    }
}
int main()
{
 int a[] = {9,7,54,3,1};
 int i , len = sizeof(a)/sizeof(int);
 MergerSort( a, len ); //建立起临时数组，并调用归并函数
 printf("MergerSort  is done ! \n");
 for(i=0 ; i<len ;i++)
    printf("%d \t" ,a[i]);

    return 0;
}
