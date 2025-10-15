//#pragma GCC optimize(2)
#include <array>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define inf 1e18
#define int long long

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n, m;
        cin >> n >> m;
        vector<array<int, 2>> a(m);
        for (int i = 0; i < m; ++i)
                cin >> a[i][0] >> a[i][1];
        vint f(n + 1, inf);
        f[n] = 0;
        int res = n;
        for (int i = n; i > 2; --i) {
                for (int j = 0; j < m; ++j) {
                        int x = a[j][0], y = a[j][1];
                        if (i <= y)
                                continue;
                        int k = i - i % y;
                        f[k] = min(f[k], f[i] + x);
                        if (f[k] != inf)
                                res = min(res, k);
                }
        }
        cout << f[res] << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
