//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int n,l,r,t,k;
	cin >> n >> l >> r >> t >> k;
	vint a(n + 1);
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	for(int i = 1;i <= n;++i)
	{
		if(i == l)
		{
			for(int j = t;j <= k;++j)
				cout << a[j] << ' ';
			i = r;
		}
		else if(i == t)
		{
			for(int j = l;j <= r;++j)
				cout << a[j] << ' ';
			i = k;
		}
		else 
			cout << a[i] << ' ';
	}
	cout << endl;
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
