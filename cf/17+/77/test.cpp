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
	int n, m; 
	cin >> n >> m;
	int a[n+1];
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	
	int r = 0, num = 1;
	vector<int> cnt(m+1, 0);
	
	// 更新cnt的函数, cnt_i 表示有多少元素是 i 的倍数
	auto ins = [&](int x){if(x<=1 || x>m) return;cnt[x]++; if(cnt[x] == 1) num++;};
	auto del = [&](int x){if(x<=1 || x>m) return;cnt[x]--; if(cnt[x] == 0) num--;};
	
	int ans = 1e9;
	if(m == 1)
	{
		cout << 0 << '\n';
		return;
	}
	
	for(int l=1;l<=n;l++)
	{
		while(num != m) 
		{
			// 指针移动，加入a[r+1]
			if(r == n) break;
			for(int i=1;i<=sqrt(a[r+1]);i++)
			{
				if(a[r+1] % i == 0)
				{
					ins(i);
					if(a[r+1] / i != i) ins(a[r+1] / i);
				}
			}
			r++;
		}
		
		if(num == m) ans = min(ans, a[r] - a[l]);
		
		for(int i=1;i<=sqrt(a[l]);i++)
		{
			if(a[l] % i == 0)
			{
				del(i);
				if(a[l] / i != i) del(a[l] / i);
			}
		}
	}
	if(ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
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
