#include<bits/stdc++.h>
using namespace std;
// O(N^2) Solution - O(1) Extra Space
void rightrotate(int arr[], int i, int j) 
{ 
    int temp = arr[j];
    for(int k=j;k>i;k--)
     arr[k] = arr[k-1];
    arr[i] = temp; 
} 
  
void rearrange(int arr[], int N) 
{ 
  int i=0,j;
  for(i=0;i<N;i++)
  {
      if((i%2==0 && arr[i]<0)||(i%2==1 && arr[i]>=0))
      {
          j = i+1;
          if(arr[i]>=0)
           { while(j<N && arr[j]>=0) j++; }
          else
           { while(j<N && arr[j]<0) j++; }
          if(j<N) rightrotate(arr,i,j); 
      }
  }
} 
int main()
 {
	int T;
	cin>>T;
	while(T--)
	 {
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++) cin>>arr[i];
       rearrange(arr, n); 
       for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
       cout << endl; 
	 }
	 return 0;
}
