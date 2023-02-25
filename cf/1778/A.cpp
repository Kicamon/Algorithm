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
	vint a(n);
	int res = 0;
	bool f = false,idx = false,cnt = false;
	for(int i = 0;i < n;++i)
	{
		cin >> a[i];
		res += a[i];
		idx |= a[i] == -1;
	}
	if(!idx)
		res -= 4;
	else 
		for(int i = 0;i + 1 < n;++i)
		{
			if(a[i] == -1 && a[i + 1] == -1)
				cnt = true;
		}
	if(cnt)
		res += 4;
	cout << res << endl;
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
