// Problem: 纸张尺寸
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4655/
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

    int l = 1189, w = 841;
    string s;
    cin >> s;
    int x = s[1] - '0';
    while (x--) {
        l /= 2;
        swap(l, w);
    }
    cout << l << endl << w << endl;

    return 0;
}
