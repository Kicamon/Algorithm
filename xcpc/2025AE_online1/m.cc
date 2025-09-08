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
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <ratio>
#include <set>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const ll inf = 1e18;

struct EDGE {
        ll val;
        int u, v;
};

struct cmp {
        bool operator()(const EDGE &a, const EDGE &b) {
                return a.val > b.val;
        };
};

int n, m;
vector<vector<array<int, 2> > > g;
vector<ll> dis;
vector<bool> vis;
vector<int> stn;

void dijkstra() {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
        dis[1] = 0;
        q.push({ 0, 1 });
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
}

void dfs(int u, int fa) {
        vis[u] = true;
        stn[u] = 1;
        for (auto [v, w] : g[u]) {
                if (v == fa || vis[v] || dis[u] + w > dis[v]) {
                        continue;
                }
                dfs(v, u);
                stn[u] += stn[v];
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m;
        g.resize(n + 1), vis.resize(n + 1), stn.resize(n + 1);
        dis.resize(n + 1, inf);
        map<array<int, 2>, int> add_eg;
        for (int i = 1, u, v, w; i < n; ++i) {
                cin >> u >> v >> w;
                if (u > v) {
                        swap(u, v);
                }
                if (add_eg.count({ u, v })) {
                        add_eg[{ u, v }] = min(add_eg[{ u, v }], w);
                } else {
                        add_eg[{ u, v }] = w;
                }
        }
        for (auto [f, w] : add_eg) {
                auto [u, v] = f;
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
        }
        dijkstra();
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
                ans += dis[i];
        }
        fill(all(vis), false);
        dfs(1, 0);
        vector<vector<int> > qm(n + 1);
        for (int i = 0, u, v; i < m; ++i) {
                cin >> u >> v;
                if (dis[u] < dis[v]) {
                        swap(u, v);
                }
                qm[u].push_back(v);
        }
        vector<queue<int> > q(n + 1);
        set<int> hq;
        for (int i = 2; i <= n; ++i) {
                if (qm[i].empty()) {
                        continue;
                }
                sort(all(qm[i]), [](int x, int y) { return dis[x] < dis[y]; });
                for (int x : qm[i]) {
                        q[i].push(x);
                }
                hq.insert(i);
        }
        cout << ans << endl;
        for (int i = 0; i < n; ++i) {
                set<int> t;
                for (int j : hq) {
                        ans -= (dis[j] - dis[q[j].front()]) * stn[j];
                        Debug(ans);
                        cout << j << ' ' << q[j].front() << endl;
                        q[j].pop();
                        if (q[j].empty()) {
                                t.insert(j);
                        }
                }
                for (int x : t) {
                        hq.erase(x);
                }
                cout << max(ans, 0ll) << endl;
        }

        return 0;
}
