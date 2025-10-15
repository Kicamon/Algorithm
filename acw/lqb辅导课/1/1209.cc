#include <iostream>
#include <cstring>
using namespace std;
#define int long long

int n;
int vis[10], cnt[10];
int ans;

bool check(int a, int c) {
        int b = n * c - a * c;

        if (!a || !b || !c)
                return false;

        memcpy(cnt, vis, sizeof vis);
        while (b) {
                int x = b % 10;
                b /= 10;
                if (!x || cnt[x])
                        return false;
                cnt[x] = true;
        }
        for (int i = 1; i <= 9; ++i)
                if (!cnt[i])
                        return false;
        return true;
}

void dfs_c(int u, int a, int c) {
        if (u > 9)
                return;
        if (check(a, c))
                ans++;
        for (int i = 1; i <= 9; ++i)
                if (!vis[i]) {
                        vis[i] = true;
                        dfs_c(u + 1, a, c * 10 + i);
                        vis[i] = false;
                }
}

void dfs_a(int u, int a) {
        if (a >= n)
                return;
        if (a)
                dfs_c(u, a, 0);
        for (int i = 1; i <= 9; ++i) {
                if (!vis[i]) {
                        vis[i] = true;
                        dfs_a(u + 1, a * 10 + i);
                        vis[i] = false;
                }
        }
}

signed main() {
        cin >> n;
        dfs_a(0, 0);
        cout << ans << endl;
        return 0;
}
