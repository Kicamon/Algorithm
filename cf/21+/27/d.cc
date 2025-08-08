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
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

ll fac[N];

struct DSU {
        vector<int> f, siz;

        DSU(int n) {
                f.resize(n);
                iota(all(f), 0);
                siz.assign(n, 1);
        }

        int find(int x) {
                while (x != f[x]) {
                        x = f[x] = f[f[x]];
                }
                return x;
        }

        bool merge(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) {
                        return false;
                }
                f[y] = x;
                siz[x] += siz[y];
                return true;
        }

        bool same(int x, int y) {
                return find(x) == find(y);
        }

        int size(int x) {
                return siz[find(x)];
        }
};

void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > g(n + 1);
        vector<bool> vis(n + 1, 1);
        DSU dsu(n + 1);
        bool flag = false;
        for (int i = 0, a, b; i < m; ++i) {
                cin >> a >> b;
                if (!dsu.merge(a, b)) {
                        flag = true;
                }
                g[a].push_back(b), g[b].push_back(a);
        }

        if (flag) {
                cout << 0 << endl;
                return;
        }

        function<ll(int)> get_num = [&](int root) {
                ll ans = 1;
                int tag = g[root].size() > 1, res = 0;

                queue<int> q;
                q.push(root);
                while (!q.empty()) {
                        int node = q.front();
                        q.pop();
                        vis[node] = false;
                        tag++;
                        for (int s : g[node]) {
                                if (g[s].size() > 1) {
                                        if (vis[s]) {
                                                q.push(s);
                                        }
                                } else {
                                        res++;
                                        vis[s] = false;
                                }
                        }
                        (ans *= fac[res]) %= mod;
                        res = 0;
                }
                if (tag > 2) {
                        (ans *= 4) %= mod;
                } else {
                        (ans *= 2) %= mod;
                }

                return ans;
        };

        ll ans = 1;
        for (int i = 1; i <= n; ++i) {
                if (vis[i]) {
                        (ans *= get_num(i)) %= mod;
                }
        }
        cout << ans << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        fac[0] = 1;
        for (int i = 1; i < N; ++i) {
                fac[i] = fac[i - 1] * i % mod;
        }

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
