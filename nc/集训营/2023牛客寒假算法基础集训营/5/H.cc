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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int x,y,k,n;
	ll t;
	cin >> x >> y >> k >> n >> t;
	ll res = 0;
	int cnt = 0,i;
	for(i = n;i && res < t;--i)
	{
		res += i * (x + y * (cnt / k));
		cnt += i;
	}
	if(res < t)
		cout << -1 << endl;
	else 
		cout << n - i << endl;
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
