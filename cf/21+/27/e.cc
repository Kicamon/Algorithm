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
#include <set>
#include <utility>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> w(n), c(n);
        vector<vector<int> > g(n);
        for (int &x : w) {
                cin >> x;
        }
        for (int &x : c) {
                cin >> x;
        }
        for (int i = 1, a, b; i < n; ++i) {
                cin >> a >> b;
                a--, b--;
                g[a].push_back(b), g[b].push_back(a);
        }

        ll ans = 0;
        vector<set<int> > s(n);

        function<void(int, int)> color = [&](int u, int p) {
                c[u] = c[p];
                for (auto v : g[u]) {
                        if (v == p) {
                                continue;
                        }
                        if (!c[v]) {
                                color(v, u);
                        }
                }
        };

        function<void(int, int)> dfs = [&](int u, int p) {
                vector<int> a;
                for (int v : g[u]) {
                        if (v == p) {
                                continue;
                        };
                        dfs(v, u);
                        if (s[u].size() < s[v].size()) { // 优化，没有这个swap会MLE
                                swap(s[u], s[v]);
                        }
                        for (int x : s[v]) {
                                if (s[u].count(x)) {
                                        a.push_back(x);
                                } else {
                                        s[u].insert(x);
                                }
                        }
                }
                sort(all(a));
                a.erase(unique(all(a)), a.end());

                if (a.size() > 1 || (a.size() == 1 && c[u] && a[0] != c[u])) {
                        ans += w[u];
                }

                if (c[u]) {
                        s[u].insert(c[u]);
                } else if (!a.empty()) {
                        c[u] = a[0];
                } else if (!s[u].empty()) {
                        c[u] = *s[u].begin();
                }
                if (c[u]) {
                        for (int v : g[u]) {
                                if (v == p) {
                                        continue;
                                }
                                if (!c[v]) {
                                        color(v, u);
                                }
                        }
                }
        };
        dfs(0, -1);

        cout << ans << endl;
        for (int i = 0; i < n; ++i) {
                cout << max(c[i], 1) << " \n"[i == n - 1];
        }
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
