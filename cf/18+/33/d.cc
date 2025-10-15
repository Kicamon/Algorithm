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

void solve() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        a[0] = INT_MAX;
        for (int i = 1; i <= n; ++i)
                cin >> a[i];
        if (n == 1)
                cout << 1 << endl;
        else if (a[1] == n) {
                int idx = 0;
                for (int i = 1; i <= n; ++i)
                        if (a[i] == n - 1) {
                                idx = i;
                                break;
                        }
                if (idx == n) {
                        cout << a[n] << ' ';
                        for (int i = 1; i < n; ++i)
                                cout << a[i] << ' ';
                        cout << endl;
                } else {
                        int cnt = idx - 1;
                        while (cnt && a[cnt - 1] < a[cnt])
                                cnt--;
                        for (int i = idx; i <= n; ++i)
                                cout << a[i] << ' ';
                        for (int i = idx - 1; i >= cnt; --i)
                                cout << a[i] << ' ';
                        for (int i = 1; i < cnt; ++i)
                                cout << a[i] << ' ';
                        cout << endl;
                }
        } else if (a[n] == n) {
                cout << a[n] << ' ';
                if (a[n - 1] > a[1]) {
                        int cnt = n - 2;
                        while (cnt > 0 && a[cnt] > a[1])
                                cnt--;
                        for (int i = n - 1; i > cnt; i--)
                                cout << a[i] << ' ';
                        for (int i = 1; i <= cnt; ++i)
                                cout << a[i] << ' ';
                } else
                        for (int i = 1; i < n; ++i)
                                cout << a[i] << ' ';
                cout << endl;
        } else {
                int idx = 0;
                for (int i = 1; i <= n; ++i)
                        if (a[i] == n) {
                                idx = i;
                                break;
                        }
                for (int i = idx; i <= n; ++i)
                        cout << a[i] << ' ';
                int cnt = idx - 2;
                while (cnt > 0 && a[cnt] > a[1])
                        cnt--;
                for (int i = idx - 1; i > cnt; i--)
                        cout << a[i] << ' ';
                for (int i = 1; i <= cnt; ++i)
                        cout << a[i] << ' ';
                cout << endl;
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        // clock_t start, finish;
        // start = clock();

        int t;
        cin >> t;
        while (t--)
                solve();

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
