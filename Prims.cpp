int Minkey(vector<int> weight,vector<bool> vis,int V)
{
    int Min = INT_MAX,Minindex = 0;
    for(int i=0;i<V;i++) 
    {
        if(vis[i] == false && weight[i] < Min) 
        { 
            Minindex = i; 
            Min = weight[i]; 
        }
    }
    return Minindex;
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // Here graph is in the form of adjacency matrix (V X V)
    vector<bool> vis(V,false);
    vector<int> weight(V,INT_MAX);
    int ans = 0;
    vis[0] = true;
    weight[0] = 0;
    for(int i=0;i<V;i++) weight[i] = graph[i][0];
    for(int i=0;i<V-1;i++)
    {
        int Min = Minkey(weight,vis,V);
        vis[Min] = true;
        ans += weight[Min];
        for(int j=0;j<V;j++)
        {
            if(graph[Min][j]<weight[j] && vis[j]==false)
             weight[j] = graph[Min][j];
        }
    }
    return ans;
}
