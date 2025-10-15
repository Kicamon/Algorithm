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

int n, idx, mdep;
vector<array<int, 2>> a;
vector<vector<int>> g, fa;
vector<int> dep;

void build() {
        idx = 1;
        dep[1] = 1;
        fa[1][0] = 1;
        dep[2] = 2;
        fa[2][0] = 1;
        dep[3] = 2;
        fa[3][0] = 1;
        idx = 4;
        while (idx < n) {
                int old_idx = idx - 2;
                for (int i = 1; i <= old_idx; ++i, ++idx) {
                        if (idx >= n) {
                                return;
                        }
                        cout << i << ' ' << idx << endl;
                        g[i].push_back(idx);
                        dep[idx] = dep[i] + 1;
                        fa[idx][0] = i;
                        for (int j = 1; j <= mdep; ++j) {
                                fa[idx][j] = fa[fa[idx][j - 1]][j - 1];
                        }
                }
        }
}

int lca(int a, int b) {
        if (dep[a] < dep[b]) {
                swap(a, b);
        }
        for (int i = mdep; ~i; --i) {
                if (dep[fa[a][i]] >= dep[b]) {
                        a = fa[a][i];
                }
        }
        if (a == b) {
                return a;
        }
        for (int i = mdep; ~i; --i) {
                if (fa[a][i] != fa[b][i]) {
                        a = fa[a][i];
                        b = fa[b][i];
                }
        }
        return fa[a][0];
}

int get_mdep(int u) {
        int res = 0;
        while ((1 << res) < u) {
                res++;
        }
        return res;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int m;
        cin >> m;
        a.resize(m);
        for (auto &x : a) {
                cin >> x[0] >> x[1];
                n = max(n, max(x[0], x[1]));
        }
        g.resize(n + 1), dep.resize(n + 1);
        mdep = get_mdep(n + 1);
        fa.assign(n + 1, vector<int>(mdep + 1, 0));
        build();
        // for (auto x : a) {
        //         cout << lca(x[0], x[1]) << endl;
        // }

        return 0;
}
