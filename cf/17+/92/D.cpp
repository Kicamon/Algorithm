//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int N = 5e5 + 10;

int tr[N][11];
int idx;

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vint> a(n,vint(m));
	for(int i = 0;i < n;++i)
	{
		vint pos(m);
		for(int j = 0;j < m;++j)
		{
			cin >> a[i][j];
			a[i][j]--;
			pos[a[i][j]] = j;
		}
		int p = 0;
		for(int j = 0;j < m;++j)
		{
			int x = pos[j];
			if(!tr[p][x])		
				tr[p][x] = ++idx;
			p = tr[p][x];
		}
	}

	for(int i = 0;i < n;++i)
	{
		int p = 0;
		int res = m;
		for(int j = 0;j < m;++j)
		{
			int x = a[i][j];
			if(!tr[p][x])
			{
				res = j;
				break;
			}
			p = tr[p][x];
		}
		cout << res << ' ';
	}
	cout << endl;
	for(int i = 0;i <= idx;++i)
		memset(tr[i],0,sizeof tr[i]);
	idx = 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//clock_t start, finish;
	//start = clock();

	int t;
	cin >> t;
	while(t--)
		solve();

	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
