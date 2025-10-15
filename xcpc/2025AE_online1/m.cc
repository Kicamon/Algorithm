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
#include <numeric>
#include <queue>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const ll inf = 1e18;

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        vector<ll> dis(n, inf);
        vector<vector<array<int, 2>>> g(n);
        vector<vector<int>> rg(n);
        for (int i = 1, u, v, w; i < n; ++i) {
                cin >> u >> v >> w;
                u--, v--;
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
        }
        for (int i = 0, u, v; i < m; ++i) {
                cin >> u >> v;
                u--, v--;
                rg[u].push_back(v);
                rg[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
                rg[i].push_back(i);
        }

        function<void(int, int)> init = [&](int u, int p) {
                for (auto [v, w] : g[u]) {
                        if (v == p) {
                                continue;
                        }
                        dis[v] = dis[u] + w;
                        init(v, u);
                }
        };

        function<void()> dijkstra = [&]() {
                vector<bool> vis(n);
                priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
                for (int i = 0; i < n; ++i) {
                        q.push({ dis[i], i });
                }
                while (!q.empty()) {
                        int u = q.top().second;
                        q.pop();
                        if (vis[u]) {
                                continue;
                        }
                        vis[u] = true;
                        for (auto [v, w] : g[u]) {
                                if (dis[u] + w < dis[v]) {
                                        dis[v] = dis[u] + w;
                                        q.push({ dis[v], v });
                                }
                        }
                }
        };

        dis[0] = 0;
        init(0, -1);
        cout << accumulate(all(dis), 0ll) << endl;
        for (int i = 0; i < n; ++i) {
                vector<ll> temp = dis;
                fill(all(dis), inf);
                for (int u = 0; u < n; ++u) {
                        for (int v : rg[u]) {
                                dis[v] = min(dis[v], temp[u]);
                        }
                }
                dijkstra();
                cout << accumulate(all(dis), 0ll) << endl;
        }

        return 0;
}
