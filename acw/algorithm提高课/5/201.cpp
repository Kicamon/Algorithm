//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

ll get_uler(int n)
{
    vector<int> phi(n + 1, 0), primes;
    vector<bool> vis(n + 1, 1);

    phi[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (vis[i])
        {
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int j = 0; primes[j] * i <= n; ++j)
        {
            int t = primes[j] * i;
            vis[t] = false;
            if (i % primes[j] == 0)
            {
                phi[t] = primes[j] * phi[i];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res += phi[i];
    return res;
}

int solve(int n)
{
	int t = get_uler(n);	
	return (t << 1) + 1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int t;
	cin >> t;
	for(int i = 1,n;i <= t;++i)
	{
		cin >> n;
		cout << i << ' ' << n << ' ' << solve(n) << endl;
	}
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
