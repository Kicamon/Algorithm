//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define inf 0x3f3f3f3f

void solve()
{
	int n,m;
	cin >> n >> m;
	vint a(n + 1),q(n + 1);
	for(int i = 1;i <= n;++i)
		cin >> a[i];

	if(m == 1)
	{
		cout << 0 << endl;
		return;
	}

	sort(a.begin() + 1,a.end());
	
	int r = 0,num = 1;
	vint cnt(m + 1,0);
	int ans = inf; 
	
	auto ins = [&](int x){
		if(x <= 1 || x > m)
			return;
		cnt[x]++;
		if(cnt[x] == 1)
			num++;
	};

	auto del = [&](int x){
		if(x <= 1 || x > m)
			return;
		cnt[x]--;
		if(cnt[x] == 0)
			num--;
	};

	for(int l = 1;l <= n;++l)
	{
		while(num != m)
		{
			if(r == n)
				break;
			for(int i = 1;i * i <= a[r + 1];++i)
				if(a[r + 1] % i == 0)
				{
					ins(i);
					if(a[r + 1] / i != i)
						ins(a[r + 1] / i);
				}
			r++;
		}

		if(num == m)
			ans = min(ans,a[r] - a[l]);

		for(int i = 1;i * i <= a[l];++i)
		{
			if(a[l] % i == 0)
			{
				del(i);
				if(a[l] / i != i)
					del(a[l] / i);
			}
		}
	}

	cout << (ans == inf ? -1 : ans) << endl;
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
