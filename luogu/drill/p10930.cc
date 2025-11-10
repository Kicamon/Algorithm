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
#include <functional>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

vector<vector<tuple<int, int>>> g;
vector<vector<int>> fa;
vector<int> dep, in;
vector<ll> dis;
int max_dep;
int time_ptr;

void init(int n) {
        max_dep = __lg(n) + 1;
        dep.resize(n + 1), in.resize(n + 1), g.resize(n + 1), dis.resize(n + 1);
        fa.assign(n + 1, vector<int>(max_dep + 1));
}

void add_edge(int u, int v, int w) {
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
}

void dfs(int u, int p) {
        in[u] = ++time_ptr;
        dep[u] = dep[p] + 1;
        fa[u][0] = p;
        for (int i = 1; i <= max_dep; ++i) {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto [v, w] : g[u]) {
                if (v == p) {
                        continue;
                }
                dis[v] = dis[u] + w;
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

ll get_dis(int u, int v) {
        int p = lca(u, v);
        return dis[u] + dis[v] - dis[p] * 2;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        init(n);
        for (int i = 1, u, v, w; i < n; ++i) {
                cin >> u >> v >> w;
                add_edge(u, v, w);
        }
        dfs(1, 0);
        int m;
        cin >> m;

        auto comp = [&](int a, int b) { return in[a] < in[b]; };
        set<int, decltype(comp)> st(comp);
        using sii = set<int>::iterator;
        function<array<sii, 2>(sii)> itop = [&](sii it) {
                auto left = it, right = it;
                if (left == st.begin()) {
                        left = st.end();
                }
                left--;
                right++;
                if (right == st.end()) {
                        right = st.begin();
                }

                return array<sii, 2>{ left, right };
        };

        ll ans = 0;
        while (m--) {
                char opt;
                cin >> opt;
                if (opt == '+') {
                        int x;
                        cin >> x;
                        if (st.empty()) {
                                st.insert(x);
                                continue;
                        }
                        auto [left, right] = itop(st.insert(x).first);
                        ans -= get_dis(*left, *right);
                        ans += get_dis(*left, x) + get_dis(x, *right);
                } else if (opt == '-') {
                        int x;
                        cin >> x;
                        auto it = st.find(x);
                        auto [left, right] = itop(it);
                        ans += get_dis(*left, *right);
                        ans -= get_dis(*left, x) + get_dis(x, *right);

                        st.erase(it);
                } else {
                        cout << (ans >> 1) << endl;
                }
        }

        return 0;
}
