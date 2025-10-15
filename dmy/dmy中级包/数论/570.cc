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
#include <functional>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

const int N = 2e7 + 10;

int n;
int p[N], pr[N / 5], pe[N], idx;
uint f[N], a, b;

void compute(int n, function<void(int)> calcpe) {
        uint ans = 0;
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
                if (i == pe[i]) {
                        calcpe(i);
                } else {
                        f[i] = f[pe[i]] * f[i / pe[i]];
                }
        }
        for (uint i = 1; i <= n; ++i) {
                ans ^= (a * i * f[i] + b);
        }
        cout << ans << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> a >> b;
        p[1] = 1;
        for (int i = 2; i <= n; ++i) {
                if (!p[i]) {
                        p[i] = i, pe[i] = i,
                        pr[++idx] = i; // pe[i]存储i的最小质因子出现的次数
                }
                for (int j = 1; j <= idx && i * pr[j] <= n; ++j) {
                        p[i * pr[j]] = pr[j];
                        if (p[i] == pr[j]) { // pr[j]等于p[i]的最小质因数时
                                pe[i * pr[j]] = pe[i] * pr[j];
                                break;
                        } else {
                                pe[i * pr[j]] = pr[j];
                        }
                }
        }

        compute(n, [&](int x) { f[x] = f[x / p[x]] + 1; }); // 因子个数
        compute(n, [&](int x) { f[x] = f[x / p[x]] + x; }); // 因子和
        compute(n, [&](int x) { f[x] = x / p[x] * (p[x] - 1); }); // 欧拉函数
        compute(n, [&](int x) { f[x] = x == p[x] ? -1 : 0; }); // 莫比乌斯函数

        return 0;
}
