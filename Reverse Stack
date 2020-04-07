#include <bits/stdc++.h>
using namespace std;
stack<int> Reverse(stack<int> input,stack<int> output)
{
    if(input.empty())
        return output;
    output.push(input.top());
    input.pop();
    return Reverse(input,output);
}
int main()
{
    stack<int> stk;
    for(int i=1;i<=5;i++)
     stk.push(i);
    stack<int> inv;
    // Method 1 : Using Another Stack : O(N) Extra Space
    // O(N) Time Complexity
    while(!stk.empty())
    {
        inv.push(stk.top());
        stk.pop();
    }
    stk = inv; 
    // Method 2 : Using Recursion : O(N) Time Complexity
    stk = Reverse(stk,inv);
    while(!stk.empty())
    {
     cout<<stk.top()<<" ";
     stk.pop();
    }
    cout<<endl;
    return 0;
}
