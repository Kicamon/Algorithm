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
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
using namespace std;
const int inf = 0x3f3f3f3f;

class DSU {
    private:
        vector<int> f;

    public:
        DSU(int n) {
                f.resize(n);
                iota(f.begin(), f.end(), 0);
        }

        int find(int x) {
                while (x != f[x]) {
                        x = f[x] = f[f[x]];
                }
                return x;
        }

        void merge(int a, int b) {
                a = find(a);
                b = find(b);
                if (a == b) {
                        return;
                }
                f[a] = b;
        }

        bool same(int a, int b) {
                return find(a) == find(b);
        }
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;
        vector<array<int, 2>> road(m);
        vector<vector<int>> g(n + 1);
        vector<int> dep(n + 1, inf), to(n + 1);
        iota(to.begin(), to.end(), 0);
        DSU dsu(n + 1);

        for (int i = 0, u, v; i < m; ++i) {
                cin >> u >> v;
                if (u > v) {
                        swap(u, v);
                }
                road[i] = { u, v };
                g[u].push_back(v);
                g[v].push_back(u);
        }

        sort(road.begin(), road.end());

        function<void(int, int, int)> dfs = [&](int u, int p, int d) {
                dep[u] = ++d;
                for (int v : g[u]) {
                        if (v == p) {
                                continue;
                        }
                        if (dep[v] < dep[u]) {
                                to[u] = to[v];
                                continue;
                        }
                        dfs(v, u, d);
                        if (dep[to[v]] < dep[to[u]]) {
                                to[u] = to[v];
                        }
                }
        };

        dfs(1, 0, 0);

        for (int i = 1; i <= n; ++i) {
                if (dep[to[i]] < dep[i]) {
                        dsu.merge(i, to[i]);
                }
        }

        for (auto [a, b] : road) {
                if (!dsu.same(a, b)) {
                        cout << a << ' ' << b << '\n';
                }
        }

        return 0;
}
