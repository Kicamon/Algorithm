// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 1e5 + 10;

int f[110][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//clock_t start, finish;
	//start = clock();

	int n;
	cin >> n;
	vint a(n + 1);
	int m = 0;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		m += a[i];
	}
	f[0][0] = 1;
	for(int i = 1;i <= n;++i)
	{
		for(int j = 0;j <= m;++j)
		{
			f[i][j] |= f[i - 1][j];
			f[i][abs(j - a[i])] |= f[i - 1][j];
			f[i][j + a[i]] |= f[i - 1][j];
		}
	}
	int res = 0;
	for(int i = 1;i <= m;++i)
		res += f[n][i];
	cout << res << endl;
	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
