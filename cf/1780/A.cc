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
        int n;
        cin >> n;
        vint a[2];
        for (int i = 1, c; i <= n; ++i) {
                cin >> c;
                if (c & 1)
                        a[0].pb(i);
                else
                        a[1].pb(i);
        }
        if (a[1].size() == n || n == 3 && a[0].size() == 2)
                cout << "NO" << endl;
        else {
                cout << "YES" << endl;
                if (a[1].size() <= 1)
                        for (int i = 0; i < 3; ++i)
                                cout << a[0][i] << ' ';
                else
                        cout << a[1][0] << ' ' << a[1][1] << ' ' << a[0][0];
                cout << endl;
        }
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
