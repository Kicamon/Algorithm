// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

int n;

template<typename T>ll C(T a,T b)
{
	ll res = 1;
	for(T i = a,j = 1;j <= b;--i,++j)
	{
		res = res * i / j;
		if(res > n)
			return res;
	}
	return res;
}

bool check(int x)
{
	int l = x * 2,r = max(n,l);
	while(l < r)
	{
		int mid = l + r >> 1;
		if(C(mid,x) < n)
			l = mid + 1;
		else 
			r = mid;
	}
	if(C(l,x) != n)
		return false;
	cout << (ll)l * (l + 1) / 2 + x + 1 << endl;
	return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	cin >> n;
	for(int i = 16; ; --i)
		if(check(i))
			break;
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
