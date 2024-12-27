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
    
	ll n;
	cin >> n;
	ll res = 1;
	for(ll i = 2;i * i <= n;++i)
	{
		if(n % i == 0)
		{
			int cnt = 0;
			while(n % i == 0)
				n /= i,cnt++;
			if(cnt & 1)
				res *= i;
		}
	}
	if(n > 1)
		res *= n;
	cout << res << endl;
	
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
