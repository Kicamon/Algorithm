// Problem: 求和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/4647/
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
// const int N =

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vint a(n);
    ll res = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res += cnt * a[i];
        cnt += a[i];
    }
    cout << res << endl;

    return 0;
}
