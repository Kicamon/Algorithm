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
	vint a(n + 1),num(n + 1);
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		num[a[i]]= i;
	}
	if(n & 1)
	{
		int l = num[n / 2 + 1],r = num[n / 2 + 1];
		int tl = n / 2,tr = n / 2 + 2;
		int ans = n / 2;
		while(tl >= 1)
		{
			if(num[tl] < l && num[tr] > r)
			{
				l = num[tl], r = num[tr];
				ans--;
				tl--,tr++;
			}
			else 
				break;
		}
		cout << ans << endl;
	}
	else 
	{
		int l = num[n / 2],r = num[n / 2 + 1];
		int tl = n / 2,tr = n / 2 + 1;
		if(tl > tr)
		{
			cout << n / 2 << endl;
			return;
		}
		{
			int l = num[n / 2],r = num[n / 2 + 1];
			int tl = n / 2,tr = n / 2 + 1;
			if(num[tl] > num[tr])
			{
				cout << n / 2 << endl;
				return;
			}
			int ans = n / 2 - 1;
			l = num[tl],r = num[tr];
			tl--,tr++;
			while(tl >= 1)
			{
				if(num[tl] < l && num[tr] > r)
				{
					l = num[tl], r = num[tr];
					ans--;
					tl--,tr++;
				}
				else 
					break;
			}
			cout << ans << endl;
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
