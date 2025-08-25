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
#include <queue>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int inf = 0x3f3f3f3f;

vector<vector<array<int, 2> > > g;
vector<vector<int> > dis;

void dijkstra(int n, int k, int s) {
        priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > q;
        vector<vector<bool> > vis(n, vector<bool>(k + 1));
        q.push({ 0, s, 0 });
        dis[s][0] = 0;
        while (!q.empty()) {
                auto [_, u, x] = q.top();
                q.pop();
                if (vis[u][x]) {
                        continue;
                }
                vis[u][x] = true;
                for (auto [v, w] : g[u]) {
                        if (u == v) {
                                continue;
                        }
                        for (int i = 0; i <= k; ++i) {
                                if (dis[u][i] == inf) {
                                        break;
                                }
                                if ((ll)dis[u][i] + w < dis[v][i]) {
                                        dis[v][i] = dis[u][i] + w;
                                        q.push({ dis[v][i], v, i });
                                }
                                if (i < k && dis[u][i] < dis[v][i + 1]) {
                                        dis[v][i + 1] = dis[u][i];
                                        q.push({ dis[v][i + 1], v, i + 1 });
                                }
                        }
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m, k, s, t;
        cin >> n >> m >> k;
        g.resize(n), dis.resize(n);
        for (auto &x : dis) {
                x.resize(k + 1, inf);
        }
        cin >> s >> t;
        int u, v, w;
        while (m--) {
                cin >> u >> v >> w;
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
        }
        dijkstra(n, k, s);
        int ans = inf;
        for (int i = 0; i <= k; ++i) {
                ans = min(dis[t][i], ans);
        }
        cout << ans << endl;

        return 0;
}
