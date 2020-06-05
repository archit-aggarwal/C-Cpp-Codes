#include<bits/stdc++.h>
using namespace std;
#define pi              pair<int,int>
#define s(type)         set<type>
#define m(type)         map<type,int>
#define hashmap(type)   unordered_map<type,int>
#define hashset(type)   unordered_set<type>
#define t(x)            int x; cin>>x; while(x--)
#define minheap(type)   priority_queue<type,vector<type>,greater<type>>
#define maxheap(type)   priority_queue<type,vector<type>,less<type>>
#define mod             1000000007
#define ll              long long int

void file_input_output()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int bs_upper_bound(int a[], int n, int x) {
	int l = 0;
	int h = n; // Not n - 1
	while (l < h) {
		int mid =  l + (h - l) / 2;
		if (x >= a[mid]) {
			l = mid + 1;
		} else {
			h = mid;
		}
	}
	return l;
}

int bs_lower_bound(int a[], int n, int x) {
	int l = 0;
	int h = n; // Not n - 1
	while (l < h) {
		int mid =  l + (h - l) / 2;
		if (x <= a[mid]) {
			h = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
int main()
{
	file_input_output();
	// Implementing Lower Bound & Upper Bound in C++ without STL.
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << bs_lower_bound(arr, 10, 8);
	cout << endl << bs_upper_bound(arr, 10, 8);
	return 0;
}