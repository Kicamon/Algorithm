// Problem: 选数异或
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/4648/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define C2(n) (n * (n - 1) >> 1)
#define ll long long
#define ull unsigned long long 
#define PII pair<int, int>
#define vint vector<int>
#define pb push_back
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define eqs 1e-6
// const int mod = 
const int N = (1 << 20) + 10;

int num[N],dp[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n,m,x;
	cin >> n >> m >> x;
	for(int i = 1,c;i <= n;++i)
	{
		cin >> c;
		num[c] = i;
		dp[i] = max(dp[i - 1],num[c ^ x]);
	}
	
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		if(dp[r] >= l)
			puts("yes");
		else
			puts("no");
	}
    
    return 0;
}
