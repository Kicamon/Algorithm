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
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

vector<int> mul(vector<int> &a, int b) {
        vector<int> res;
        for (int i = 0, t = 0; i < (int)a.size() || t; ++i) {
                if (i < (int)a.size()) {
                        t += a[i] * b;
                }
                res.push_back(t % 10);
                t /= 10;
        }
        return res;
}

vector<int> div(vector<int> &a, int b) {
        vector<int> res;
        ll t = 0;
        for (int i = (int)a.size() - 1; ~i; --i) {
                t = t * 10 + a[i];
                res.push_back(t / b);
                t %= b;
        }
        reverse(all(res));
        while ((int)res.size() > 1 && !res.back()) {
                res.pop_back();
        }
        return res;
}

vector<int> MAX(vector<int> &a, vector<int> b) {
        if (a.size() > b.size()) {
                return a;
        }
        if (a.size() < b.size()) {
                return b;
        }
        for (int i = (int)a.size() - 1; ~i; --i) {
                if (a[i] > b[i]) {
                        return a;
                }
                if (a[i] < b[i]) {
                        return b;
                }
        }
        return a;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<array<int, 2> > a(n + 1);
        for (auto &x : a) {
                cin >> x[0] >> x[1];
        }
        sort(a.begin() + 1, a.end(),
             [](array<int, 2> x, array<int, 2> y) { return x[0] * x[1] < y[0] * y[1]; });
        vector<int> temp;
        temp.push_back(a[0][0]);
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; ++i) {
                ans = MAX(ans, div(temp, a[i][1]));
                temp = mul(temp, a[i][0]);
        }
        for (int x : vector<int>(ans.rbegin(), ans.rend())) {
                cout << x;
        }
        cout << endl;

        return 0;
}
