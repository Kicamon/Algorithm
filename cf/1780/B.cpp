//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

template <typename T> T gcd(T a, T b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n + 1,0);
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}

	ll res = 0;
	for(int i = 1;i < n;++i)
		res = max(res,gcd(a[i],a[n] - a[i]));
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
