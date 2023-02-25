//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = (1 << 20) + 10;

int num[N],dp[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1,c;i <= n;++i)
	{
		cin >> c;
		dp[i] = max(dp[i - 1],num[c ^ k]);
		num[c] = i;
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
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
