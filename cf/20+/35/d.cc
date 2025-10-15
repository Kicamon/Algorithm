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
#include <array>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;

ll get(vector<array<ll, 2>> a) {
        int n = a.size() - 1;
        if (n == 1) {
                return a[1][0];
        }
        vector<ll> res(n + 1);
        vector<array<ll, 2>> b = a;
        ll ans = 0;
        int idx = 0;

        for (int i = 1; i <= n; i++) {
                int tmp = (1 << (a[i][1] - a[idx][1])) % mod * a[i][0] % mod;
                if (tmp >= a[idx][0]) {
                        res[i] = ((1 << a[i][1]) % mod * a[i][0] % mod + ans) % mod;
                        idx = i;
                } else {
                        res[i] = (((1 << a[idx][1]) - 1) % mod * a[idx][0] % mod + ans +
                                  get(vector<array<ll, 2>>(b.begin() + idx, b.begin() + i))) %
                                 mod;
                }
                while (a[i][0] % 2 == 0) {
                        a[i][1]++;
                        a[i][0] >>= 1;
                }
                if (a[i][0] >= a[idx][0]) {
                        idx = i;
                }
                ans = (ans + a[i][0]) % mod;
        }
        return res[n];
}

void solve() {
        int n;
        cin >> n;
        vector<array<ll, 2>> a(n + 1), b(n + 1);
        vector<ll> res(n + 1);
        ll ans = 0;
        int idx = 0;

        for (int i = 1; i <= n; i++) {
                cin >> a[i][0];
                b[i][0] = a[i][0];
                a[i][1] = a[i - 1][1];
                int tmp = (1 << (a[i][1] - a[idx][1])) % mod * a[i][0] % mod;
                if (tmp >= a[idx][0]) {
                        res[i] = ((1 << a[i][1]) % mod * a[i][0] % mod + ans) % mod;
                        idx = i;
                } else {
                        res[i] = (((1 << a[idx][1]) - 1) % mod * a[idx][0] % mod + ans +
                                  get(vector<array<ll, 2>>(b.begin() + idx, b.begin() + i))) %
                                 mod;
                }
                while (a[i][0] % 2 == 0) {
                        a[i][1]++;
                        a[i][0] >>= 1;
                }
                if (a[i][0] >= a[idx][0]) {
                        idx = i;
                }
                ans = (ans + a[i][0]) % mod;
        }
        for (int i = 1; i <= n; i++) {
                cout << res[i] << ' ';
        }
        cout << endl;
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
