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
/* #pragma GCC optimize(2) */
#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 510;
const ll inf = 1e18;
int n, m, d;
vector<vector<bool> > vis(N, vector<bool>(N));
vector<vector<array<int, 3> > > g(N);
vector<vector<double> > dis(N, vector<double>(N, inf));
vector<vector<array<int, 2> > > path(N, vector<array<int, 2> >(N, { -1, -1 }));

struct node {
        double t;
        int v;
        int nd;
        bool operator>(const node &u) const {
                return t > u.t;
        }
};

double get(int v, int w) {
        return double(w) / v;
}

void dijkstra() {
        priority_queue<node, vector<node>, greater<node> > q;
        dis[0][70] = 0;
        q.push({ 0, 70, 0 });
        while (!q.empty()) {
                auto t = q.top();
                q.pop();
                if (vis[t.nd][t.v]) {
                        continue;
                }
                vis[t.nd][t.v] = true;
                for (auto x : g[t.nd]) {
                        if (x[0] == t.nd) {
                                continue;
                        }
                        int v = x[1] ? x[1] : t.v;
                        if (dis[t.nd][t.v] + get(v, x[2]) < dis[x[0]][v]) {
                                dis[x[0]][v] = dis[t.nd][t.v] + get(v, x[2]);
                                path[x[0]][v][0] = t.nd;
                                path[x[0]][v][1] = t.v;
                                q.push({ dis[x[0]][v], v, x[0] });
                        }
                };
        }
}

int get_pre(int x) {
        int res = 0;
        for (int i = 0; i < N; ++i) {
                if (dis[x][i] < dis[x][res]) {
                        res = i;
                }
        }
        return res;
}

void print(int nd, int v) {
        if (nd == -1) {
                return;
        }
        print(path[nd][v][0], path[nd][v][1]);
        cout << nd << ' ';
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m >> d;
        int a, b, v, l;
        while (m--) {
                cin >> a >> b >> v >> l;
                if (!a && !v) {
                        v = 70;
                }
                g[a].push_back({ b, v, l });
        }
        dijkstra();
        print(d, get_pre(d));
        cout << endl;

        return 0;
}
