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
// const int N =

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    ll res = 0;
    int num;
    for (int i = 0; i < n; ++i) {
        ll t = a[i] * (n - i);
        if (t > res)
            res = t, num = a[i];
    }
    cout << res << ' ' << num << endl;

    return 0;
}
