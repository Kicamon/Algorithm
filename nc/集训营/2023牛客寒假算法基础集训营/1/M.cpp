// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 510;

double f[N][N];

signed main()
{
	//clock_t start, finish;
	//start = clock();

	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
		for(int j = 0;j <= m;++j)
			for(int k = 0;k <= j;++k)
				f[i][j] = max(f[i][j], f[i - 1][j - k] + 1. * k / (m - j + k));
	printf("%.9lf\n",f[n][m]);

	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
