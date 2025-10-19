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
const int N = 1e5 + 10, M = 2e6 + 10;

int n, m;
int w[N];
int e[M], ne[M], h[N], rh[N], idx;
int dmin[N], dmax[N];
bool vis[N];
int q[N];

void add(int *h, int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int *h, int *dist, int type) {
        int hh = 0, tt = 1;
        if (type == 0) {
                memset(dist, 0x3f, sizeof dmin);
                dist[1] = w[1];
                q[0] = 1;
        } else {
                memset(dist, -0x3f, sizeof dmax);
                dist[n] = w[n];
                q[0] = n;
        }

        while (hh != tt) {
                int t = q[hh++];
                if (hh == N)
                        hh = 0;

                vis[t] = false;
                for (int i = h[t]; ~i; i = ne[i]) {
                        int j = e[i];
                        if ((type == 0 && dist[j] > min(dist[t], w[j]))
                            || (type == 1 && dist[j] < max(dist[t], w[j]))) {
                                if (type == 0)
                                        dist[j] = min(dist[t], w[j]);
                                else
                                        dist[j] = max(dist[t], w[j]);

                                if (!vis[j]) {
                                        q[tt++] = j;
                                        if (tt == N)
                                                tt = 0;
                                        vis[j] = true;
                                }
                        }
                }
        }
}

void solve() {
        memset(h, -1, sizeof h);
        memset(rh, -1, sizeof rh);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
                scanf("%d", &w[i]);
        while (m--) {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                add(h, a, b), add(rh, b, a);
                if (c == 2)
                        add(h, b, a), add(rh, a, b);
        }

        spfa(h, dmin, 0);
        spfa(rh, dmax, 1);

        int res = 0;
        for (int i = 1; i <= n; ++i)
                res = max(res, dmax[i] - dmin[i]);
        printf("%d\n", res);
}

signed main() {
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
