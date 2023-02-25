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

int N(int u)
{
	return (u + 1) * u >> 1;
}

int get_bn(int u)
{
	int res = 0;
	while(u)
	{
		res++;
		u -= u & -u;
	}
	return res;
}

void solve()
{
	int n,k;
	cin >> n >> k;
	string a,b;
	cin >> a >> b;
	vector<bool> sam(n,0);
	vector<vint> us(26);
	for(int i = 0;i < n;++i)
	{
		if(a[i] == b[i])
			sam[i] = true;
		else 
			us[a[i] - 'a'].pb(i);
	}
	vint usam;
	for(int i = 0;i < 26;++i)
		if(us[i].size())
			usam.pb(i);
	if(usam.size() <= k)
		cout << N(n) << endl;
	else 
	{
		int ans = 0;
		for(int i = 0;i < 1 << usam.size();++i)
		{
			if(get_bn(i) != k)
				continue;
			vector<bool> cnt = sam;
			for(int j = 0;j < usam.size();++j)
			{
				if(i >> j & 1)
				{
					int t = usam[j];
					for(int k : us[t])
						cnt[k] = true;
				}
			}
			int len = 0,res = 0;
			for(int i = 0;i < n;++i)
			{
				if(cnt[i])
					len++;
				else
				{
					res += N(len);
					len = 0;
				}
			}
			res += N(len);
			ans = max(ans,res);
		}
		cout << ans << endl;
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
