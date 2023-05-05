#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
const int qwq=90000;
int dp[305][180005],a[505];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	dp[2][a[2]+qwq]=1;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<=qwq+qwq;j++)
		{
			if(dp[i][j])
			{
				if(j!=qwq)
				{
					dp[i+1][a[i+1]+j]+=dp[i][j];
					dp[i+1][a[i+1]-j+qwq*2]+=dp[i][j];
				}
				else dp[i+1][a[i+1]+j]+=dp[i][j];
			}
		}
		for(int j=0;j<=qwq+qwq;j++) dp[i+1][j]%=mod;
	}
	int ans=0;
	for(int i=0;i<=qwq+qwq;i++) ans+=dp[n][i];
	cout << ans%mod;
	return 0;
}
