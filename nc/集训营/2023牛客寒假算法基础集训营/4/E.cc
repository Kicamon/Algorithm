//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n, t, a;
        cin >> n >> t >> a;
        vector<array<int, 2>> w(n);
        bool f = false;
        for (int i = 0; i < n; ++i) {
                cin >> w[i][0] >> w[i][1];
                w[i][1] *= t;
                f |= w[i][1] >= a && w[i][0] > a;
        }
        if (f)
                cout << -1 << endl;
        else {
                int res = 0;
                for (int i = 0; i < n; ++i) {
                        if (w[i][0] <= a)
                                res += t;
                        else
                                res += (w[i][0] - 2 * w[i][1] + a - 1) / (a - w[i][1]) * t;
                }
                cout << res - t + 1 << endl;
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
