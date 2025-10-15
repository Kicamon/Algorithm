// Problem: 重新排序
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4658/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define C2(n) (n * (n - 1) >> 1)
#define ll long long
#define ull unsigned long long
#define PII pair<int, int>
#define vint vector<int>
#define pb push_back
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define eqs 1e-6
// const int mod =
const int N = 1e5 + 10;

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vint a(n + 1, 0);
        vector<ll> b(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                b[i] = a[i] + b[i - 1];
        }
        int m;
        cin >> m;
        ll res = 0;
        vint s(n + 2, 0);
        for (int i = 0; i < m; ++i) {
                int l, r;
                cin >> l >> r;
                res += b[r] - b[l - 1];
                s[l]++, s[r + 1]--;
        }
        for (int i = 1; i <= n; ++i)
                s[i] += s[i - 1];
        sort(s.begin() + 1, s.end() - 1);
        sort(a.begin() + 1, a.end());
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
                ans += (ll)a[i] * s[i];
        cout << ans - res << endl;

        return 0;
}
