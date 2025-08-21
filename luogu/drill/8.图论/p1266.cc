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
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 155, inf = 0x3f3f3f3f;
int n, m, d, temp;

vector<vector<array<int, 2> > > g(N, vector<array<int, 2> >(N));
vector<vector<int> > G(N, vector<int>(N));
vector<int> dis(N, inf);
vector<bool> vis(N);

int get(array<int, 2> a) {
        return a[1] * (temp / a[0]);
}

void init() {
        priority_queue<array<int, 2>, vector<array<int, 2> >, greater<array<int, 2> > > q;

        function<void(int, int)> f = [&](int u, int v) {
                for (int i = 0; i < n; ++i) {
                        if (!vis[i] || i == u || i == v || !g[i][u][1]) {
                                continue;
                        }
                        if (!g[i][v][1] ||
                            get(g[i][v]) > get({ g[i][u][0], g[i][u][1] + g[u][v][1] })) {
                                g[i][v] = { g[i][u][0], g[i][u][1] + g[u][v][1] };
                        }
                        if (dis[i] + get(g[i][v]) < dis[v]) {
                                dis[v] = dis[i] + get(g[i][v]);
                        }
                }
        };

        dis[0] = 0;
        q.push({ 0, 0 });
        while (!q.empty()) {
                int t = q.top()[1];
                q.pop();
                if (vis[t]) {
                        continue;
                }
                vis[t] = true;
                for (int i = 0; i < n; ++i) {
                        if (i == t || !g[t][i][1]) {
                                continue;
                        }
                        if (!g[t][i][0]) {
                                f(t, i);
                                g[t][i] = { 0, 0 };
                        } else if (dis[t] + get(g[t][i]) < dis[i]) {
                                dis[i] = dis[t] + get(g[t][i]);
                                q.push({ dis[i], i });
                        }
                }
        }
}

vector<int> ans;
void dfs(int u, int v) {
        ans.push_back(u);
        if (u == d) {
                for (int x : ans) {
                        cout << x << ' ';
                }
                cout << endl;
                return;
        }
        for (int i = 0; i < n; ++i) {
                if (i == u || vis[i] || !G[u][i] || G[u][i] + v > min(dis[d], dis[i])) {
                        continue;
                }
                vis[i] = true;
                dfs(i, v + G[u][i]);
                vis[i] = false;
        }
        ans.pop_back();
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m >> d;
        int a, b, v, l;
        while (m--) {
                cin >> a >> b >> v >> l;
                if (!a && !v) {
                        v = 70;
                }
                g[a][b] = { v, l };
                if (!temp) {
                        temp = v;
                }
                if (v) {
                        temp = temp * v / __gcd(temp, v);
                }
        }
        init();
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (g[i][j][0]) {
                                G[i][j] = get(g[i][j]);
                        }
                }
        }
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        printf("%-10d", G[i][j]);
                }
                printf("\n");
        }
        fill(all(vis), false);
        vis[0] = true;
        dfs(0, 0);

        return 0;
}
