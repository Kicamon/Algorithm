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
#include <set>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;

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
                        return true;
                }
                f[y] = x;
                siz[x] += siz[y];
                return false;
        }

        bool same(int x, int y) {
                return find(x) == find(y);
        }

        int size(int x) {
                return siz[find(x)];
        }
};

ll funci(int res) {
        ll ans = 1;
        res++;
        while (--res) {
                (ans *= res) %= mod;
        }
        return ans;
}

void solve() {
        int n, m;
        cin >> n >> m;
        vector<array<int, 2> > a(m);
        vector<vector<int> > g(m + 1);
        vector<int> tag(m + 1);
        set<int> st;
        DSU dsu(n + 1);
        for (auto &x : a) {
                cin >> x[0] >> x[1];
                g[x[0]].push_back(x[1]);
                g[x[1]].push_back(x[0]);
        }
        for (auto x : a) {
                if (dsu.merge(x[0], x[1])) {
                        cout << 0 << endl;
                        return;
                }
                int f = dsu.find(x[0]);
                if (!st.count(f)) {
                        st.insert(f);
                }
                tag[f] = 1;
                if (!tag[x[0]]) {
                        for (int y : g[x[0]]) {
                                tag[y] = 1;
                        }
                }
                if (!tag[x[1]]) {
                        for (int y : g[x[1]]) {
                                tag[y] = 1;
                        }
                }
        }
        for (int i = 1; i <= n; ++i) {
                int f = dsu.find(i);
                if (f != i) {
                        tag[f] += tag[i];
                }
        }

        function<ll(int)> get_num = [&](int t) {
                int res = 0;
                ll ans = 0;
                queue<int> q;
                q.push(t);

                while (!q.empty()) {
                        int temp = q.front();
                        q.pop();
                        for (int x : g[temp]) {
                                if (g[x].size() > 1) {
                                        q.push(x);
                                } else {
                                        res++;
                                }
                        }
                        (ans += funci(res)) %= mod;
                        res = 0;
                }

                return ans;
        };

        ll ans = 1;
        for (int x : st) {
                ll res = get_num(x);
                if (tag[x] > 1) {
                        (res *= 4) %= mod;
                } else {
                        (res *= 2) %= mod;
                }
                (ans *= res) %= mod;
        }
        cout << ans << endl;
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
