#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void Reverse()
{
    if(q.empty())
    return ;
     int x = q.front();
     q.pop();
     Reverse();
     q.push(x);
}
int main()
{
    for(int i=1;i<=5;i++)
     q.push(i);
    Reverse();
    while(!q.empty())
    {
     cout<<q.front()<<" ";
     q.pop();
    }
    cout<<endl;
    return 0;
}
