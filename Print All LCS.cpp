vector<string> all_longest_common_subsequences(string text1, string text2)
	{
	    int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        vector<string> res;
        queue<pair<string, pair<int, int>>> q;
        q.push(make_pair("", make_pair(n, m)));
        while(!q.empty())
        {
            string curr = q.front().first;
            int i = q.front().second.first, j = q.front().second.second;
            q.pop();
            if(i == 0 || j == 0)
            {
                res.push_back(curr);
                continue;
            }
            if(text1[i-1] == text2[j-1])
                q.push(make_pair(text1[i-1] + curr, make_pair(i-1, j-1)));
            else
            {
                if(dp[i-1][j] >= dp[i][j-1])
                    q.push(make_pair(curr, make_pair(i-1, j)));
                if(dp[i-1][j] <= dp[i][j-1])
                    q.push(make_pair(curr, make_pair(i, j-1)));
            }
        }
        
        return res;
	}
