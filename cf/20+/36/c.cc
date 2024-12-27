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
#include <set>
#include <array>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

auto get_jp(string prex) {
        vector<int> jp(prex.size());
        prex = " " + prex;
        for (size_t i = 2, j = 0; i < prex.size(); i++) {
                while (j && prex[i] != prex[j + 1]) {
                        j = jp[j];
                }
                if (prex[i] == prex[j + 1]) {
                        j++;
                }
                jp[i] = j;
        }
        return jp;
}

void solve() {
        string s;
        cin >> s;
        s = " " + s;
        string prex = " 1100";
        auto jp = get_jp(prex);
        set<array<int, 2> > st;
        for (int i = 1, j = 0; i <= s.size(); i++) {
                while (j && s[i] != prex[j + 1]) {
                        j = jp[j];
                }
                if (s[i] == prex[j + 1]) {
                        j++;
                }
                if (j == s.size()) {
                        st.insert((array<int, 2>){ i - 4, i - 1 });
                }
        }

        auto check = [&](int idx) -> bool {
                auto it = upper_bound(all(st), (array<int, 2>){ idx, 0 });
                if ((*it)[1] > idx) {
                        return false;
                }
                st.erase(it);
                return true;
        };

        auto add = [&](int idx) -> void {
                if (s[idx] == '1') {
                        if ("1100" == s.substr(idx, idx + 3)) {
                                st.insert({ idx, idx + 3 });
                        }
                        if ("1100" == s.substr(idx - 1, idx + 2)) {
                                st.insert({ idx - 1, idx + 2 });
                        }
                } else {
                        if ("1100" == s.substr(idx - 2, idx + 1)) {
                                st.insert({ idx - 2, idx + 1 });
                        }
                        if ("1100" == s.substr(idx - 3, idx)) {
                                st.insert({ idx - 3, idx });
                        }
                }
        };

        int q, i, v;
        cin >> q;
        while (q--) {
                cin >> i >> v;
                if (s[i] - '0' == v && st.size()) {
                        cout << "Yes" << endl;
                } else if (check(i) && st.size()) {
                        cout << "Yes" << endl;
                } else {
                        s[i] = char(v + '0');
                        add(i);
                        if (st.size()) {
                                cout << "Yes" << endl;
                        } else {
                                cout << "No" << endl;
                        }
                }
                s[i] = char(v + '0');
        }
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
