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
#include <iostream>
#include <set>
#include <vector>
#include <array>
using namespace std;
const int inf = 0x3f3f3f3f;

void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        vector<array<int, 2>> l(n), r(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
                cin >> b[i];
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
                int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
                l[i][0] = idx == 0 ? inf : a[i] - b[idx - 1];
                r[i][0] = idx == m ? inf : b[idx] - a[i];
                l[i][1] = r[i][1] = i;
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        char ch;
        set<int> st;
        int ldis = 0, rdis = 0, L = 0, R = 0;
        while (k--) {
                cin >> ch;
                if (ch == 'L') {
                        ldis++;
                        rdis--;
                } else {
                        ldis--;
                        rdis++;
                }
                int t = upper_bound(l.begin(), l.end(), array<int, 2>{ ldis, 0 }) - l.begin();
                for (int i = L; i < t; ++i) {
                        st.insert(l[i][1]);
                }
                L = max(L, t);
                t = upper_bound(r.begin(), r.end(), array<int, 2>{ rdis, 0 }) - r.begin();
                for (int i = R; i < t; ++i) {
                        st.insert(r[i][1]);
                }
                R = max(R, t);
                cout << n - st.size() << ' ';
        }
        cout << '\n';
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
