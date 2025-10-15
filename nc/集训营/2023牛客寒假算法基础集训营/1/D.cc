// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

void solve() {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        double ans = 0;
        for (auto c : { 0, x })
                for (auto d : { 0, y }) {
                        double xl = min(x, max(a, c));
                        double xr = min(a, c);
                        double yl = min(y, max(b, d));
                        double yr = min(b, d);
                        double s = (xl - xr) * (yl - yr);
                        double S = x * y + abs(a - c) * abs(b - d) - s;
                        ans = max(ans, s / S);
                }
        cout << ans << endl;
}

signed main() {
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
