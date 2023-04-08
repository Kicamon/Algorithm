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
#define PII pair<int, int>
#define int long long
const int N = 5e5 + 10;
int n, m, s, p;
int dfn[N], bel[N], low[N], idx, cnt;
bool ins[N];
vector<int> e[N], ne[N];
stack<int> stk;
int val[N], num[N];

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
            num[cnt] += val[v];
            ins[v] = false;
            bel[v] = cnt;
            if (v == u)
                break;
        }
    }
}

int dist[N];
void bfs(int start)
{
    vector<bool> vis(cnt + 1);
    priority_queue<PII, vector<PII>, less<PII>> q;
    dist[start] = num[start];
    q.push({num[start], start});
    while (!q.empty())
    {
        PII t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int v : ne[u])
        {
            if (dist[v] < dist[u] + num[v])
            {
                dist[v] = dist[u] + num[v];
                q.push({dist[v], v});
            }
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
    for (int i = 1, a, b; i <= m; ++i)
    {
        cin >> a >> b;
        e[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            dfs(i);
    for (int u = 1; u <= n; ++u)
        for (int v : e[u])
            if (bel[u] != bel[v])
                ne[bel[u]].push_back(bel[v]);
    cin >> s >> p;
    s = bel[s];
    bfs(s);
    int ans = 0;
    while (p--)
    {
        int c;
        cin >> c;
        ans = max(ans, dist[bel[c]]);
    }
    cout << ans << endl;

    // finish = clock();
    // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

    return 0;
}
