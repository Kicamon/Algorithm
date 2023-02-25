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
	int n;
	cin >> n;
	map<int,int> p;
	for(int i = 0,c;i < n;++i)
	{
		cin >> c;
		p[c]++;
	}
	int ans = n;
	int last = -1,cnt = 0;
	for(auto x : p)
	{
		if(x.first == last + 1)
			ans -= min(cnt,x.second);
		last = x.first;
		cnt = x.second;
	}
	cout << ans << endl;
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
