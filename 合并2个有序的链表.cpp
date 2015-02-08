/*
描述：编写一个函数合并两个有序的链表，返回一个新链表；

解题方案；1-依次比较两个链表的长度，把较小的值依次按尾插法插入新链表，直到一个的链表指向链表末尾；
          2-把新的链表的未指针指向没有结束的指针；

解决成本：时间复杂度O(M) M->最短的链表长度
*/

#include <iostream>
using namespace std;

typedef int Elements;
typedef struct Node *Linklist;
struct Node
{
    Elements data ;
    struct Node * next;
};
int Insert_Node(Linklist Header , int i)
{
    Linklist p;
    p = new Node ;
    if (p == NULL)
        cout<<"It is wrong!!"<<endl;
    p->data = i ;
    p->next = Header->next;  //头插法
    Header->next = p ;

    return 0;
}
void Display(Linklist head)
{
    Linklist temp;
    temp = head->next;
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next ;
    }
    cout<<endl;
}
void Init_Link_Header(Linklist &Header)
{
    Header = new Node ;
    Header->next = NULL ;
}

Linklist Merge_Two_Sort_List(Linklist A , Linklist B , Linklist C)
{
    A = A->next ;
    B = B->next ;
    Linklist Tmp_A = A->next ;
    Linklist Tmp_B = B->next ;
    Linklist Tmp_C = C ;
    while(A != NULL && B != NULL )
    {
        if(A->data <= B->data )
        {
            A->next = Tmp_C->next ; //尾插法
            Tmp_C->next = A ;
            A = Tmp_A ;
            if ( A != NULL)  //保证A不为空
                Tmp_A = Tmp_A->next ;
        }
        else
        {
            B->next = Tmp_C->next ;
            Tmp_C->next = B ;
            B = Tmp_B;
            if (B != NULL)
                Tmp_B = Tmp_B->next ;
        }
        Tmp_C = Tmp_C->next ;
    }
    if(A != NULL )
        Tmp_C->next = A ;
    if(B != NULL )
        Tmp_C->next = B ;
    return C;
}
int main()
{
    int i ;
    Linklist A , B , C ;
    Init_Link_Header(A);
    Init_Link_Header(B);
    Init_Link_Header(C);
    int  len , a[] = {1,2,3,4,5,6,7,8} ; //测试数组，A B 包含
    len = sizeof(a)/sizeof(a[0]) ;
    for(i=len-1 ; i >= 0  ; i = i - 1 )
        Insert_Node(A , a[i]) ;

    cout<<"THIS IS A List ---->";
    Display(A) ;

    for(i=7 ; i > 0  ; i = i - 2 )
        Insert_Node(B , i) ;

    cout<<"THIS IS B List ---->";
    Display(B);

    cout<<"THIS IS Merge Two Sort List ---->";
    Merge_Two_Sort_List( A , B, C);
    Display(C);

    return 0;
}

/*
----The Answer as follow--->
----
THIS IS A List ---->1   2       3       4       5       6       7       8

THIS IS B List ---->1   3       5       7
THIS IS Merge Two Sort List ---->1      1       2       3       3       4
5       5       6       7       7       8

Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.

*/
