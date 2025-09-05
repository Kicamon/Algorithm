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
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int inf = 1e9;

vector<vector<array<int, 2> > > g;
vector<ll> h;

bool spfa(int n) {
        queue<int> q;
        vector<bool> vis(n + 1);
        vector<int> dep(n + 1);
        q.push(0);
        vis[0] = true;
        h[0] = 0;
        while (!q.empty()) {
                int u = q.front();
                q.pop();
                vis[u] = false;
                for (auto [v, w] : g[u]) {
                        if (h[u] + w < h[v]) {
                                h[v] = h[u] + w;
                                if (vis[v]) {
                                        continue;
                                }
                                vis[v] = true;
                                q.push(v);
                                dep[v] = dep[u] + 1;
                                if (dep[v] >= n) {
                                        return false;
                                }
                        }
                }
        }
        return true;
}

void dijkstra(int root, int n) {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
        vector<bool> vis(n + 1);
        vector<ll> dis(n + 1, inf);
        q.push({ 0, root });
        dis[root] = 0;
        while (!q.empty()) {
                int u = q.top().second;
                q.pop();
                if (vis[u]) {
                        continue;
                }
                vis[u] = true;
                for (auto [v, w] : g[u]) {
                        if (dis[u] + w + h[u] - h[v] < dis[v]) {
                                dis[v] = dis[u] + w + h[u] - h[v];
                                q.push({ dis[v], v });
                        }
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
                if (dis[i] == inf) {
                        ans += dis[i] * i;
                } else {
                        ans += (dis[i] - h[root] + h[i]) * i;
                }
        }
        cout << ans << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        g.resize(n + 1), h.resize(n + 1, inf);
        for (int i = 0, u, v, w; i < m; ++i) {
                cin >> u >> v >> w;
                if (u == v) {
                        continue;
                }
                g[u].push_back({ v, w });
        }
        for (int i = 1; i <= n; ++i) {
                g[0].push_back({ i, 0 });
        }
        if (!spfa(n)) {
                cout << -1 << endl;
        } else {
                for (int i = 1; i <= n; ++i) {
                        dijkstra(i, n);
                }
        }

        return 0;
}
