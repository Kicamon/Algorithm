//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define pb push_back

void solve()
{
	ll n;
	cin >> n;
	if(n == 2)
	{
		cout << -1 << endl;
		return;
	}
	cout << (n * 2 + n % 2) / 3 << endl;
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
