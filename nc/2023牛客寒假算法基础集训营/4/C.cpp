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
#define ai2 array<int,2>

int calc(int n,int m,vector<ai2>& s)
{
	vint f(m + 1);
	for(int i = 0;i < n;++i)
		for(int j = m;j >= s[i][0];--j)
			f[j] = max(f[j],f[j - s[i][0]] + s[i][1]);
	return f[m];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int n,m;
	cin >> n >> m;
	vector<ai2> s(n);
	for(int i = 0;i < n;++i)
		cin >> s[i][0] >> s[i][1];
	if(n == 1)
		cout << 0 << endl;
	else 
	{
		for(int i = 0;i < n;++i)
		{
			int vmax;
			vector<ai2> S;
			for(int j = 0;j < n;++j)
			{
				if(j == i)
					continue;
				S.pb(s[j]);
			}
			vmax = calc(n - 1,m,S);

			int vi = s[i][1];
			
			int l = 0,r = 1e18 + 1;
			while(l < r)
			{
				int mid = l + r >> 1;
				s[i][1] = vi + mid;
				if(calc(n,m,s) == vmax)
					l = mid + 1;
				else 
					r = mid;
			}
			cout << r << endl;
			s[i][1] = vi;
		}
	}
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
