// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll unsigned long long
#define vint vector<int>
#define pb push_back

ll lowbit(ll x)
{
	return x & -x;
}

void solve()
{
	ll n,x;
	cin >> n >> x;
	if(n == x)
	{
		cout << n << endl;
		return;
	}
	while(true)
	{
		ll t = lowbit(n);
		t += n;
		n += lowbit(n);
		n -= lowbit(n);
		if(n == x)
		{
			cout << t << endl;
			return;
		}
		if(n < x)
		{
			cout << -1 << endl;
			return;
		}
	}
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
