#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
struct DSU {
        std::vector<int> f, siz;

        DSU() {
        }
        DSU(int n) {
                init(n);
        }

        void init(int n) {
                f.resize(n);
                std::iota(f.begin(), f.end(), 0);
                siz.assign(n, 1);
        }

        int find(int x) {
                while (x != f[x]) {
                        x = f[x] = f[f[x]];
                }
                return x;
        }

        bool same(int x, int y) {
                return find(x) == find(y);
        }

        bool merge(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) {
                        return false;
                }
                siz[x] += siz[y];
                f[y] = x;
                return true;
        }

        int size(int x) {
                return siz[find(x)];
        }
};
void solve() {
        int n;
        std::cin >> n;

        DSU dsu(2 * n);
        std::vector<int> ans;
        for (int i = 0; i < n; i++) {
                int a, b;
                std::cin >> a >> b;
                a--;
                b--;
                if (dsu.merge(a, b)) {
                        ans.push_back(i + 1);
                }
        }

        std::cout << ans.size() << "\n";
        for (auto x : ans) {
                std::cout << x << " \n"[x == ans.back()];
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
