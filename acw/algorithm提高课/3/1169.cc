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

int n, m;
vector<array<int, 2>> e[N], ne[N];
int dfn[N], low[N], bel[N], sz[N], idx, cnt;
bool ins[N];
stack<int> stk;

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    ins[u] = true;
    stk.push(u);
    for (auto j : e[u])
    {
        int v = j[0];
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
            bel[v] = cnt;
            ins[v] = false;
            sz[cnt]++;
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

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        e[0].push_back({i, 1});
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            e[a].push_back({b, 0}), e[b].push_back({a, 0});
        else if (op == 2)
            e[a].push_back({b, 1});
        else if (op == 3)
            e[b].push_back({a, 0});
        else if (op == 4)
            e[b].push_back({a, 1});
        else
            e[a].push_back({b, 0});
    }
    dfs(0);
    bool f = false;
    for (int u = 0; u <= n; ++u)
    {
        for (auto j : e[u])
        {
            int v = j[0];
            if (bel[u] != bel[v])
                ne[bel[u]].push_back({bel[v], j[1]});
            else if (j[1] > 0)
            {
                f = true;
                break;
            }
        }
        if (f)
            break;
    }
    if (f)
        cout << -1 << endl;
    else
    {
        vector<int> dist(n + 1);
        for (int u = cnt; u; --u)
            for (auto j : ne[u])
            {
                int v = j[0];
                dist[v] = max(dist[v], dist[u] + j[1]);
            }
        ll ans = 0;
        for (int i = 1; i <= cnt; ++i)
            ans += 1ll * dist[i] * sz[i];
        cout << ans << endl;
    }

    // finish = clock();
    // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

    return 0;
}
