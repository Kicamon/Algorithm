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
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int mod = 20101009, N = 1e7 + 10;

vector<int> prime;
array<int, N> mu;
array<ll, N> sum;
array<bool, N> st;

void init() {
        mu[1] = sum[1] = 1;
        for (int i = 2; i < N; ++i) {
                if (!st[i]) {
                        prime.push_back(i);
                        mu[i] = -1;
                }
                for (int x : prime) {
                        if (i * x >= N) {
                                break;
                        }
                        st[i * x] = true;
                        if (i % x == 0) {
                                break;
                        }
                        mu[i * x] = -mu[i];
                }
                sum[i] = (sum[i - 1] + 1ll * i * i % mod * mu[i]) % mod;
        }
}

int f(int a, int b) {
        return a / (a / b);
}

ll g(int n, int m) {
        return (1ll * n * (n + 1) / 2 % mod) * (1ll * m * (m + 1) / 2 % mod) % mod;
}

ll sum_f(int n, int m) {
        if (n > m) {
                swap(n, m);
        }
        ll res = 0;
        for (int i = 1, t; i <= n; ++i) {
                t = min(n, min(f(n, i), f(m, i)));
                (res += (1ll * (sum[t] - sum[i - 1] + mod) * g(n / i, m / i) % mod)) %= mod;
                i = t;
        }
        return res;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        init();
        int n, m;
        cin >> n >> m;
        if (n > m) {
                swap(n, m);
        }
        ll ans = 0;
        for (int i = 1, t; i <= n; ++i) {
                t = min(n, min(f(n, i), f(m, i)));
                (ans += 1ll * (t - i + 1) * (i + t) / 2 % mod * sum_f(n / i, m / i)) %= mod;
                i = t;
        }
        cout << ans << endl;

        return 0;
}
