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
#include <numeric>
#include <stack>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int &x : a) {
                cin >> x;
        }
        iota(all(b), 0);
        stack<int> q;
        for (int i = 1; i < n; ++i) {
                if (a[i] > a[i - 1]) {
                        b[i] = b[i - 1];
                } else {
                        q.push(i - 1);
                }
        }
        for (int i = n - 1; ~i && !q.empty(); --i) {
                if (i != q.top()) {
                        continue;
                }
                if (!i) {
                        if (i + 1 == n - 1) {
                                b[i + 1] = b[i];
                        }
                        if (a[i + 2] > a[i]) {
                                for (int j = i + 2; j < n && b[j] == b[i + 1]; ++j) {
                                        b[j] = b[i];
                                }
                                b[i + 1] = b[i];
                        }
                } else if (i + 1 == n - 1) {
                        if (a[i + 1] > a[i - 1]) {
                                b[i + 1] = b[i];
                        } else {
                                b[i + 1] = i;
                        }
                } else if (a[i - 1] < a[i + 1] && a[i] < a[i + 2]) {
                        for (int j = i + 2; j < n && b[j] == b[i + 1]; ++j) {
                                b[j] = b[i];
                        }
                        b[i + 1] = b[i];
                } else if (a[i] < a[i + 2]) {
                        for (int j = i + 2; j < n && b[j] == b[i + 1]; ++j) {
                                b[j] = i;
                        }
                        b[i + 1] = i;
                } else {
                        b[i + 1] = b[i];
                }
                q.pop();
        }
        while (m--) {
                int l, r;
                cin >> l >> r;
                if (r - l <= 1) {
                        cout << "YES" << endl;
                        continue;
                }
                l--, r--;
                if (l >= b[r]) {
                        cout << "YES" << endl;
                } else {
                        cout << "NO" << endl;
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
