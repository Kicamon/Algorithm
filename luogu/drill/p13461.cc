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
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;

vector<int> primes;
void init() {
        vector<bool> vis(N);
        for (int i = 2; i < N; ++i) {
                if (!vis[i]) {
                        primes.push_back(i);
                }
                for (int j : primes) {
                        if (i * j >= N) {
                                break;
                        }
                        vis[i * j] = true;
                        if (i % j == 0) {
                                break;
                        }
                }
        }
}

class DSU {
    private:
        vector<int> f;

    public:
        DSU(int n) {
                f.resize(n);
                iota(all(f), 0);
        }

        int find(int x) {
                while (x != f[x]) {
                        x = f[x] = f[f[x]];
                }
                return x;
        }

        bool merge(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) {
                        return false;
                }
                f[y] = x;
                return true;
        }
};

void solve(int Case) {
        ll a, b, p;
        cin >> a >> b >> p;
        DSU dsu(b - a + 1);
        int idx = lower_bound(all(primes), p) - primes.begin();
        for (int i = idx; i < (int)primes.size() && primes[i] <= b; ++i) {
                ll t = ceil((double)a / primes[i]);
                for (ll j = primes[i] * t; j <= b; j += primes[i]) {
                        dsu.merge(primes[i] * t - a, j - a);
                }
        }
        int ans = 0;
        for (int i = 0; i <= b - a; ++i) {
                ans += (dsu.find(i) == i);
        }
        cout << "Case #" << Case << ": " << ans << '\n';
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        init();

        int t;
        cin >> t;
        for (int i = 1; i <= t; ++i) {
                solve(i);
        }

        return 0;
}
