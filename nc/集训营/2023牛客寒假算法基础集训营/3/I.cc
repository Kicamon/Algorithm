//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int N = 1e6;

bool vis[N + 10];
vint primes;

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
	if(n == 1)
		cout << 2 << endl;
	else if(n == 2)
		cout << -1 << endl;
	else if(n == 3)
		cout << 4 << endl;
	else if(n == 7)
		cout << 8 << endl;
	else if(n & 1)
	{
		for(int i : primes)
		{
			if(i >= n - 1)
				break;
			if(!vis[n - 1 - i] && i != n - i - 1)
			{
				cout << 1LL * i * (n - 1 - i) << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
	else 
	{
		if(!vis[n - 1])
			cout << 1LL * (n - 1) * (n - 1) << endl;
		else 
			cout << 1LL * (n - 3) * 2 << endl;
	}
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
