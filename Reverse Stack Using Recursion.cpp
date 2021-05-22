#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &stk, int bottom)
{
    if(stk.empty())
    {
        stk.push(bottom);
        return;
    }
    
    int top = stk.top();
    stk.pop();
    insert(stk, bottom);
    stk.push(top);
}


// Pick Element One by One from Stack, then while returning
// Insert it at bottom using another recursive function
void reverse(stack<int> &stk)
{
    if(stk.empty()) return;
    
    int top = stk.top();
    stk.pop();
    
    reverse(stk);
    insert(stk, top);
}

int main() {
    stack<int> stk;
    for(int i=0; i<10; i++) stk.push(i);
    
    // Method 2: Using Recursion
    // Time Complexity : O(N ^ 2) : For each element we are calling Insert (At Bottom), thus O(Size) X O(Insert) = O(N) X O(N) = O(N^2)
    // Extra Space: We are using Recursion/Function Call Stack which will take O(N) Space if considered.
  
    reverse(stk);
    while(!stk.empty()) 
    {
        cout << stk.top() << " ";
        stk.pop();
    }
	return 0;
}
