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
int dfn[N], bel[N], low[N], vis[N], idx, cnt;
bool ins[N];
stack<int> stk;
int far[N], way[N];

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    ins[u] = true;
    stk.push(u);
    for (int v : e[u])
    {
        if (!dfn[v])
            dfs(v);
        if (ins[v])
            low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u])
    {
        ++cnt;
        while (true)
        {
            int v = stk.top();
            stk.pop();
            ins[v] = false;
            bel[v] = cnt;
            scc[cnt].push_back(v);
            if (v == u)
                break;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // clock_t start, finish;
    // start = clock();

    cin >> n >> m >> mod;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            dfs(i);
    int ans = 0, w = 0, T = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        way[i] = 1;
        far[i] = 0;
        T++;
        for (int u : scc[i])
            for (int v : e[u])
            {
                if (bel[v] != i && vis[bel[v]] != T)
                {
                    vis[bel[v]] = T;
                    if (far[bel[v]] > far[i])
                        far[i] = far[bel[v]], way[i] = 0;
                    if (far[bel[v]] == far[i])
                        way[i] = (way[i] + way[bel[v]]) % mod;
                }
            }
        far[i] += scc[i].size();
        if (far[i] > ans)
            ans = far[i], w = 0;
        if (far[i] == ans)
            w = (w + way[i]) % mod;
    }
    cout << ans << endl << w << endl;

    // finish = clock();
    // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

    return 0;
}
