/**
 *    author:  tourist
 *    created: 07.08.2025 07:57:27
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tt;
        cin >> tt;
        while (tt--) {
                int n, k;
                cin >> n >> k;
                vector<int> w(n);
                for (int i = 0; i < n; i++) {
                        cin >> w[i];
                }
                vector<int> c(n);
                for (int i = 0; i < n; i++) {
                        cin >> c[i];
                }
                vector<vector<int> > g(n);
                for (int i = 0; i < n - 1; i++) {
                        int x, y;
                        cin >> x >> y;
                        --x;
                        --y;
                        g[x].push_back(y);
                        g[y].push_back(x);
                }
                vector<int> order;
                vector<int> pv(n, -1);
                vector<set<int> > s(n);
                int64_t ans = 0;
                auto Dfs = [&](auto &&self, int v, int pr) -> void {
                        order.push_back(v);
                        pv[v] = pr;
                        vector<int> cand;
                        for (int u : g[v]) {
                                if (u == pr) {
                                        continue;
                                }
                                self(self, u, v);
                                if (s[u].size() > s[v].size()) {
                                        swap(s[u], s[v]);
                                }
                                for (int x : s[u]) {
                                        if (!(s[v].insert(x).second)) {
                                                cand.push_back(x);
                                        }
                                }
                                set<int>().swap(s[u]);
                        }
                        sort(cand.begin(), cand.end());
                        cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
                        if (c[v] == 0) {
                                if (cand.size() == 1) {
                                        c[v] = cand[0];
                                } else {
                                        if (cand.size() > 1) {
                                                ans += w[v];
                                        }
                                        if (!s[v].empty()) {
                                                c[v] = *s[v].begin();
                                        }
                                }
                        } else {
                                if (cand.size() == 0 || (cand.size() == 1 && cand[0] == c[v])) {
                                        // pass
                                } else {
                                        ans += w[v];
                                }
                        }
                        if (c[v] > 0) {
                                s[v].insert(c[v]);
                        }
                };
                Dfs(Dfs, 0, -1);
                if (c[0] == 0) {
                        c[0] = 1;
                }
                for (int i : order) {
                        if (c[i] == 0) {
                                assert(pv[i] >= 0);
                                c[i] = c[pv[i]];
                        }
                }
                for (int i = 0; i < n; i++) {
                        assert(c[i] != 0);
                }
                cout << ans << '\n';
                for (int i = 0; i < n; i++) {
                        cout << c[i] << " \n"[i == n - 1];
                }
        }
        return 0;
}
