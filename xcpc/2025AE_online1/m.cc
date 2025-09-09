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
#define pli pair<ll, int>
const ll inf = 1e18;

int n, m;
vector<vector<array<int, 2> > > g;
vector<vector<int> > rg;
vector<vector<ll> > dis;

void init(int u, int fa) {
        for (auto [v, w] : g[u]) {
                if (v == fa) {
                        continue;
                }
                dis[0][v] = dis[0][u] + w;
                init(v, u);
        }
}

void dijkstra(int dep) {
        priority_queue<pli, vector<pli>, greater<pli> > q;
        vector<bool> vis(n + 1);
        for (int i = 1; i <= n; ++i) {
                q.push({ dis[dep][i], i });
        }
        while (!q.empty()) {
                int u = q.top().second;
                q.pop();
                if (vis[u]) {
                        continue;
                }
                vis[u] = true;
                for (auto [v, w] : g[u]) {
                        if (dis[dep][u] + w < dis[dep][v]) {
                                dis[dep][v] = dis[dep][u] + w;
                                q.push({ dis[dep][v], v });
                        }
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m;
        g.resize(n + 1), rg.resize(n + 1);
        dis.assign(n + 1, vector<ll>(n + 1, inf));
        for (int i = 1, u, v, w; i < n; ++i) {
                cin >> u >> v >> w;
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
        }
        for (int i = 0, u, v; i < m; ++i) {
                cin >> u >> v;
                rg[u].push_back(v);
                rg[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
                rg[i].push_back(i);
        }
        dis[0][1] = 0;
        init(1, 0);
        for (int i = 1; i <= n; ++i) {
                for (int u = 1; u <= n; ++u) {
                        for (int v : rg[u]) {
                                dis[i][v] = min(dis[i][v], dis[i - 1][u]);
                        }
                }
                dijkstra(i);
        }
        for (int i = 0; i <= n; ++i) {
                cout << accumulate(dis[i].begin() + 1, dis[i].end(), 0ll) << endl;
        }

        return 0;
}
