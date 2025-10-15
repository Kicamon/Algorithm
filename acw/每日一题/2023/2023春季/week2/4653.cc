// Problem: 数位排序
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4656/
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
const int N = 1e6 + 10;

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        vint a(n), b(n + 1);
        for (int i = 0; i < n; ++i) {
                a[i] = i + 1;
                int s = 0;
                for (int j = i + 1; j; j /= 10)
                        s += j % 10;
                b[a[i]] = s;
        }

        sort(all(a), [&](int v1, int v2) {
                if (b[v1] != b[v2])
                        return b[v1] < b[v2];
                return v1 < v2;
        });

        cout << a[m - 1] << endl;

        return 0;
}
