#include <bits/stdc++.h>
using namespace std;
void bubble(int A[],int num,int i)
{
  if(A[i]>A[i+1])
    swap(A[i],A[i+1]);
  if(i<num-1)
   bubble(A,num,i+1);
  else if(num>0) bubble(A,num-1,0);
}
int main()
{
    int arr[5] = {5,1,4,2,8};
    bubble(arr,5,0);
    cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4]<<endl;
    return 0;
}
