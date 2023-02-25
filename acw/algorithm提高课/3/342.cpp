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
//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <cstring>
#include <functional>
#include <queue>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define Debug(x) cout << #x << ':' << x << endl
int input = 0;
const int N = 25010, M = 15e4 + 10;
#define ai2 array<int, 2>

int T, R, P, S;

int e[M], ne[M], w[M], h[N], idx;
int id[N], bcnt;
vint b[N];
int it[N];
queue<int> q;
int dist[N];
bool vis[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int bid)
{
    id[u] = bid, b[bid].pb(u);

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!id[j])
            dfs(j, bid);
    }
}

void dijkstra(int u)
{
    priority_queue<ai2, vector<ai2>, greater<ai2>> p;
    for (int x : b[u])
        p.push({dist[x], x});

    while (!p.empty())
    {
        ai2 t = p.top();
        p.pop();

        if (vis[t[1]])
            continue;
        vis[t[1]] = true;

        for (int i = h[t[1]]; ~i; i = ne[i])
        {
            int j = e[i];
            if (id[j] != id[t[1]] && --it[j] == 0)
                q.push(j);
            if (dist[j] > dist[t[1]] + w[i])
            {
                dist[j] = dist[t[1]] + w[i];
                if (id[j] == id[t[1]])
                    p.push({dist[j], j});
            }
        }
    }
}

void topsort()
{
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= T; ++i)
        if (it[i] == 0)
            q.push(i);
    dist[S] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        dijkstra(t);
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    cin >> T >> R >> P >> S;
    int a, b, c;
    for (int i = 0; i < R; ++i)
    {
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    for (int i = 1; i <= T; ++i)
    {
        if (!id[i])
        {
            bcnt++;
            dfs(i, bcnt);
        }
    }

    for (int i = 0; i < P; ++i)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        it[b]++;
    }

    topsort();

    for (int i = 1; i <= T; ++i)
    {
        if (dist[i] >= 0x3f3f3f3f)
            cout << "NO PATH" << endl;
        else
            cout << dist[i] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // clock_t start, finish;
    // start = clock();

    int t = 1;
    if (input)
        cin >> t;
    while (t--)
        solve();

    // finish = clock();
    // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

    return 0;
}
