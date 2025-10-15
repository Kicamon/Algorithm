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
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
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

        int n, m, k;
        cin >> n >> m >> k;
        vector<array<int, 3>> a(m);
        vector<vector<array<int, 3>>> g(n);
        for (int i = 0, u, v, w; i < m; ++i) {
                cin >> u >> v >> w;
                u--, v--;
                a[i] = { u, v, w };
                g[u].push_back({ v, w, i });
                g[v].push_back({ u, w, i });
        }

        function<void(vector<ll> &, int)> dijkstra = [&](vector<ll> &dis, int start) {
                priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
                vector<bool> vis(n, false);
                dis[start] = 0;
                pq.push({ 0, start });
                while (!pq.empty()) {
                        int u = pq.top().second;
                        pq.pop();
                        if (vis[u])
                                continue;
                        vis[u] = true;
                        for (auto [v, w, i] : g[u]) {
                                if (dis[u] + w < dis[v]) {
                                        dis[v] = dis[u] + w;
                                        pq.push({ dis[v], v });
                                }
                        }
                }
        };

        vector<ll> dis(n, inf), rdis(n, inf);
        dijkstra(dis, 0);
        dijkstra(rdis, n - 1);

        vector<int> inp(m, -1);
        vector<int> l(n, n), r(n, -1);
        int t = 0;
        int u = 0;
        while (u != n - 1) {
                bool found = false;
                for (auto [v, w, i] : g[u]) {
                        if (dis[u] + w == dis[v] && dis[v] + rdis[v] == dis[n - 1]) {
                                inp[i] = t;
                                l[u] = t;
                                r[u] = t - 1;
                                u = v;
                                t++;
                                found = true;
                                break;
                        }
                }
                if (!found)
                        break;
        }
        l[n - 1] = t;
        r[n - 1] = t - 1;

        vector<int> order(n);
        iota(all(order), 0);
        sort(all(order), [&](int x, int y) { return dis[x] < dis[y]; });
        for (int u : order) {
                for (auto [v, w, i] : g[u]) {
                        if (inp[i] != -1)
                                continue;
                        if (dis[u] + w == dis[v]) {
                                l[v] = min(l[v], l[u]);
                        }
                }
        }

        sort(all(order), [&](int x, int y) { return rdis[x] < rdis[y]; });
        for (int u : order) {
                for (auto [v, w, i] : g[u]) {
                        if (inp[i] != -1)
                                continue;
                        if (rdis[u] + w == rdis[v]) {
                                r[v] = max(r[v], r[u]);
                        }
                }
        }

        vector<vector<ll>> add(t + 1), rem(t + 1);
        for (int i = 0; i < m; ++i) {
                if (inp[i] != -1)
                        continue;
                auto [u, v, w] = a[i];
                if (l[u] <= r[v]) {
                        ll cost = dis[u] + w + rdis[v];
                        add[l[u]].push_back(cost);
                        rem[r[v]].push_back(cost);
                }
                if (l[v] <= r[u]) {
                        ll cost = dis[v] + w + rdis[u];
                        add[l[v]].push_back(cost);
                        rem[r[u]].push_back(cost);
                }
        }

        multiset<ll> ms;
        vector<ll> sdis(t, inf);
        for (int i = 0; i < t; ++i) {
                for (ll cost : add[i]) {
                        ms.insert(cost);
                }
                if (!ms.empty()) {
                        sdis[i] = *ms.begin();
                }
                for (ll cost : rem[i]) {
                        auto it = ms.find(cost);
                        if (it != ms.end()) {
                                ms.erase(it);
                        }
                }
        }

        while (k--) {
                int i, x;
                cin >> i >> x;
                i--;
                auto [u, v, w] = a[i];
                if (inp[i] == -1) {
                        cout << min(dis[n - 1], min(dis[u] + x + rdis[v], dis[v] + x + rdis[u]))
                             << endl;
                } else {
                        cout << min(dis[n - 1] - w + x, sdis[inp[i]]) << endl;
                }
        }

        return 0;
}
