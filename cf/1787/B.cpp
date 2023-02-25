//#pragma GCC optimize(2)
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long
const int N = 5e4;

vint primes;
bool vis[N + 10];

void prime(int n)
{
	vis[0] = vis[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i])
			primes.push_back(i);
		for (int j = 0; primes[j] * i <= n; j++)
		{
			vis[primes[j] * i] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	vector<array<int,2>> a;
	for(int i : primes)
	{
		if(i > n)
			break;
		if(n % i == 0)
		{
			int t = 0;
			while(n % i == 0)
			{
				t++;
				n /= i;
			}
			a.pb({i,t});
		}
	}
	if(n > 1)
		a.pb({n,1});
	sort(all(a),[&](auto x,auto y){
			return x[1] > y[1];
			});
	int t = a[0][1], k = a[0][0];
	int ans = 0;
	for(int i = 1;i < a.size();++i)
	{
		if(a[i][1] != t)
		{
			ans += k * (t - a[i][1]);
			t = a[i][1];
		}
		k *= a[i][0];
	}
	ans += k * t;
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//clock_t start, finish;
	//start = clock();

	prime(N);

	int t;
	cin >> t;
	while(t--)
		solve();

	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
