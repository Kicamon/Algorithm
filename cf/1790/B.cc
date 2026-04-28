//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

void solve() {
        int n, s, t;
        cin >> n >> s >> t;
        vint a(n);
        a[0] = s - t;
        s = t;
        t = s / (n - 1);
        int k = s % (n - 1);
        for (int i = 1; i < n; ++i) {
                a[i] = t;
                if (i <= k)
                        a[i]++;
        }
        for (int x : a)
                cout << x << ' ';
        cout << endl;
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
