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
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define all(x) (x).begin(), (x).end()

class TR {
    private:
        const int inf = INT_MAX;
        const ll INF = LLONG_MAX;
        vector<vector<array<int, 2>>> g;
        vector<vector<int>> fa, mmax, smax;
        vector<int> dep, f;
        vector<bool> vis;
        int max_dep;
        vector<array<int, 3>> edge;
        int n, m;
        ll sum = 0;

    public:
        TR(int _n, int _m) {
                n = _n, m = _m;
                max_dep = __lg(n) + 1;
                g.resize(n + 1), dep.resize(n + 1), f.resize(n + 1), vis.resize(m);
                fa.assign(n + 1, vector<int>(max_dep + 1, 0));
                mmax.assign(n + 1, vector<int>(max_dep + 1, -inf));
                smax.assign(n + 1, vector<int>(max_dep + 1, -inf));
                iota(all(f), 0);
        }

        void add_edge(int u, int v, int w) {
                edge.push_back({ u, v, w });
        }

        int find(int x) {
                while (x != f[x]) {
                        x = f[x] = f[f[x]];
                }
                return x;
        }

        bool merge(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) {
                        return false;
                }
                f[y] = x;
                return true;
        }

        void kruskal() {
                sort(all(edge), [](const auto &a, const auto &b) { return a[2] < b[2]; });
                for (int i = 0; i < m; ++i) {
                        const auto &[u, v, w] = edge[i];
                        if (merge(u, v)) {
                                sum += w;
                                g[u].push_back({ v, w });
                                g[v].push_back({ u, w });
                                vis[i] = true;
                        }
                }
        }

        void dfs(int u, int p) {
                fa[u][0] = p;
                dep[u] = dep[p] + 1;
                for (int i = 1; (1 << i) <= dep[u]; ++i) {
                        fa[u][i] = fa[fa[u][i - 1]][i - 1];
                        int v = fa[u][i - 1];
                        int tmp[4]
                            = { mmax[u][i - 1], smax[u][i - 1], mmax[v][i - 1], smax[v][i - 1] };
                        sort(tmp, tmp + 4);
                        mmax[u][i] = tmp[3];
                        int idx = 2;
                        while (~idx && tmp[idx] == tmp[3]) {
                                --idx;
                        }
                        if (idx != -1) {
                                smax[u][i] = tmp[idx];
                        }
                }

                for (const auto &[v, w] : g[u]) {
                        if (v == p) {
                                continue;
                        }
                        mmax[v][0] = w;
                        dfs(v, u);
                }
        }

        int lca(int a, int b) {
                if (dep[a] < dep[b]) {
                        swap(a, b);
                }
                for (int i = max_dep; ~i; --i) {
                        if (dep[fa[a][i]] >= dep[b]) {
                                a = fa[a][i];
                        }
                }
                if (a == b) {
                        return a;
                }
                for (int i = max_dep; ~i; --i) {
                        if (fa[a][i] != fa[b][i]) {
                                a = fa[a][i];
                                b = fa[b][i];
                        }
                }
                return fa[a][0];
        }

        int query(int x, int y, int w) {
                int res = -inf;
                for (int i = max_dep; ~i; --i) {
                        if (dep[fa[x][i]] >= dep[y]) {
                                if (w != mmax[x][i]) {
                                        res = max(res, mmax[x][i]);
                                } else {
                                        res = max(res, smax[x][i]);
                                }
                                x = fa[x][i];
                        }
                }
                return res;
        }

        ll tr() {
                kruskal();
                ll ans = INF;
                dfs(1, 0);

                for (int i = 0; i < m; ++i) {
                        if (vis[i]) {
                                continue;
                        }
                        const auto &[u, v, w] = edge[i];
                        int _lca = lca(u, v);
                        ll temp = max(query(u, _lca, w), query(v, _lca, w));
                        if (temp > -inf) {
                                ans = min(ans, sum - temp + w);
                        }
                }
                return ans == INF ? -1 : ans;
        }
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        TR tr(n, m);
        for (int i = 0, u, v, w; i < m; ++i) {
                cin >> u >> v >> w;
                tr.add_edge(u, v, w);
        }
        cout << tr.tr() << endl;

        return 0;
}
