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
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << ' ';
#define all(x) (x).begin(), (x).end()
#define PDI pair<double, int>
const int N = 155, inf = 1e9;
int n, m, d;

vector<vector<double> > V(N, vector<double>(N, inf));
vector<vector<array<int, 2> > > g(N, vector<array<int, 2> >(N));
array<bool, N> vis;

double get(int a, int b) {
        return double(a) / b;
}

void change(int t, int u) {
        for (int i = 0; i < n; ++i) {
                if (!g[i][t][0]) {
                        continue;
                }
                if (V[i][u] > get(g[i][t][1] + g[t][u][1], g[i][t][0])) {
                        V[i][u] = get(g[i][t][1] + g[t][u][1], g[i][t][0]);
                        g[i][u] = { g[i][t][0], g[i][t][1] + g[t][u][1] };
                }
        }
}

void init(int u) {
        for (int i = 0; i < n; ++i) {
                if (i == u || vis[i]) {
                        continue;
                }
                vis[i] = true;
                if (!g[u][i][0] && g[u][i][1]) {
                        change(u, i);
                        g[u][i][1] = 0;
                }
                init(i);
                vis[i] = false;
        }
}

vector<int> ans, temp;
vector<double> dis;

void dfs(int u) {
        temp.push_back(u);
        if (u == d) {
                ans = temp;
                temp.pop_back();
                return;
        }
        for (int i = 0; i < n; ++i) {
                if (i == u) {
                        continue;
                }
                if (dis[u] + V[u][i] < dis[i]) {
                        dis[i] = dis[u] + V[u][i];
                        if (i == d || dis[i] < dis[d]) {
                                dfs(i);
                        }
                }
        }
        temp.pop_back();
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m >> d;
        dis.resize(n, inf);
        int a, b, v, l;
        while (m--) {
                cin >> a >> b >> v >> l;
                if (!a && !v) {
                        v = 70;
                }
                g[a][b] = { v, l };
                if (v) {
                        V[a][b] = get(l, v);
                }
        }
        vis[0] = true;
        init(0);
        dis[0] = 0;
        dfs(0);
        for (int x : ans) {
                cout << x << ' ';
        }
        cout << endl;

        return 0;
}
