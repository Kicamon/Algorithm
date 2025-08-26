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
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
#define pli pair<ll, int>
const ll inf = 5e18;

struct Tarjan {
        struct Node {
                int dfn, low;
                Node(int n) {
                        dfn = low = n;
                }

                bool check() {
                        return dfn == low;
                }
        };
        vector<int> scc, scc_size;
        stack<int> s;
        vector<bool> inStack;
        vector<Node> node;
        int n, dfncnt, scc_num;
        vector<vector<array<int, 2> > > g;

        Tarjan(vector<vector<array<int, 2> > > &G) {
                n = (int)G.size();
                scc.resize(n), scc_size.resize(n);
                inStack.resize(n);
                node.resize(n);
                g = G;
        }

        void tarjan(int u) {
                node[u] = Node(dfncnt++);
                inStack[u] = true;
                s.push(u);
                for (auto [v, _] : g[u]) {
                        if (!node[v].dfn) {
                                tarjan(v);
                                node[u].low = min(node[u].low, node[v].low);
                        } else if (inStack[v]) {
                                node[u].low = min(node[u].low, node[v].dfn);
                        }
                }
                if (node[u].check()) {
                        scc_num++;
                        do {
                                scc[s.top()] = scc_num;
                                scc_size[scc_num]++;
                                inStack[s.top()] = false;
                                s.pop();
                        } while (s.top() != u);
                }
        }

        int size() {
                return scc_num;
        }

        int scc_node(int u) {
                return scc[u];
        }
};

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<array<int, 2> > > g(n + 1);
        vector<int> rd(n + 1), nk(k);
        vector<ll> dis(n + 1, inf);

        int u, v, w;
        while (m--) {
                cin >> u >> v >> w;
                if (u == v) {
                        continue;
                }
                g[u].push_back({ v, w });
                rd[v]++;
        }
        for (int &x : nk) {
                cin >> x;
        }
        int idx = 1;
        for (int i = 1; i <= n; ++i) {
                if (rd[i] < rd[idx]) {
                        idx = i;
                }
        }
        for (int i = 1; i <= n; ++i) {
                if (rd[i] == rd[idx]) {
                        g[0].push_back({ i, 0 });
                        if (rd[idx]) {
                                break;
                        }
                }
        }

        Tarjan tj(g);
        tj.tarjan(0);
        int tj_size = tj.size();
        vector<map<int, array<int, 3> > > out_node(tj_size + 1);
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
