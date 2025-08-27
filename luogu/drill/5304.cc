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
#include <queue>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const ll inf = 1e16;

int bl(int x) {
        int len = 0;
        while (x) {
                len++;
                x >>= 1;
        }
        return len;
}

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<array<int, 2> > > g(n + 2), G;
        vector<int> nk(k);
        vector<ll> dis(n + 2);
        vector<bool> vis(n + 2);
        int u, v, w;
        while (m--) {
                cin >> u >> v >> w;
                if (u == v) {
                        continue;
                }
                g[u].push_back({ v, w });
        }
        int len = 0;
        for (int &x : nk) {
                cin >> x;
                len = max(len, bl(x));
        }

        ll ans = inf;
        function<void(int)> dijkstra = [&](int p) {
                fill(all(dis), inf), fill(all(vis), false);
                priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
                q.push({ 0, p });
                dis[p] = 0;
                while (!q.empty()) {
                        u = q.top().second;
                        q.pop();
                        if (vis[u]) {
                                continue;
                        }
                        vis[u] = true;
                        for (auto [v, w] : G[u]) {
                                if (dis[u] + w < dis[v]) {
                                        dis[v] = dis[u] + w;
                                        q.push({ dis[v], v });
                                }
                        }
                }
                ans = min(ans, dis[n + 1 - p]);
        };

        for (int i = 0; i < len; ++i) {
                G = g;
                for (int x : nk) {
                        if (x >> i & 1) {
                                G[0].push_back({ x, 0 });
                                G[x].push_back({ 0, 0 });
                        } else {
                                G[n + 1].push_back({ x, 0 });
                                G[x].push_back({ n + 1, 0 });
                        }
                }
                dijkstra(0), dijkstra(n + 1);
        }
        cout << ans << endl;
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
