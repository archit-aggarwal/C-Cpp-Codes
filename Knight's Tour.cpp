#include<bits/stdc++.h>
using namespace std;
void file_input_output()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
#define sz(a) int((a).size())
#define ll                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem0(a)           memset(a,0,sizeof(a))
const long long INF = 1e18;
const int32_t mod = 1e9 + 7;

vector < vector<int>> board(8, vector<int>(8, -1));
bool solve(int i, int j, int k, pair<int, int> move[])
{
	if (k == 64) return true;
	for (int l = 0; l < 8; l++)
	{
		int r = i + move[l].first , c = j + move[l].second;
		if (!(r < 0 || c < 0 || r >= 8 || c >= 8 || board[r][c] >= 0))
		{
			board[r][c] = k;
			if (solve(i + move[l].first, j + move[l].second, k + 1, move))
				return true;
			board[r][c] = -1;
		}

	}
	board[i][j] = -1;
	return false;
}
int main()
{
	file_input_output();
	pair<int, int> move[8];
	move[0] = make_pair(1, 2);
	move[1] = make_pair(1, -2);
	move[2] = make_pair(-1, 2);
	move[3] = make_pair(-1, -2);
	move[4] = make_pair(2, 1);
	move[5] = make_pair(2, -1);
	move[6] = make_pair(-2, 1);
	move[7] = make_pair(-2, -1);
	bool temp = solve(0, 0, 0, move);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	return 0;
}
