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
#include <iostream>
#include <vector>
using namespace std;

void solve() {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        int idx = x + 1;
        for (int i = x + 1; i <= y; ++i) {
                if (a[i] < a[idx]) {
                        idx = i;
                }
        }
        vector<int> pre, mid, nex;
        for (int i = idx; i <= y; ++i) {
                mid.push_back(a[i]);
        }
        for (int i = x + 1; i < idx; ++i) {
                mid.push_back(a[i]);
        }
        idx = 0;
        for (int i = 0; i <= x; ++i) {
                if (a[i] > mid[0]) {
                        idx = i;
                        break;
                }
        }
        if (idx) {
                for (int i = 1; i < idx; ++i) {
                        pre.push_back(a[i]);
                }
                for (int i = idx; i <= x; ++i) {
                        nex.push_back(a[i]);
                }
                for (int i = y + 1; i <= n; ++i) {
                        nex.push_back(a[i]);
                }
        } else {
                idx = y;
                for (int i = y + 1; i <= n; ++i) {
                        if (a[i] > mid[0]) {
                                break;
                        }
                        idx = i;
                }
                for (int i = 1; i <= x; ++i) {
                        pre.push_back(a[i]);
                }
                for (int i = y + 1; i <= idx; ++i) {
                        pre.push_back(a[i]);
                }
                for (int i = idx + 1; i <= n; ++i) {
                        nex.push_back(a[i]);
                }
        }
        for (int x : pre) {
                cout << x << ' ';
        }
        for (int x : mid) {
                cout << x << ' ';
        }
        for (int x : nex) {
                cout << x << ' ';
        }
        cout << '\n';
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
