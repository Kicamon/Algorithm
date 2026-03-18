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
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

ll num(int x) {
        return 1ll * x * (x - 1) / 2;
}

class DSU {
    private:
        vector<int> fa, siz;
        ll size;

    public:
        DSU(int n) {
                size = 0;
                fa.resize(n);
                iota(fa.begin(), fa.end(), 0);
                siz.assign(n, 1);
        }

        int find(int x) {
                while (x != fa[x]) {
                        x = fa[x] = fa[fa[x]];
                }
                return x;
        }

        bool merge(int a, int b) {
                a = find(a);
                b = find(b);
                if (a == b) {
                        return false;
                }
                size += 1ll * siz[a] * siz[b];
                fa[b] = a;
                siz[a] += siz[b];
                return true;
        }

        ll get_size() {
                return size;
        }
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, q, k;
        cin >> n;
        vector<vector<int>> g(n + 1);
        vector<int> fa(n + 1);
        for (int i = 1, u, v; i < n; ++i) {
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        function<void(int, int)> init = [&](int u, int p) {
                fa[u] = p;
                for (int v : g[u]) {
                        if (v == p) {
                                continue;
                        }
                        init(v, u);
                }
        };
        init(1, 0);

        cin >> q;
        while (q--) {
                cin >> k;
                DSU dsu(k);
                map<int, int> p;
                for (int i = 0, x; i < k; ++i) {
                        cin >> x;
                        p[x] = i;
                }
                for (auto [u, i] : p) {
                        if (p.count(fa[u])) {
                                dsu.merge(i, p[fa[u]]);
                        }
                }
                cout << dsu.get_size() << '\n';
        }

        return 0;
}
