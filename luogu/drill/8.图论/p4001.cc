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
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

struct DINIC {
        const int inf = 0x3f3f3f3f;

        struct node {
                int rev, to, cap, flow;
                node(int n, int t, int c, int fl) {
                        rev = n, to = t, cap = c, flow = fl;
                }
        };

        int n;
        vector<vector<node> > e;
        vector<int> dep, iter;

        DINIC(int size) {
                n = size;
                e.resize(n), dep.resize(n), iter.resize(n);
        }

        void add_edge(int u, int v, int w) {
                e[u].push_back(node((int)e[v].size(), v, w, 0));
                e[v].push_back(node((int)e[u].size() - 1, u, w, 0));
        }

        bool bfs(const int &s, const int &t) {
                queue<int> q;
                fill(all(dep), 0);
                q.push(s);
                dep[s] = 1;
                while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        for (auto x : e[u]) {
                                if (!dep[x.to] && x.cap > x.flow) {
                                        dep[x.to] = dep[u] + 1;
                                        if (x.to == t) {
                                                return true;
                                        }
                                        q.push(x.to);
                                }
                        }
                }
                return false;
        }

        int dfs(int u, int flow, const int &t) {
                if (u == t) {
                        return flow;
                }

                for (int &i = iter[u]; i < (int)e[u].size(); ++i) {
                        auto &x = e[u][i];
                        if (dep[x.to] == dep[u] + 1 && x.cap > x.flow) {
                                int d = dfs(x.to, min(flow, x.cap - x.flow), t);
                                if (d > 0) {
                                        x.flow += d;
                                        e[x.to][x.rev].flow -= d;
                                        return d;
                                }
                        }
                }
                return 0;
        }

        int max_flow(const int &s, const int &t) {
                int flow = 0;
                while (bfs(s, t)) {
                        fill(all(iter), 0);
                        int f;
                        while ((f = dfs(s, inf, t)) > 0) {
                                flow += f;
                        }
                }
                return flow;
        }
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        function<int(int, int)> get = [&](int x, int y) { return x * m + y; };

        DINIC di(n * m);
        for (int i = 0, a; i < n; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                        cin >> a;
                        di.add_edge(get(i, j), get(i, j + 1), a);
                }
        }
        for (int i = 0, a; i < n - 1; ++i) {
                for (int j = 0; j < m; ++j) {
                        cin >> a;
                        di.add_edge(get(i, j), get(i + 1, j), a);
                }
        }
        for (int i = 0, a; i < n - 1; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                        cin >> a;
                        di.add_edge(get(i, j), get(i + 1, j + 1), a);
                }
        }
        cout << di.max_flow(get(0, 0), get(n - 1, m - 1)) << endl;

        return 0;
}
