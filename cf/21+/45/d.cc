/*
[[ ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷ ]],
[[ ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇ ]],
[[ ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽ ]],
[[ ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕ ]],
[[ ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕ ]],
[[ ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕ ]],
[[ ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄ ]],
[[ ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕ ]],
[[ ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿ ]],
[[ ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ]],
[[ ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟ ]],
[[ ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠ ]],
[[ ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙ ]],
[[ ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣ ]],
*/
/* #pragma GCC optimize(2) */
#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<array<int, 2> > > f(n + 1, vector<array<int, 2> >(m + 1));
        f[1][0][1] = 1;
        for (int i = 2; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                        if (f[i - 1][j][0]) {
                                int k = j + (f[i - 1][j][0] - 1);
                                if (k <= m) {
                                        f[i][k][0] = f[i - 1][j][0];
                                        k = j + (i - 1);
                                        if (k <= m) {
                                                f[i][k][1] = i;
                                        }
                                }
                        }
                        if (f[i - 1][j][1]) {
                                int k = j + (f[i - 1][j][1] - 1);
                                if (k <= m) {
                                        f[i][k][0] = f[i - 1][j][1];
                                        k = j + (i - 1);
                                        if (k <= m) {
                                                f[i][k][1] = i;
                                        }
                                }
                        }
                }
        }

        for (int i = 1; i <= n; ++i) {
                Debug(i);
                for (int j = 0; j <= m; ++j) {
                        cout << j << ':' << f[i][j][0] << " \n"[j == m];
                }
                for (int j = 0; j <= m; ++j) {
                        cout << j << ':' << f[i][j][1] << " \n"[j == m];
                }
                cout << "-------------------\n";
        }

        if (!f[n][m][0] && !f[n][m][1]) {
                cout << 0 << endl;
                return;
        }
        vector<int> ans(n + 1);
        int k = 1;
        for (int i = n, j = m; i;) {
                if (f[i][j][1]) {
                        cout << 1 << ':' << i << ' ' << j << endl;
                        ans[i] = k++;
                        j -= i - 1;
                        --i;
                } else {
                        cout << 0 << ':' << i << ' ' << j << endl;
                        int x = f[i][j][0];
                        j -= (i - f[i][j][0]) * (f[i][j][0] - 1);
                        i = x;
                }
        }
        for (int i = 1; i <= n; ++i) {
                if (!ans[i]) {
                        cout << k++ << ' ';
                } else {
                        cout << ans[i] << ' ';
                }
        }
        cout << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
