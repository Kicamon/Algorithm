#include <bits/stdc++.h>
using namespace std;

int n;
int ans[10];
bool vis[10];
void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0;i < n;++i)
			cout << ans[i] << ' ';
		cout << endl;
		return;
	}
	for(int i = 1;i <= n;++i)
	{
		if(vis[i])
			continue;
		vis[i] = true;
		ans[u] = i;
		dfs(u + 1);
		vis[i] = false;
	}
}

int main()
{
	cin >> n;
	dfs(0);
	return 0;
}
