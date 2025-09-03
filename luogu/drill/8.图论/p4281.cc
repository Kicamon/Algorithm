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
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

vector<vector<int> > g;
vector<int> dep;
vector<vector<int> > fa;
int mdep;

struct node {
        int idx;
        int val;
        bool operator<(node &t) const {
                return val < t.val;
        }
};

int get_mdep(int n) {
        int res = 1;
        while (1 << res < n) {
                res++;
        }
        return res;
}

void dfs(int u, int f) {
        for (int v : g[u]) {
                if (v == f) {
                        continue;
                }
                dep[v] = dep[u] + 1;
                fa[v][0] = u;
                for (int i = 1; i <= mdep; ++i) {
                        fa[v][i] = fa[fa[v][i - 1]][i - 1];
                }
                dfs(v, u);
        }
}

int lca(int a, int b) {
        if (dep[a] < dep[b]) {
                swap(a, b);
        }
        for (int i = mdep; ~i; --i) {
                if (dep[fa[a][i]] >= dep[b]) {
                        a = fa[a][i];
                }
        }
        if (a == b) {
                return a;
        }
        for (int i = mdep; ~i; --i) {
                if (fa[a][i] != fa[b][i]) {
                        a = fa[a][i];
                        b = fa[b][i];
                }
        }
        return fa[a][0];
}

int get_val(int x, int y, int z, int t) {
        return abs(dep[x] - dep[t]) + abs(dep[y] - dep[t]) + abs(dep[z] - dep[t]);
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        mdep = get_mdep(n + 1);
        g.resize(n + 1), dep.resize(n + 1);
        fa.assign(n + 1, vector<int>(mdep + 1, 0));
        for (int i = 1, a, b; i < n; ++i) {
                cin >> a >> b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        dep[1] = 1;
        dfs(1, 0);
        fa[1][0] = 1;
        vector<node> t(3);
        while (m--) {
                int x, y, z;
                cin >> x >> y >> z;
                t[0].idx = lca(x, y);
                t[0].val = get_val(x, y, z, t[0].idx);
                t[1].idx = lca(y, z);
                t[1].val = get_val(x, y, z, t[1].idx);
                t[2].idx = lca(x, z);
                t[2].val = get_val(x, y, z, t[2].idx);
                sort(all(t));
                cout << t[0].idx << ' ' << t[0].val << endl;
        }

        return 0;
}
