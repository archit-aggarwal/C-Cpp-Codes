vector<int> findSubarray(int a[], int n) {
	    int start = 0, max_start = 0, max_end = 0; 
	    long long int Max = a[0] , curr = a[0];
        for(int i=1;i<n;i++)
        {
            if(curr >= 0)
                curr += a[i];
            else
            {
                curr = a[i];
                start = i;
            }
            if((curr > Max) || ((curr == Max) && (max_end - max_start < i - start)))
            {
                max_start = start;
                max_end = i;
                Max = curr;
            }
        }
        
        vector<int> res;
        for(int i=max_start; i<=max_end; i++)
            res.push_back(a[i]);
        return res;
	}
