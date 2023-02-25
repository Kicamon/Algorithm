#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define int long long
#define forl(i,l,r) for(int i=l;i<=r;i++) 
#define forr(i,r,l) for(int i=r;i>=l;i--)
#define mem(a,x) memset(a,x,sizeof(a));
#define all(x) x.begin(), x.end()
#define NO {puts("NO");return;}
#define YES {puts("YES");return;}
using namespace std;
typedef pair<int, int> PII;
const int N = 2e6+ 50, INF = 4e18, mod = 1e9 + 7;
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int lcm(int a,int b) {return a/gcd(a,b)*b;}
int n, m, d, k, T, l, r, res, x, y, z;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int q[N];
int cnt[N], sum[N];
int a[N];
int s[N];

void solve()
{   
	cin >> n;map<int, int>mp, mmp;
	forl(i, 1, 1e5) {
		sum[i] = cnt[i] = s[i] = a[i] = q[i] = 0;
	}
	forl(i, 1, n) {
		cin >> q[i];
		mp[q[i]] ++;
	}
	for (auto [y, x] : mp) {
		sum[x] += x;
		s[x] ++;
	}
	forl(i, 1, n) {
		sum[i] += sum[i - 1];
        s[i] += s[i - 1];
	}
	forl(i, 1, n) {
		res = sum[i];
		if (i != 1) res += (s[n] - s[i]) * (i - 1);
		cout << res << endl;
	}
}

signed main()
{
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	T = 1;//init();
	cin >> T;
	while (T--) solve();
	return 0;
}
