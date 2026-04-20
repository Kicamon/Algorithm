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
//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define Debug(x) cout << #x << ':' << x << endl
int input = 0;

const int N = 5e4 + 10, M = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int a[5];

int e[M], ne[M], w[M], h[N], idx;

void add(int a, int b, int c) {
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[N];
bool vis[N];

void dijkstra(int start) {
        memset(dist, 0x3f, sizeof dist);
        memset(vis, 0, sizeof(vis));
        dist[start] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
        q.push({ 0, start });
        while (!q.empty()) {
                array<int, 2> t = q.top();
                q.pop();

                if (vis[t[1]])
                        continue;
                vis[t[1]] = true;

                for (int i = h[t[1]]; ~i; i = ne[i]) {
                        int j = e[i];
                        if (dist[j] > dist[t[1]] + w[i]) {
                                dist[j] = dist[t[1]] + w[i];
                                q.push({ dist[j], j });
                        }
                }
        }
}

bool st[5];
int d[5];
int g[5][5];
int ans = inf;
void dfs(int u, int fa, int res) {
        if (u == 5) {
                ans = min(res, ans);
                return;
        }
        for (int i = 0; i < 5; ++i) {
                if (st[i])
                        continue;
                st[i] = true;
                dfs(u + 1, i, res + g[fa][i]);
                st[i] = false;
        }
}

void solve() {
        memset(h, -1, sizeof h);
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < 5; ++i)
                cin >> a[i];
        while (m--) {
                int a, b, c;
                cin >> a >> b >> c;
                add(a, b, c), add(b, a, c);
        }
        dijkstra(1);
        for (int i = 0; i < 5; ++i)
                d[i] = dist[a[i]];
        memset(g, 0x3f, sizeof g);
        for (int i = 0; i < 5; ++i) {
                dijkstra(a[i]);
                for (int j = 0; j < 5; ++j)
                        g[i][j] = g[j][i] = dist[a[j]];
        }
        for (int i = 0; i < 5; ++i) {
                st[i] = true;
                dfs(1, i, d[i]);
                st[i] = false;
        }
        cout << ans << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        // clock_t start, finish;
        // start = clock();

        int t = 1;
        if (input)
                cin >> t;
        while (t--)
                solve();

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
