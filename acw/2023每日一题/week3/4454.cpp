// Problem: 未初始化警告
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4457/
// Memory Limit: 64 MB
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
#define ai2 array<int, 2>
#define vint vector<int>
#define pb push_back
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define eqs 1e-6
// const int mod =

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<bool> vis(n + 1, 0);
    vis[0] = true;
    int res = 0, a, b;
    while (m--)
    {
        cin >> a >> b;
        if (!vis[b])
            res++;
        vis[a] = true;
    }

    cout << res << endl;

    return 0;
}
