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
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class DINIC {
    private:
        const int suf = 0x3f3f3f3f;

        struct node {
                int rev, to, cap, flow;
                node(int r, int t, int c, int f) {
                        rev = r, to = t, cap = c, flow = f;
                }
        };

        int n;
        vector<int> dep, iter;
        vector<vector<node>> g;

    public:
        DINIC(int _n) {
                n = _n;
                g.resize(n), dep.resize(n), iter.resize(n);
        }

        void add_edge(int u, int v, int w) {
                g[u].push_back(node(g[v].size(), v, w, 0));
                g[v].push_back(node(g[u].size() - 1, u, 0, 0));
        }

        bool bfs(const int &s, const int &t) {
                fill(dep.begin(), dep.end(), 0);
                queue<int> q;
                q.push(s);
                dep[s] = 1;
                while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        for (auto [_, v, cap, flow] : g[u]) {
                                if (!dep[v] && cap > flow) {
                                        dep[v] = dep[u] + 1;
                                        q.push(v);
                                }
                        }
                }
                return dep[t];
        }

        int dfs(int u, int value, const int &t) {
                if (u == t) {
                        return value;
                }

                for (int &i = iter[u]; i < (int)g[u].size(); ++i) {
                        auto &[rev, v, cap, flow] = g[u][i];
                        if (dep[v] != dep[u] + 1 || cap <= flow) {
                                continue;
                        }
                        int d = dfs(v, min(value, cap - flow), t);
                        if (d > 0) {
                                flow += d;
                                g[v][rev].flow -= d;
                                return d;
                        }
                }
                return 0;
        }

        int max_flow(const int &s, const int &t) {
                int flow = 0;
                while (bfs(s, t)) {
                        fill(iter.begin(), iter.end(), 0);
                        int f;
                        while ((f = dfs(s, suf, t)) > 0) {
                                flow += f;
                        }
                }
                return flow;
        }
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m, s, t;
        cin >> n >> m >> s >> t;
        DINIC di(n + 1);
        for (int i = 0, u, v, w; i < m; ++i) {
                cin >> u >> v >> w;
                di.add_edge(u, v, w);
        }
        cout << di.max_flow(s, t) << '\n';

        return 0;
}
