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
const int N = 510;

vector<array<int, 2>> e[N];

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        // clock_t start, finish;
        // start = clock();

        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<int> pn(n);
        for (int i = 0; i < n; ++i)
                cin >> pn[i];
        while (m--) {
                int a, b, c;
                cin >> a >> b >> c;
                e[a].push_back({ b, c }), e[b].push_back({ a, c });
        }
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
        vector<int> dist(n, 0x3f3f3f3f), cnt(n), mf(n), num = pn;
        vector<bool> vis(n);
        dist[s] = 0;
        cnt[s] = 1;
        mf[s] = -1;
        q.push({ 0, s });
        while (!q.empty()) {
                auto t = q.top();
                q.pop();
                int u = t[1];
                if (vis[u])
                        continue;
                vis[u] = true;
                for (auto k : e[u]) {
                        int v = k[0], w = k[1];
                        if (dist[v] > dist[u] + w) {
                                dist[v] = dist[u] + w;
                                num[v] = num[u] + pn[v];
                                cnt[v] = cnt[u];
                                mf[v] = u;
                                q.push({ dist[v], v });
                        } else if (dist[v] == dist[u] + w) {
                                cnt[v] += cnt[u];
                                if (num[v] < num[u] + pn[v]) {
                                        num[v] = num[u] + pn[v];
                                        mf[v] = u;
                                }
                        }
                }
        }
        vector<int> ans;
        int idx = d;
        while (idx != -1) {
                ans.push_back(idx);
                idx = mf[idx];
        }
        reverse(all(ans));

        cout << cnt[d] << ' ' << num[d] << endl;
        for (int i = 0; i < (int)ans.size(); ++i) {
                if (i)
                        cout << ' ';
                cout << ans[i];
        }
        cout << endl;

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
