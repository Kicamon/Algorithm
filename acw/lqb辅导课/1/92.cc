#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[20];
void dfs(int u)
{
	if(u == n)
	{
		for(int i = 1;i <= n;++i)
			if(vis[i])
				cout << i << ' ';
		cout << endl;
		return;
	}

	for(int i = 0; i <= 1;++i)
	{
		vis[u + 1] = i;
		dfs(u + 1);
		vis[u + 1] = 0;
	}
}

int main()
{
	cin >> n;
	dfs(0);
	return 0;
}
