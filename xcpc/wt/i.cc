#include <future>
#include <iostream>
#include <queue>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 1e5 + 10, inf = 1e9;

int n, m, V, t;
vector<vector<array<int, 2> > > g;
vector<array<int, 2> > dis;

void dijkstra() {
        priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > q;
        vector<bool> vis(n + 1);
        dis[t] = { 1, 0 };
        q.push({ 1, 0, t });
        while (!q.empty()) {
                int u = q.top()[2];
                q.pop();
                if (vis[u]) {
                        continue;
                }
                vis[u] = true;
                for (auto [v, w] : g[u]) {
                        if (w > V) {
                                continue;
                        }
                        array<int, 2> temp;
                        if (dis[u][1] + w <= V) {
                                temp = { dis[u][0], dis[u][1] + w };
                        } else {
                                temp = { dis[u][0] + 1, w };
                        }
                        if (temp[0] < dis[v][0] || (temp[0] == dis[v][0] && temp[1] < dis[v][1])) {
                                dis[v] = temp;
                                q.push({ dis[v][0], dis[v][1], v });
                        }
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m >> V >> t;
        g.resize(n + 1), dis.resize(n + 1, { inf, inf });
        for (int i = 0, u, v, w; i < m; ++i) {
                cin >> u >> v >> w;
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
        }
        dijkstra();
        for (int i = 1; i <= n; ++i) {
                if (dis[i][0] == inf) {
                        cout << -1 << " \n"[i == n];
                } else {
                        cout << dis[i][0] << " \n"[i == n];
                }
        }

        return 0;
}
