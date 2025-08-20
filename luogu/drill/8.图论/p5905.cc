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
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int inf = 1e9;
int n, m;
vector<vector<array<int, 2> > > g;
vector<ll> h;

void dijkstra(int x) {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
        vector<ll> dis(n + 1, inf);
        vector<bool> vis(n + 1);
        dis[x] = 0;
        q.push({ 0, x });
        while (!q.empty()) {
                auto t = q.top();
                q.pop();
                if (vis[t.second]) {
                        continue;
                }
                vis[t.second] = true;
                for (const auto &x : g[t.second]) {
                        if (dis[t.second] + x[1] + h[t.second] - h[x[0]] < dis[x[0]]) {
                                dis[x[0]] = dis[t.second] + x[1] + h[t.second] - h[x[0]];
                                q.push({ dis[x[0]], x[0] });
                        }
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
                if (dis[i] == inf) {
                        ans += dis[i] * i;
                } else {
                        ans += (dis[i] - h[x] + h[i]) * i;
                }
        }
        cout << ans << endl;
}

bool spfa() {
        queue<int> q;
        vector<int> cnt(n + 1), vis(n + 1);
        vis[0] = true;
        q.push(0);
        h[0] = 0;
        while (!q.empty()) {
                auto t = q.front();
                q.pop();
                vis[t] = false;
                for (const auto &x : g[t]) {
                        if (h[t] + x[1] < h[x[0]]) {
                                h[x[0]] = h[t] + x[1];
                                if (!vis[x[0]]) {
                                        cnt[x[0]] = cnt[t] + 1;
                                        if (cnt[x[0]] >= n) {
                                                return false;
                                        }
                                        vis[x[0]] = true;
                                        q.push(x[0]);
                                }
                        }
                }
        }
        return true;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m;
        g.resize(n + 1), h.resize(n + 1, inf);
        int u, v, w;
        while (m--) {
                cin >> u >> v >> w;
                g[u].push_back({ v, w });
        }
        for (int i = 1; i <= n; ++i) {
                g[0].push_back({ i, 0 });
        }
        if (!spfa()) {
                cout << -1 << endl;
                return 0;
        }
        for (int i = 1; i <= n; ++i) {
                dijkstra(i);
        }

        return 0;
}
