//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        ll res = 0;
        int n;
        cin >> n;
        vint a(n + 1, 0);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                sum += a[i];
        }
        for (int i = 1; i <= n; ++i) {
                sum -= a[i];
                res += 1LL * a[i] * sum;
        }
        cout << res << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
