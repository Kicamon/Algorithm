//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int mod = 1e9 + 7;

ll get(int n) {
        ll res = 1;
        for (int i = 1; i <= n; ++i)
                res = res * i % mod;
        res = res * n % mod;
        res = res * (n - 1) % mod;
        return res;
}

void solve() {
        int n;
        cin >> n;
        cout << get(n) << endl;
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
