//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 110, M = 1 << 6, K = 25;
const int mod = 1e9 + 7;

int n, m, k;
int f[N][M][M][K];
int num[M + 10];

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        f[0][0][0][0] = 1;
        for (int i = 0; i < 1 << 6; ++i) {
                int x = i;
                while (x) {
                        num[i]++;
                        x -= x & -x;
                }
        }

        cin >> n >> m >> k;
        for (int i = 1; i <= m; ++i) {
                for (int a = 0; a < 1 << n; ++a) {
                        for (int b = 0; b < 1 << n; ++b) {
                                if (a & (b << 2) || b & (a << 2))
                                        continue;
                                for (int c = 0; c < 1 << n; ++c) {
                                        if (c & (b << 2) || b & (c << 2))
                                                continue;
                                        if (c & (a << 1) || a & (c << 1))
                                                continue;
                                        for (int t = num[c]; t <= k; ++t)
                                                f[i][b][c][t] =
                                                    (f[i][b][c][t] + f[i - 1][a][b][t - num[c]]) %
                                                    mod;
                                }
                        }
                }
        }

        int res = 0;
        for (int i = 0; i < 1 << n; ++i)
                for (int j = 0; j < 1 << n; ++j)
                        res = (res + f[m][i][j][k]) % mod;
        cout << res << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
