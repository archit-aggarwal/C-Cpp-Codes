#include <bits/stdc++.h>
using namespace std;
int heapify(int A[],int n,int i)
{
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && A[left]>A[i])
     max = left;
    if(right<n && A[right]>A[max])
     max = right;
    if(i<n && i!=max)
    {
     swap(A[i],A[max]);
     heapify(A,n,max);
    }
}
void heap_insert(int A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
       heapify(A,n,i);
}
void heap_sort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
    swap(A[0],A[n-1-i]);
    heapify(A,n-i-1,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    heap_insert(A,n);
    heap_sort(A,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
