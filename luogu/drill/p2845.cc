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
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <array>
using namespace std;

int m_x[] = { 0, 1, 0, -1 };
int m_y[] = { 1, 0, -1, 0 };

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;
        vector<vector<vector<array<int, 2>>>> mx(n + 2, vector<vector<array<int, 2>>>(n + 2));
        vector<vector<bool>> light(n + 2, vector<bool>(n + 2));
        vector<vector<bool>> vis(n + 2, vector<bool>(n + 2));
        queue<array<int, 2>> q;
        while (m--) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                mx[a][b].push_back({ c, d });
        }

        function<void(int, int)> dfs = [&](int x, int y) {
                vis[x][y] = true;
                for (auto [a, b] : mx[x][y]) {
                        if (vis[a][b]) {
                                continue;
                        }
                        light[a][b] = true;
                        q.push({ a, b });
                }
                for (int i = 0; i < 4; ++i) {
                        int X = x + m_x[i], Y = y + m_y[i];
                        if (vis[X][Y] || !light[X][Y]) {
                                continue;
                        }
                        dfs(X, Y);
                }
        };

        light[1][1] = true;
        vis[0][1] = true;
        q.push({ 1, 1 });
        while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (vis[x][y]) {
                        continue;
                }
                bool flag = false;
                for (int i = 0; i < 4; ++i) {
                        int X = x + m_x[i], Y = y + m_y[i];
                        if (vis[X][Y]) {
                                flag = true;
                        }
                }
                if (flag) {
                        dfs(x, y);
                }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                        ans += light[i][j];
                }
        }
        cout << ans << '\n';

        return 0;
}
