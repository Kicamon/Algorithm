//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 1e7 + 10;

template <class T> struct Get_uler
{
    vector<int> primes;
    int phi[N];
    bool vis[N];
	T s[N];

    void get_uler(int n)
    {
        for (int i = 2; i <= n; ++i)
        {
            if (!vis[i])
            {
                phi[i] = i - 1;
                primes.push_back(i);
            }
            for (int j = 0; primes[j] * i <= n; ++j)
            {
                int t = primes[j] * i;
                vis[t] = true;
                if (i % primes[j] == 0)
                {
                    phi[t] = primes[j] * phi[i];
                    break;
                }
                phi[t] = phi[i] * (primes[j] - 1);
            }
        }
		for(int i = 1;i <= n;++i)
			s[i] = s[i - 1] + phi[i];
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	Get_uler<ll> c;
	int n;
	cin >> n;
	c.get_uler(n);
	ll res = 0;
	for(int i : c.primes)
		res += c.s[n / i] * 2 + 1;
	cout << res << endl;
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
