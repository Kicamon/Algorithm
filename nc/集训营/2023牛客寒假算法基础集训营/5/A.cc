//#pragma GCC optimize(2)
#include <algorithm>
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

        int n, m;
        cin >> n >> m;
        vint a(n + 1);
        for (int i = 1; i <= n; ++i)
                cin >> a[i];
        sort(a.begin() + 1, a.end());
        vector<ll> b(n + 1);
        b[0] = 0;
        for (int i = 1; i <= n; ++i)
                b[i] = a[i] + b[i - 1];
        while (m--) {
                int k, x;
                cin >> k >> x;
                ll res = 0;
                int l = upper_bound(all(a), x) - a.begin();
                l--;
                if (l >= k)
                        cout << b[l] - b[l - k] << endl;
                else
                        cout << b[l] << endl;
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
