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
using ll = long long;

class DINIC {
    private:
        const ll suf = 1e18;

        struct node {
                int rev, to;
                ll cap, flow;
                node(int r, int t, ll c) {
                        rev = r, to = t, cap = c, flow = 0;
                }
        };

        vector<vector<node>> g;
        vector<int> dep, iter;

    public:
        DINIC(int n) {
                g.resize(n), dep.resize(n), iter.resize(n);
        }

        void add_edge(int u, int v, int w) {
                g[u].push_back({ (int)g[v].size(), v, w });
                g[v].push_back({ (int)g[u].size() - 1, u, 0 });
        }

        bool bfs(const int &s, const int &t) {
                fill(dep.begin(), dep.end(), 0);
                queue<int> q;
                dep[s] = 1;
                q.push(s);
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

        ll dfs(int u, ll value, const int &t) {
                if (u == t) {
                        return value;
                }

                for (int &i = iter[u]; i < (int)g[u].size(); ++i) {
                        auto &[rev, v, cap, flow] = g[u][i];
                        if (dep[v] != dep[u] + 1 || cap <= flow) {
                                continue;
                        }
                        ll d;
                        if ((d = dfs(v, min(value, cap - flow), t)) > 0) {
                                flow += d;
                                g[v][rev].flow -= d;
                                return d;
                        }
                }

                return 0;
        }

        int max_flow(int s, int t) {
                ll flow = 0;
                while (bfs(s, t)) {
                        ll f;
                        fill(iter.begin(), iter.end(), 0);
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

        DINIC din(n + 1);
        for (int i = 0, u, v, w; i < m; ++i) {
                cin >> u >> v >> w;
                din.add_edge(u, v, w);
        }
        cout << din.max_flow(s, t) << '\n';

        return 0;
}
