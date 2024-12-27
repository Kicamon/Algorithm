// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

const int N = 1e5 + 10;
int a[N];

int f(int x)
{
	return round(10 * sqrt(1. * x));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//clock_t start, finish;
	//start = clock();

	int n,m;
	cin >> n >> m;
	set<int> st;
	ll sum= 0;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		sum += a[i];
		if(a[i] != f(a[i]))
			st.insert(i);
	}
	st.insert(n + 1);
	
	while(m--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int l,r,k;
			cin >> l >> r >> k;
			int pos = l;
			while(true)
			{
				int idx = *st.lower_bound(pos);
				if(idx > r)
					break;
				for(int i = 1;i <= min(20LL,k);++i)
				{
					sum -= a[idx];
					a[idx] = f(a[idx]);
					sum += a[idx];
				}
				if(a[idx] == f(a[idx]))
					st.erase(idx);
				pos = idx + 1;
			}
		}
		else 
			cout << sum << endl;
	}


	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
