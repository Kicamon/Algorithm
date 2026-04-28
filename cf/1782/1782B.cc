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
        int n;
        cin >> n;
        vint a(n);
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        sort(all(a));
        int res = 1;
        if (a[0])
                res++;
        for (int i = 1; i < n; ++i)
                if (a[i - 1] < i && i < a[i]) {
                        res++;
                        //			cout << i << ' ' << a[i] << endl;
                }
        cout << res << endl;
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
