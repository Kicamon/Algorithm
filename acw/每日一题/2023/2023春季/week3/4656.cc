// Problem: 技能升级
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4659/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define C2(n) (n * (n - 1) >> 1)
#define ll long long
#define ull unsigned long long
#define ai2 array<int, 2>
#define vint vector<int>
#define pb push_back
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define eqs 1e-6
// const int mod =
// const int N =

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        vector<ai2> a(n);
        for (int i = 0; i < n; ++i)
                cin >> a[i][0] >> a[i][1];
        sort(all(a));

        auto check = [&](int x) {
                int res = 0;
                int l = 0, r = n - 1;
                while (l < r) {
                        int mid = l + r >> 1;
                        if (a[mid][0] <= x)
                                l = mid + 1;
                        else
                                r = mid;
                }
                for (int i = l; i < n; ++i)
                        res += ((ll)a[i][0] - x + a[i][1] - 1) / a[i][1];
                return res > m;
        };

        int l = 0, r = a[n - 1][0];
        while (l < r) {
                int mid = l + r >> 1;
                if (check(mid))
                        l = mid + 1;
                else
                        r = mid;
        }

        int cnt = 0;
        auto add = [&](ll res, int i) {
                int t = (a[i][0] - l + a[i][1] - 1) / a[i][1];
                cnt += t;
                res += (ll)t * a[i][0] - (ll)t * (t - 1) / 2 * a[i][1];
                return res;
        };

        ll res = 0;
        for (int i = 0; i < n; ++i) {
                if (a[i][0] > l)
                        res = add(res, i);
        }

        cout << res + (ll)l * (m - cnt) << endl;

        return 0;
}
