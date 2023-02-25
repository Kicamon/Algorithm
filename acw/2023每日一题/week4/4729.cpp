//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

void solve()
{
	ll n,a,b;
	cin >> n >> a >> b;
	ll t = n - a * b + 2;
	
	auto check = [&](int mid){
		return (ll)mid * (t - mid) < n;
	};

	int l = 1,r = t >> 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid))
			l = mid + 1;
		else 
			r = mid;
	}
	if((ll)l * (t - l) == n)
		cout << l << ' ' << t - l << endl;
	else
		cout << "NO" << endl;
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
