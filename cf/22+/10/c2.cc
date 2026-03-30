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
#include <numeric>
#include <set>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> prime;

void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
                cin >> b[i];
        }
        if (n == 1) {
                if (a[0] == b[0] && a[0] == 1) {
                        cout << "0\n";
                } else {
                        cout << "1\n";
                }
                return;
        }
        if (n == 2) {
                int t = gcd(a[0], a[1]);
                int ans = 2 - (a[0] == t) - (a[1] == t);
                if (t == a[0] && t == a[1]) {
                        for (int x : prime) {
                                if (x * a[0] > b[0]) {
                                        break;
                                }
                                if (gcd(x * a[0], a[1]) == t) {
                                        ans++;
                                        a[0] *= x;
                                        break;
                                }
                        }
                        for (int x : prime) {
                                if (x * a[1] > b[1]) {
                                        break;
                                }
                                if (gcd(x * a[1], a[0]) == t) {
                                        ans++;
                                        break;
                                }
                        }
                } else if (t == a[0]) {
                        a[1] = a[0];
                        for (int x : prime) {
                                if (x * a[0] > b[0]) {
                                        break;
                                }
                                if (gcd(x * a[0], a[1]) == t) {
                                        ans++;
                                        a[0] *= x;
                                        break;
                                }
                        }
                } else if (t == a[1]) {
                        a[0] = a[1];
                        for (int x : prime) {
                                if (x * a[1] > b[1]) {
                                        break;
                                }
                                if (gcd(x * a[1], a[0]) == t) {
                                        ans++;
                                        a[0] *= x;
                                        break;
                                }
                        }
                }
                cout << ans << '\n';
                return;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
                int pr = gcd(a[i], a[i - 1]);
                int ne = gcd(a[i], a[i + 1]);
                int t = lcm(pr, ne);
                if (t == a[i]) {
                        for (int x : prime) {
                                if (gcd(x * a[i], a[i - 1]) == pr
                                    && gcd(x * a[i], a[i + 1]) == ne) {
                                        t *= x;
                                        break;
                                }
                        }
                }
                if (t <= b[i]) {
                        ans++;
                        a[i] = t;
                }
        }
        int t = gcd(a[0], a[1]);
        if (t == a[0]) {
                for (int x : prime) {
                        if (gcd(a[1], x) == 1) {
                                t *= x;
                                break;
                        }
                }
        }
        ans += t <= b[0];
        t = gcd(a[n - 1], a[n - 2]);
        if (t == a[n - 1]) {
                for (int x : prime) {
                        if (gcd(a[n - 2], x) == 1) {
                                t *= x;
                                break;
                        }
                }
        }
        ans += t <= b[n - 1];

        // for (int i = 0; i < n; ++i) {
        //         cout << a[i] << " \n"[i == n - 1];
        // }

        cout << ans << '\n';
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<bool> vis(N);
        for (int i = 2; i < N; ++i) {
                if (!vis[i]) {
                        prime.push_back(i);
                }
                for (int j : prime) {
                        if (i * j >= N) {
                                break;
                        }
                        vis[i * j] = true;
                        if (i % j == 0) {
                                break;
                        }
                }
        }

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
