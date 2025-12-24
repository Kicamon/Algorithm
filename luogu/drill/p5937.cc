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
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <array>
using namespace std;
#define all(x) (x).begin(), (x).end()

vector<int> f;

int find(int x) {
        while (x != f[x]) {
                x = f[x] = f[f[x]];
        }
        return x;
}

void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
                return;
        }
        f[x] = y;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> a(m);
        vector<int> b;
        for (int i = 0, x, y; i < m; ++i) {
                char opt;
                cin >> x >> y >> opt;
                x--;
                a[i] = { x, y, opt == 'o' };
                b.push_back(x);
                b.push_back(y);
        }
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        f.resize(b.size() * 2);
        iota(all(f), 0);
        for (int i = 0; i < m; ++i) {
                int x = lower_bound(all(b), a[i][0]) - b.begin();
                int y = lower_bound(all(b), a[i][1]) - b.begin();
                if (a[i][2]) {
                        if (find(x) == find(y)) {
                                cout << i << '\n';
                                return 0;
                        } else {
                                merge(x, y + b.size());
                                merge(x + b.size(), y);
                        }
                } else {
                        if (find(x) == find(y + b.size())) {
                                cout << i << '\n';
                                return 0;
                        } else {
                                merge(x, y);
                                merge(x + b.size(), y + b.size());
                        }
                }
        }
        cout << m << '\n';

        return 0;
}
