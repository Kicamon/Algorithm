// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int N = 1e5 + 10;

int e[N], ne[N], h[N], idx;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    int res = 0, cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        cnt++;
        int j = e[i];
        res = max(res, dfs(j));
    }
    res += cnt;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // clock_t start, finish;
    // start = clock();

    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    for (int i = 2, c; i <= n; ++i) {
        cin >> c;
        add(c, i);
    }
    cout << dfs(1) << endl;

    // finish = clock();
    // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

    return 0;
}
