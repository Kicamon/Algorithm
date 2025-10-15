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
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 2010;

vector<int> G[N];
int b[N]; // 节点编号

struct Node {
        int cnt;
        int p[N];
        bool l[N], r[N]; // 记录是否具有紧挨的边，分别为前面和后面
        int s1, s2; // 起点，终点
        int find(int x) {
                return p[x] == x ? x : p[x] = find(p[x]);
        }
        void init(int n) {
                s1 = s2 = 0;
                for (int i = 1; i <= n; ++i) {
                        p[i] = i;
                        l[i] = r[i] = 0;
                }
        }
        void merge(int x, int y) { // 让x,y紧挨
                p[find(x)] = find(y);
                r[x] = l[y] = true;
                cnt--;
        }
        bool pd1(int k) { // 判断k是否为起点
                if (l[k])
                        return false;
                if (s2 && cnt >= 2 && find(s2) == find(k))
                        return false;
                return true;
        }
        bool pd2(int k) { // 判断k是否为终点
                if (s2)
                        return false;
                if (r[k])
                        return false;
                if (s1 && cnt >= 2 && find(s1) == find(k))
                        return false;
                return true;
        }
        bool pd3(int k1, int k2) { // 判断k1和k2是否紧挨着删除
                if (s2 == k1 || s1 == k2)
                        return false;
                if (r[k1] || l[k2])
                        return false;
                if (find(k1) == find(k2))
                        return false;
                if (s1 && s2 && cnt >= 3 && find(s1) == find(k1) && find(s2) == find(k2))
                        return false;
                return true;
        }
} a[N];

int fa[N];
int ans;
void dfs(int u) {
        if (a[u].pd2(fa[u]))
                ans = min(ans, u);
        for (auto v : G[u]) {
                if (v == fa[u])
                        continue;
                if (a[u].pd3(fa[u], v))
                        fa[v] = u, dfs(v);
        }
}

void solve() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
                G[i].clear();
        for (int i = 1; i <= n; ++i)
                cin >> b[i];
        for (int i = 1; i < n; ++i) {
                int u, v;
                cin >> u >> v;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        if (n == 1) {
                cout << 1 << endl;
                return;
        } else if (n == 2) {
                cout << b[2] << ' ' << b[1] << endl;
                return;
        }
        for (int i = 1; i <= n; ++i) {
                a[i].init(n);
                a[i].cnt = G[i].size();
        }
        for (int i = 1; i <= n; ++i) {
                ans = n + 1;
                for (auto v : G[b[i]]) {
                        if (a[b[i]].pd1(v))
                                fa[v] = b[i], dfs(v);
                }
                cout << ans << ' ';
                int u = ans, v;
                a[u].s2 = fa[u];
                v = u, u = fa[u];
                while (u != b[i]) {
                        a[u].merge(fa[u], v);
                        v = u, u = fa[u];
                }
                a[b[i]].s1 = v;
        }
        cout << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--)
                solve();

        return 0;
}
