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
int input = 0;
const int N = 11, M = 400, K = 1 << 10;
#define PII pair<int, int>

int n, m, p;
int e[M], ne[M], w[M], h[N * N], idx;
set<PII> edge;
int g[N][N];
int key[N * N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build()
{
    int mx[4]{0, 1, 0, -1}, my[4]{1, 0, -1, 0};
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int u = 0; u < 4; ++u)
            {
                int x = i + mx[u], y = j + my[u];
                if (!x || x > n || !y || y > m)
                    continue;
                int a = g[i][j], b = g[x][y];
                if (!edge.count({a, b}))
                    add(a, b, 0);
            }
}

int dist[N * N][K];
bool vis[N * N][K];
int bfs()
{
    deque<PII> q;
    q.push_back({1, 0});
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    while (!q.empty())
    {
        PII t = q.front();
        q.pop_front();

        if (vis[t.first][t.second])
            continue;
        vis[t.first][t.second] = true;
        if (t.first == n * m)
            return dist[t.first][t.second];

        if (key[t.first])
        {
            int state = t.second | key[t.first];
            if (dist[t.first][state] > dist[t.first][t.second])
            {
                dist[t.first][state] = dist[t.first][t.second];
                q.push_front({t.first, state});
            }
        }

        for (int i = h[t.first]; ~i; i = ne[i])
        {
            int j = e[i];
            if (w[i] && !(t.second >> w[i] - 1 & 1))
                continue;
            if (dist[j][t.second] > dist[t.first][t.second] + 1)
            {
                dist[j][t.second] = dist[t.first][t.second] + 1;
                q.push_back({j, t.second});
            }
        }
    }
    return -1;
}

void solve()
{
    memset(h, -1, sizeof h);
    int k;
    cin >> n >> m >> p >> k;
    for (int i = 1, t = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j, ++t)
            g[i][j] = t;
    int x1, y1, x2, y2, c;
    while (k--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2];
        edge.insert({a, b}), edge.insert({b, a});
        if (c)
            add(a, b, c), add(b, a, c);
    }

    build();

    cin >> k;
    int a, b;
    while (k--)
    {
        cin >> a >> b >> c;
        key[g[a][b]] |= 1 << c - 1;
    }

    cout << bfs() << endl;
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
