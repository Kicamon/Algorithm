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
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

struct LCA {
        vector<vector<int>> g, fa;
        vector<int> dep;
        int mdep;

        LCA(int n) {
                mdep = 1;
                while (1 << mdep < n) {
                        mdep++;
                }
                g.resize(n), dep.resize(n);
                fa.assign(n, vector<int>(mdep + 1, 0));
        }

        void add_edge(int u, int v) {
                g[u].push_back(v);
                g[v].push_back(u);
        }

        void init(int root, int fp) {
                dep[root] = 1;
                dfs(root, fp);
                fa[root][0] = root;
        }

        void dfs(int u, int f) {
                for (int v : g[u]) {
                        if (v == f) {
                                continue;
                        }
                        dep[v] = dep[u] + 1;
                        fa[v][0] = u;
                        for (int i = 1; i <= mdep; ++i) {
                                fa[v][i] = fa[fa[v][i - 1]][i - 1];
                        }
                        dfs(v, u);
                }
        }

        int get_lca(int a, int b) {
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
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        LCA lca(n + 1);
        for (int i = 1, a, b; i < n; ++i) {
                cin >> a >> b;
                lca.add_edge(a, b);
        }
        lca.init(1, 0);
        vector<int> t(3);
        while (m--) {
                int x, y, z;
                cin >> x >> y >> z;
                t[0] = lca.get_lca(x, y);
                t[1] = lca.get_lca(y, z);
                t[2] = lca.get_lca(x, z);
                sort(all(t));
                cout << (t[0] == t[1] ? t[2] : t[0]) << ' ';
                cout << 1ll * lca.dep[x] + lca.dep[y] + lca.dep[z] - lca.dep[t[0]] - lca.dep[t[1]] -
                            lca.dep[t[2]]
                     << endl;
        }

        return 0;
}
