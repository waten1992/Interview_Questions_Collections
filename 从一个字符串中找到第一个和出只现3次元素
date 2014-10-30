/*
描述：从一个字符串中找到第一个和出只现3次元素

第一个----建立队列，保持第一个；
3次-----用一个数组记录次数，等于3次进入队列，大于3次剔除队列；
输出队列首部的元素；

*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    int Record[26] = {0}; //记录数组
    deque <char> St; //队列
    char *str = "helloeell";
    int index = 0, i = 0 ; //index 记录数组的下标
    cout<<"The original is --->"<<str<<endl;
    while(str[i] != '\0')
    {
        index = (str[i] - 'a') %26;
        Record[index]++;
#if 1 //for test !
        cout<<str[i]<<"--->"<<Record[index]<<endl;
#endif
        if(Record[index] == 3)
        {
            St.push_back(str[i]);
        }
        if(Record[index] > 3)  //把它从队列中删掉
        {
            St.erase(find(St.begin(),St.end(),str[i]));
        }

        i++;
    }
    if (!St.empty()) //如果队列不为空就输出第一个元素
        cout <<"The Answer is -->"<< St.front() << endl;
    return 0;
}
/*
The Answer as follow--->

The original is --->helloeell
h--->1
e--->1
l--->1
l--->2
o--->1
e--->2
e--->3
l--->3
l--->4
The Answer is -->e

Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.

*/
