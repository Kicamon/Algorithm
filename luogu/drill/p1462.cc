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
const ll inf = 1e18;
int n, m, b;
vector<ll> f;
vector<vector<array<int, 2>>> g;

bool dijkstra(int p) {
        if (f[0] > p) {
                return false;
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        vector<ll> dis(n, inf);
        vector<bool> vis(n);
        dis[0] = 0;
        q.push({ 0, 0 });
        while (!q.empty()) {
                int u = q.top().second;
                q.pop();
                if (vis[u]) {
                        continue;
                }
                vis[u] = true;
                for (auto &[v, w] : g[u]) {
                        if (v == u || f[v] > p || dis[u] + w > b) {
                                continue;
                        }
                        if (dis[u] + w < dis[v]) {
                                dis[v] = dis[u] + w;
                                q.push({ dis[v], v });
                        }
                }
        }
        return dis[n - 1] != inf;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m >> b;
        g.resize(n), f.resize(n);
        for (ll &x : f) {
                cin >> x;
        }
        int u, v, w;
        while (m--) {
                cin >> u >> v >> w;
                u--, v--;
                g[u].push_back({ v, w }), g[v].push_back({ u, w });
        }
        vector<ll> t;
        for (int x : f) {
                if (x >= f[n - 1]) {
                        t.push_back(x);
                }
        }
        sort(all(t));
        t.erase(unique(all(t)), t.end());
        int l = 0, r = (int)t.size();
        while (l < r) {
                int mid = (l + r) >> 1;
                if (!dijkstra(t[mid])) {
                        l = mid + 1;
                } else {
                        r = mid;
                }
        }
        if (l == (int)t.size()) {
                cout << "AFK" << endl;
        } else {
                cout << t[l] << endl;
        }

        return 0;
}
