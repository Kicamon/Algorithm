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
#include <queue>
#include <utility>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int inf = 1e9 + 10;

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m, q;
        cin >> n >> m >> q;
        vector<array<int, 3> > a(m);
        vector<vector<array<int, 2> > > g(n);
        vector<int> dep(n);
        int max_dep = 0;
        for (auto &x : a) {
                cin >> x[0] >> x[1] >> x[2];
                x[0]--, x[1]--;
                g[x[0]].push_back({ x[1], x[2] });
                g[x[1]].push_back({ x[0], x[2] });
        }

        function<void(vector<ll> &, int)> dijkstra = [&](vector<ll> &dis, int p) {
                vector<bool> vis(n);
                priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
                q.push({ 0, p });
                dis[p] = 0;
                dep[p] = 0;
                while (!q.empty()) {
                        int u = q.top().second;
                        q.pop();
                        if (vis[u]) {
                                continue;
                        }
                        vis[u] = true;
                        for (auto [v, w] : g[u]) {
                                if (dis[u] + w < dis[v]) {
                                        dep[v] = dep[u] + 1;
                                        max_dep = max(max_dep, dep[v]);
                                        dis[v] = dis[u] + w;
                                        q.push({ dis[v], v });
                                }
                        }
                }
        };

        vector<ll> dis(n, inf), rdis(n, inf);
        dijkstra(rdis, n - 1), dijkstra(dis, 0);

        vector<array<ll, 2> > Q(max_dep + 1, { inf, inf });
        for (auto &[u, v, w] : a) {
                if (dep[u] > dep[v]) {
                        swap(u, v);
                }
                if (rdis[0] < max(rdis[u], rdis[v])) {
                        continue;
                }
                int d = dep[v];
                if (dis[u] + w + rdis[v] <= Q[d][0]) {
                        Q[d][1] = Q[d][0];
                        Q[d][0] = dis[u] + w + rdis[v];
                } else if (dis[u] + w + rdis[v] < Q[d][1]) {
                        Q[d][1] = dis[u] + w + rdis[v];
                }
        }

        int t, x;
        while (q--) {
                cin >> t >> x;
                t--;
                auto [u, v, w] = a[t];
                if (dep[u] > dep[v]) {
                        swap(u, v);
                }
                if (rdis[0] < max(rdis[u], rdis[v])) {
                        cout << min(dis[n - 1], dis[u] + x + rdis[v]) << endl;
                } else if (dis[u] + rdis[v] + w == dis[n - 1]) {
                        int d = dep[v];
                        if (Q[d][1] == inf) {
                                cout << dis[u] + x + rdis[v] << endl;
                        } else {
                                cout << min(dis[u] + x + rdis[v], Q[d][1]) << endl;
                        }
                } else {
                        cout << min(dis[n - 1], dis[u] + x + rdis[v]) << endl;
                }
        }

        return 0;
}
