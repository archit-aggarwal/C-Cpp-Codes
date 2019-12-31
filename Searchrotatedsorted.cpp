//Searching an element in an rotated sorted array
#include<iostream>
using namespace std;
int binarysearch(int A[],int start,int end,int key)
{
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(A[mid]==key)
        return mid;
        if(A[mid]>key)
        end=mid-1;
        else start=mid+1;
    }
    return -1;
}
int findpivot(int A[],int start,int end)
{
    if(A[end]>A[start])
     return -1;
    int mid; 
    while(start<=end)
    {
        mid=(start+end)/2;
        if(A[mid]>A[mid+1])
        return mid;
        if(A[mid]<A[mid-1])
        return mid-1;
        if(A[mid]<A[0])
        end=mid-1;
        else start=mid+1;
    }
    return -1;
}
int main()
 {
	int T,N,key;
	cin>>T;
	while(T--)
	 {
	     cin>>N;
	     int A[N],index=-1;
	     for(int i=0;i<N;i++)
	      cin>>A[i];
	     cin>>key;
	     int pivot=findpivot(A,0,N-1);
	     if(pivot == -1)
	     index=binarysearch(A,0,N-1,key);
	     else if(binarysearch(A,0,pivot,key)!=-1)
	     index = binarysearch(A,0,pivot,key);
	     else if(binarysearch(A,pivot+1,N-1,key)!=-1)
	     index = binarysearch(A,pivot+1,N-1,key);
	     cout<<index<<endl;
	      
	 } 
	 return 0;
}
