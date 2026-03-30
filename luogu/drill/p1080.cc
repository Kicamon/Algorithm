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
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

bool v_max(vector<int> &a, vector<int> &b) {
        if (a.size() != b.size()) {
                return a.size() < b.size();
        }
        for (int i = (int)a.size() - 1; ~i; --i) {
                if (a[i] != b[i]) {
                        return a[i] < b[i];
                }
        }
        return true;
}

vector<int> MAX(vector<int> &a, vector<int> b) {
        if (v_max(a, b)) {
                return b;
        }
        return a;
}

vector<int> mul(vector<int> &a, int b) {
        vector<int> res;
        int t = 0;
        for (int i = 0; i < (int)a.size() || t; ++i) {
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
        int t = 0;
        for (int i = (int)a.size() - 1; ~i; --i) {
                t = t * 10 + a[i];
                res.push_back(t / b);
                t = t % b;
        }
        if (res.empty()) {
                return { 0 };
        }
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == 0) {
                res.pop_back();
        }
        return res;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        vector<array<int, 2>> a(n + 1);
        for (auto &x : a) {
                cin >> x[0] >> x[1];
        }
        sort(a.begin() + 1, a.end(), [](auto x, auto y) { return x[0] * x[1] < y[0] * y[1]; });

        vector<int> t = { a[0][0] };
        vector<int> ans = { 0 };
        for (int i = 1; i <= n; ++i) {
                ans = MAX(ans, div(t, a[i][1]));
                t = mul(t, a[i][0]);
        }
        for (int x : vector<int>(ans.rbegin(), ans.rend())) {
                cout << x;
        }
        cout << '\n';

        return 0;
}
