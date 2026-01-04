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
#include <iostream>
#include <set>
#include <vector>
#include <array>
using namespace std;
using ll = long long;
const ll inf = 1e18;

vector<vector<array<int, 2>>> g;
vector<vector<int>> fa;
vector<set<int>> nd, rnd;
vector<int> dep;
vector<ll> dis;
int max_dep;

void init(int n) {
        max_dep = __lg(n) + 1;
        g.resize(n + 1);
        dep.resize(n + 1);
        dis.resize(n + 1);
        nd.resize(n + 1), rnd.resize(n + 1);
        fa.assign(n + 1, vector<int>(max_dep + 1));
}

void add(int u, int v, int w) {
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
}

array<ll, 2> dfs(int u, int p) {
        dep[u] = dep[p] + 1;
        fa[u][0] = p;
        array<ll, 2> res = { u, u };
        for (int i = 1; i <= max_dep; ++i) {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto [v, w] : g[u]) {
                if (v == p) {
                        continue;
                }
                dis[v] = dis[u] + w;
                auto temp = dfs(v, u);
                res = { min(res[0], temp[0]), max(res[1], temp[1]) };
        }

        nd[res[0]].insert(dis[u]), rnd[res[1] + 1].insert(dis[u]);

        return res;
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

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;
        init(n + 1);
        for (int i = 1, u, v, w; i < n; ++i) {
                cin >> u >> v >> w;
                add(u, v, w);
        }
        dfs(1, 0);

        for (int i = 2; i <= n; ++i) {
                for (int x : nd[i - 1]) {
                        nd[i].insert(x);
                }
                for (int x : rnd[i]) {
                        auto it = nd[i].find(x);
                        if (it != nd[i].end()) {
                                nd[i].erase(it);
                        }
                }
        }

        int l, r;
        while (m--) {
                cin >> l >> r;
                int ans = r - l + 1;
                for (int x : nd[r]) {
                        auto it = nd[l].find(x);
                        if (it != nd[l].end()) {
                                ans++;
                        }
                }
                cout << ans << '\n';
        }

        return 0;
}
