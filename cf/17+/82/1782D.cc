// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

bool isSquare(int x) {
        int t = sqrt(x * 1.0);
        return t * t == x;
}

void solve() {
        int n;
        cin >> n;
        vint a(n);
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        int ans = 1;
        for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                        int d = a[j] - a[i];
                        for (int k = 1; k * k <= d; ++k)
                                if (d % k == 0) {
                                        int t = d / k;
                                        if ((t - k) % 2)
                                                continue;
                                        int x = t - k >> 1;
                                        int y = t + k >> 1;
                                        if (a[i] > x * x)
                                                continue;
                                        int res = 0;
                                        int X = x * x - a[i];
                                        for (int p = 0; p < n; ++p)
                                                res += isSquare(a[p] + X);
                                        ans = max(ans, res);
                                }
                }
        }
        cout << ans << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int t;
        cin >> t;
        while (t--)
                solve();

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
