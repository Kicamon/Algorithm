//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define ai2 array<int, 2>
const int N = 1e5 + 10, M = 510;

int n, m;

int e[N], ne[N], w[N], h[M], idx;

void add(int a, int b, int c) {
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[N];
bool vis[M];

int dijkstra() {
        memset(dist, 0x3f, sizeof dist);
        dist[1] = 0;
        priority_queue<ai2, vector<ai2>, greater<ai2>> q;
        q.push({ 0, 1 });
        while (!q.empty()) {
                ai2 t = q.top();
                q.pop();

                if (vis[t[1]])
                        continue;
                vis[t[1]] = true;

                for (int i = h[t[1]]; ~i; i = ne[i]) {
                        int j = e[i];
                        if (dist[j] > dist[t[1]] + w[i]) {
                                dist[j] = dist[t[1]] + w[i];
                                q.push({ dist[j], j });
                        }
                }
        }

        if (dist[n] == 0x3f3f3f3f)
                return -1;
        return dist[n];
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        memset(h, -1, sizeof h);
        cin >> n >> m;
        while (m--) {
                int a, b, c;
                cin >> a >> b >> c;
                add(a, b, c);
        }

        cout << dijkstra() << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
