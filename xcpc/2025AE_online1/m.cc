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
#define pli pair<ll, int>
const ll inf = 1e18;

vector<vector<array<int, 2> > > g;
vector<vector<ll> > dis;
vector<vector<bool> > vis;

struct node {
        ll val;
        int t;
        int nid;
        bool operator<(const node &p) const {
                return val < p.val;
        }
        bool operator>(const node &p) const {
                return val > p.val;
        }
};

void dijkstra() {
        priority_queue<node, vector<node>, greater<node> > q;
        dis[0][0] = 0;
        q.push({ 0, 0, 0 });
        while (!q.empty()) {
                auto [_, t, u] = q.top();
                q.pop();
                if (vis[u][t]) {
                        continue;
                }
                vis[u][t] = true;
                for (auto [v, w] : g[u]) {
                        if (!w && t <= (int)dis.size() && dis[u][t] < dis[v][t + 1]) {
                                dis[v][t + 1] = dis[u][t];
                                q.push({ dis[v][t + 1], t + 1, v });
                        }
                        if (w && dis[u][t] + w < dis[v][t]) {
                                dis[v][t] = dis[u][t] + w;
                                q.push({ dis[v][t], t, v });
                        }
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        g.resize(n);
        dis.assign(n, vector<ll>(n + 1, inf));
        vis.assign(n, vector<bool>(n));
        for (int i = 1, u, v, w; i < n; ++i) {
                cin >> u >> v >> w;
                u--, v--;
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
        }
        for (int i = 0, u, v; i < m; ++i) {
                cin >> u >> v;
                u--, v--;
                g[u].push_back({ v, 0 });
                g[v].push_back({ u, 0 });
        }
        dijkstra();
        for (int j = 0; j <= n; ++j) {
                ll ans = 0;
                for (int i = 0; i < n; ++i) {
                        if (j) {
                                dis[i][j] = min(dis[i][j], dis[i][j - 1]);
                        }
                        ans += dis[i][j];
                }
                cout << ans << endl;
        }

        return 0;
}
