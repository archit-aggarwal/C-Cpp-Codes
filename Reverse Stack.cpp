#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stk;
    for(int i=1;i<=5;i++)
     stk.push(i);
    
    // Method 1 : Using Another Stack 
    // O(N) Time Complexity, O(N) Extra Space
    
    stack<int> inv;
    while(!stk.empty())
    {
        inv.push(stk.top());
        stk.pop();
    }
    
    stk = inv; 
    // Copies the content from Inv stack back into originial stack - O(N) Time 
    
    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    
    return 0;
}
