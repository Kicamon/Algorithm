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
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

array<bool, 31> gbl(int x) {
        array<bool, 31> res;
        fill(all(res), 0);
        int idx = 0;
        while (x) {
                res[idx++] = x % 2;
                x >>= 1;
        }
        return res;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<array<bool, 31>> a(n);
        vector<int> x(n);
        array<int, 32> vis;
        fill(all(vis), 0);

        function<void(bool, int)> update = [&](bool ud, int i) {
                if (ud) {
                        for (int j = 0; j < 32; ++j) {
                                if (a[i][j]) {
                                        vis[j]--;
                                }
                        }
                } else {
                        for (int j = 0; j < 32; ++j) {
                                if (a[i][j]) {
                                        vis[j]++;
                                }
                        }
                }
        };

        for (int i = 0; i < n; ++i) {
                cin >> x[i];
                a[i] = gbl(x[i]);
                update(0, i);
        }

        int m;
        cin >> m;
        int idx = -1;

        function<void(int)> change = [&](int v) {
                for (int i = 0; i < n; ++i) {
                        if ((x[i] & (1 << v)) && (x[i] >= (1 << v))) {
                                x[i] <<= (idx - i);
                                update(1, i);
                                a[i] = gbl(x[i]);
                                update(0, i);
                        }
                }
        };

        for (int i = 30; ~i; --i) {
                if (!vis[i]) {
                        continue;
                }
                if (idx == -1) {
                        idx = i;
                        continue;
                }
                if ((idx - i) * vis[i] <= m) {
                        m -= (idx - i) * vis[i];
                        change(i);
                } else {
                        idx = i;
                }
        }
        int ans = 0;
        for (int s : x) {
                ans |= s;
        }
        cout << ans << endl;

        return 0;
}
