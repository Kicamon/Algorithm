//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

void solve()
{
	int n;
	cin >> n;
	vint a(n);

	for(int i = 0;i < n;++i)
		cin >> a[i];
	if(n == 1)
	{
		cout << 0 << endl;
		return;
	}
	int res = 0;
	for(int i = 1;i < n;++i)
	{
		if((a[i - 1] % 2) == (a[i] % 2))
		{
			a[i] = a[i] * a[i - 1] % 2;
			res++;
		}
	}
	cout << res << endl;
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
