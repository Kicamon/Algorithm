// #pragma GCC optimize(2)
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
        vector<bool> l(n + 1, 0), w(n + 1, 0);
        int ln = 0, wn = 0;
        ll s = (ll)n * n;
        for (int i = 0, x, y; i < m; ++i) {
                cin >> x >> y;
                int t = 0;
                if (!l[x])
                        t |= 1;
                if (!w[y])
                        t |= 2;
                l[x] = w[y] = true;
                if (t == 1)
                        s -= n - wn;
                else if (t == 2)
                        s -= n - ln;
                else if (t == 3)
                        s -= n + n - ln - wn - 1;
                if (t & 1)
                        ln++;
                if (t & 2)
                        wn++;
                cout << s << ' ';
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
