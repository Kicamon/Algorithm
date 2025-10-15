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
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define Debug(x) cout << #x << ':' << x << endl
const int N = 1e5 + 10;

int n, m, mod;
vector<int> e[N], scc[N];
int dfn[N], low[N], bel[N], idx, cnt;
bool ins[N], vis[N];
stack<int> stk;
int dp[N], way[N];

void dfs(int u) {
        dfn[u] = low[u] = ++idx;
        ins[u] = true;
        stk.push(u);
        for (int v : e[u]) {
                if (!dfn[v])
                        dfs(v);
                if (ins[v])
                        low[u] = min(low[u], low[v]);
        }
        if (dfn[u] == low[u]) {
                ++cnt;
                while (true) {
                        int v = stk.top();
                        bel[v] = cnt;
                        scc[cnt].push_back(v);
                        ins[v] = false;
                        stk.pop();
                        if (v == u)
                                break;
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        // clock_t start, finish;
        // start = clock();

        cin >> n >> m >> mod;
        for (int i = 0; i < m; ++i) {
                int a, b;
                cin >> a >> b;
                e[a].push_back(b);
        }
        for (int i = 1; i <= n; ++i)
                if (!dfn[i])
                        dfs(i);
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= cnt; ++i) {
                way[i] = 1;
                dp[i] = 0;
                for (int u : scc[i]) {
                        for (int v : e[u]) {
                                if (bel[v] != i && !vis[bel[v]]) {
                                        vis[bel[v]] = true;
                                        if (dp[bel[v]] > dp[i])
                                                dp[i] = dp[bel[v]], way[i] = 0;
                                        if (dp[bel[v]] == dp[i])
                                                way[i] = (way[i] + way[bel[v]]) % mod;
                                }
                        }
                }
                dp[i] += scc[i].size();
                if (dp[i] > ans1)
                        ans1 = dp[i], ans2 = 0;
                if (dp[i] == ans1)
                        ans2 = (ans2 + way[i]) % mod;
                for (int u : scc[i])
                        for (int v : e[u])
                                vis[bel[v]] = false;
        }
        cout << ans1 << endl << ans2 << endl;

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
