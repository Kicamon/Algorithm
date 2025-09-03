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
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<vector<char> > ms(n, vector<char>(n));
        vector<vector<char> > me(n, vector<char>(n));
        string s;
        for (int i = 0; i < n; ++i) {
                cin >> s;
                for (int j = 0; j < (int)s.size(); ++j) {
                        ms[i][j] = s[j];
                }
        }
        for (int i = 0; i < n; ++i) {
                cin >> s;
                for (int j = 0; j < (int)s.size(); ++j) {
                        me[i][j] = s[j];
                }
        }

        function<bool()> check = [&]() {
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                                if (ms[i][j] != me[i][j]) {
                                        return false;
                                }
                        }
                }
                return true;
        };

        function<void(vector<vector<char> > &)> change = [&](vector<vector<char> > &t) {
                vector<vector<char> > temp = t;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                                t[i][j] = temp[n - 1 - j][i];
                        }
                }
        };

        function<void(vector<vector<char> > &)> change2 = [&](vector<vector<char> > &t) {
                vector<vector<char> > temp = t;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                                t[i][j] = temp[i][n - 1 - j];
                        }
                }
        };

        for (int i = 1; i <= 3; ++i) {
                change(ms);
                if (check()) {
                        cout << i << endl;
                        return 0;
                }
        }
        change(ms);
        auto temp = ms;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        ms[i][j] = temp[i][n - 1 - j];
                }
        }
        if (check()) {
                cout << 4 << endl;
                return 0;
        }
        for (int i = 0; i < 3; ++i) {
                change(ms);
                if (check()) {
                        cout << 5 << endl;
                        return 0;
                }
        }
        change(ms);
        change2(ms);
        if (check()) {
                cout << 6 << endl;
        } else {
                cout << 7 << endl;
        }

        return 0;
}
