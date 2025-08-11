#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> w(n), c(n);
        for (int i = 0; i < n; i++) {
                std::cin >> w[i];
        }
        for (int i = 0; i < n; i++) {
                std::cin >> c[i];
        }

        std::vector<std::vector<int> > adj(n);
        for (int i = 0; i < n - 1; i++) {
                int u, v;
                std::cin >> u >> v;
                u--;
                v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        std::vector<std::set<int> > s(n);
        i64 ans = 0;

        auto color = [&](this auto &&self, int x, int p) -> void {
                c[x] = c[p];
                for (auto y : adj[x]) {
                        if (y == p) {
                                continue;
                        }
                        if (!c[y]) {
                                self(y, x);
                        }
                }
        };

        auto dfs = [&](this auto &&self, int x, int p) -> void {
                std::vector<int> a;
                for (auto y : adj[x]) {
                        if (y == p) {
                                continue;
                        }
                        self(y, x);
                        if (s[x].size() < s[y].size()) {
                                std::swap(s[x], s[y]);
                        }
                        for (auto v : s[y]) {
                                if (s[x].contains(v)) {
                                        a.push_back(v);
                                } else {
                                        s[x].insert(v);
                                }
                        }
                }

                std::sort(a.begin(), a.end());
                a.erase(std::unique(a.begin(), a.end()), a.end());

                if (a.size() > 1 || (a.size() == 1 && c[x] && a[0] != c[x])) {
                        ans += w[x];
                }

                if (c[x]) {
                        s[x].insert(c[x]);
                } else if (!a.empty()) {
                        c[x] = a[0];
                } else if (!s[x].empty()) {
                        c[x] = *s[x].begin();
                }
                if (c[x]) {
                        for (auto y : adj[x]) {
                                if (y == p) {
                                        continue;
                                }
                                if (!c[y]) {
                                        color(y, x);
                                }
                        }
                }
        };
        dfs(0, -1);

        for (int i = 0; i < n; i++) {
                if (!c[i]) {
                        c[i] = 1;
                }
        }

        std::cout << ans << "\n";
        for (int i = 0; i < n; i++) {
                std::cout << c[i] << " \n"[i == n - 1];
        }
}

int main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int t;
        std::cin >> t;

        while (t--) {
                solve();
        }

        return 0;
}
