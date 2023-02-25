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
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int res = a;
	int cnt = a;
	if(res == 0)
	{
		cout << 1 << endl;
		return;
	}
	else 
	{
		bool flag = false;
		if(b || c)
		{
			int x = min(b,c),y = max(b,c);
			res += x * 2;
			y -= x;
			if(y > cnt)
			{
				res += cnt;
				cnt = 0;
				flag = true;
			}
			else 
			{
				res += y;
				cnt -= y;
			}
		}
		if(d)
		{
			if(cnt > 0)
				res += min(cnt,d);
			if(d > cnt)
				flag = true;
		}
		cout << res + flag << endl;
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
