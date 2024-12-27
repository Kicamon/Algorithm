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

int lowbit(int n)
{
	return n & -n;	
}

void solve()
{
	int n;
	cin >> n;
	if(n & 1 || n & (n << 1))
		cout << -1 << endl;
	else 
	{
		int a = n,b = 0;
		while(n)
		{
			int t = lowbit(n);
			n -= t;
			t >>= 1;
			a += t,b += t;
		}
		cout << a << ' ' << b << endl; 
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
