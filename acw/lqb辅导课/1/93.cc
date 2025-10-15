#include <iostream>
using namespace std;

int n, m;

int ans[30];

void dfs(int u, int last) {
        if (u == m) {
                for (int i = 0; i < m; ++i)
                        cout << ans[i] << ' ';
                cout << endl;
                return;
        }
        for (int i = last; i <= n; ++i) {
                ans[u] = i;
                dfs(u + 1, i + 1);
        }
}

int main() {
        cin >> n >> m;
        dfs(0, 1);
        return 0;
}
