//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long
const int N = 1e5 + 10;

int e[N << 1], ne[N << 1], h[N], idx;

void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int ans = 0;

int dfs(int u, int fa) {
        int res = 0, cnt = 0;
        for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (j == fa)
                        continue;
                int t = dfs(j, u);
                if (t > res) {
                        cnt = res;
                        res = t;
                } else if (t > cnt)
                        cnt = t;
        }
        ans = max(ans, res + cnt);
        return res + 1;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();
        memset(h, -1, sizeof h);

        int n, m;
        cin >> n >> m;
        while (m--) {
                int a, b;
                cin >> a >> b;
                add(a, b), add(b, a);
        }

        dfs(1, -1);
        cout << ans << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
