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
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

bool check(vector<int> &v) {
        vector<int> u = { v[0] }, d = { v[0] };
        for (size_t i = 1; i < v.size(); i++) {
                if (1 <= v[i] - u.back() && v[i] - u.back() <= 3) {
                        u.push_back(v[i]);
                }
                if (1 <= d.back() - v[i] && d.back() - v[i] <= 3) {
                        d.push_back(v[i]);
                }
        }
        return (max(u.size(), d.size()) == v.size());
}

bool get_ans(vector<int> &v) {
        vector<vector<int>> res(3, v);
        for (size_t i = 1; i < v.size(); i++) {
                if (abs(v[i] - v[i - 1]) < 1 || abs(v[i] - v[i - 1]) > 3) {
                        res[0].erase(res[0].begin() + i - 1, res[0].begin() + i);
                        res[1].erase(res[1].begin() + i, res[1].begin() + i + 1);
                        return (check(res[0]) || check(res[1]));
                }
                if (i < v.size() - 1 && (v[i] - v[i - 1]) * (v[i + 1] - v[i]) <= 0) {
                        res[0].erase(res[0].begin() + i - 1, res[0].begin() + i);
                        res[1].erase(res[1].begin() + i, res[1].begin() + i + 1);
                        res[2].erase(res[2].begin() + i + 1, res[2].begin() + i + 2);
                        return (check(res[0]) || check(res[1])) || check(res[2]);
                }
        }
        return true;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        ifstream fp("input.txt");
        if (!fp.is_open()) {
                return 1;
        }
        string line;
        int ans = 0;
        while (getline(fp, line)) {
                stringstream ss(line);
                vector<int> rel;
                int x;
                while (ss >> x) {
                        rel.push_back(x);
                }
                ans += get_ans(rel);
        }
        cout << ans << endl;

        return 0;
}
