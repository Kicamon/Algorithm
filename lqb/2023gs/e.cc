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
#define all(x) x.begin(), x.end()
#define uq(x)         \
        sort(all(x)); \
        x.erase(unique(all(x)), x.end())
const int N = 2010;
#define int long long

bool vis[N][N];
map<ll, int> cnt;

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<array<int, 2>> point(n);
        vector<int> a(n << 1);
        for (int i = 0; i < n; ++i) {
                cin >> point[i][0] >> point[i][1];
                a[i << 1] = point[i][0];
                a[i << 1 | 1] = point[i][1];
        }
        uq(a);
        for (int i = 0; i < n; ++i) {
                int x = lower_bound(all(a), point[i][0]) - a.begin();
                int y = lower_bound(all(a), point[i][1]) - a.begin();
                vis[x][y] = true;
        }
        auto len = [&](int x, int y) {
                return (point[y][0] - point[y][0]) * (point[y][0] - point[y][0])
                       + (point[x][1] - point[y][1]) * (point[x][1] - point[y][1]);
        };
        int ans = 0, line = 0;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (i == j)
                                continue;
                        ans += cnt[len(i, j)];
                        Debug(ans);
                        cnt[len(i, j)]++;
                        int x = lower_bound(all(a), point[i][0] + point[j][0] >> 1) - a.begin();
                        int y = lower_bound(all(a), point[i][1] + point[j][1] >> 1) - a.begin();
                        if (vis[x][y])
                                line++;
                }
                cnt.clear();
        }
        cout << ans << ' ' << line << endl;
        cout << ans - line / 2 << endl;
        return 0;
}
