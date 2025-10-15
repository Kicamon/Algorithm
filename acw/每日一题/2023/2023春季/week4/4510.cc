// #pragma GCC optimize(2)
#include <array>
#include <bits/stdc++.h>
#include <vector>
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

        // clock_t start, finish;
        // start = clock();

        int n, L, S;
        cin >> n >> L >> S;
        vector<array<int, 2>> a(n);
        for (int i = 0, x, y; i < n; ++i) {
                cin >> x >> y;
                a[i] = { x, y };
        }
        vector<vint> b(S + 1, vint(S + 1));
        for (int i = S; ~i; --i)
                for (int j = 0; j <= S; ++j)
                        cin >> b[i][j];
        auto check = [&](int x, int y) {
                vector<vint> t(S + 1, vint(S + 1, 0));
                for (int k = 0; k < n; ++k) {
                        int i = a[k][0] - x, j = a[k][1] - y;
                        if (i >= 0 && j >= 0 && i <= S && j <= S)
                                t[i][j] = 1;
                }

                for (int i = 0; i <= S; ++i)
                        for (int j = 0; j <= S; ++j)
                                if (t[i][j] != b[i][j])
                                        return false;
                return true;
        };
        int res = 0;
        for (int k = 0; k < n; ++k) {
                int x = a[k][0], y = a[k][1];
                if (x + S > L || y + S > L)
                        continue;
                if (check(x, y))
                        res++;
        }
        cout << res << endl;

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
