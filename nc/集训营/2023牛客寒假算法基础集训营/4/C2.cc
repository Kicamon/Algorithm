//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n, m;
        cin >> n >> m;
        vint w(n), v(n);
        for (int i = 0; i < n; ++i)
                cin >> w[i] >> v[i];
        for (int i = 0; i < n; ++i) {
                vint f(m + 1);
                for (int j = 0; j < n; ++j)
                        if (i == j)
                                continue;
                        else
                                for (int k = m; k >= w[j]; --k)
                                        f[k] = max(f[k], f[k - w[j]] + v[j]);
                int ans = f[m] - v[i] - f[m - w[i]] + 1;
                cout << (ans < 0 ? 0 : ans) << endl;
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
