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

void solve()
{
	int a,b,c;
	cin >> a >> b >> c;
	int cnt = a + b + c;
	if(cnt & 1)
	{
		cout << "NO\n";
		return;
	}
	cnt >>= 1;
	int la = cnt - a,lb = cnt - b,lc = cnt - c;
	if(la + lb <= lc || la + lc <= lb || lb + lc <= la)
		cout << "NO\n";
	else 
	{
		cout << "YES\n";
		cout << la << ' ' << lb << ' ' << lc << endl;
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
