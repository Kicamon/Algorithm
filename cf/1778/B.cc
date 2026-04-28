// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define inf 0x3f3f3f3f

void solve() {
        int n, m, d;
        cin >> n >> m >> d;
        vint p(n + 1);
        for (int i = 0, c; i < n; ++i) {
                cin >> c;
                p[c] = i;
        }
        vint a(m);
        for (int i = 0, c; i < m; ++i) {
                cin >> c;
                a[i] = p[c];
        }
        int res = inf;
        for (int i = 0; i + 1 < m; ++i) {
                if (a[i] > a[i + 1] || a[i] + d < a[i + 1]) {
                        cout << 0 << endl;
                        return;
                } else {
                        res = min(res, a[i + 1] - a[i]);
                        int t = a[i] + d + 1;
                        if (n - 1 - a[i + 1] + a[i] >= t - a[i + 1])
                                res = min(res, t - a[i + 1]);
                }
        }
        cout << res << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        // clock_t start, finish;
        // start = clock();

        int t;
        cin >> t;
        while (t--)
                solve();

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
