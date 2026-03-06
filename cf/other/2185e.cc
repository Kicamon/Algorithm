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
#include <functional>
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
        vector<array<int, 2>> ldis(n), rdis(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
                cin >> b[i];
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
                int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
                ldis[i][0] = !idx ? inf : a[i] - b[idx - 1];
                rdis[i][0] = idx == m ? inf : b[idx] - a[i];
                ldis[i][1] = rdis[i][1] = i;
        }
        sort(ldis.begin(), ldis.end());
        sort(rdis.begin(), rdis.end());
        int l = 0, r = 0, L = 0, R = 0;
        set<int> st;

        function<int(vector<array<int, 2>> &, int)> bs = [&](vector<array<int, 2>> &a, int x) {
                int l = 0, r = a.size();

                while (l < r) {
                        int mid = (l + r) >> 1;
                        if (a[mid][0] <= x) {
                                l = mid + 1;
                        } else {
                                r = mid;
                        }
                }

                return l;
        };

        while (k--) {
                char ch;
                cin >> ch;
                if (ch == 'L') {
                        l++;
                        r--;
                } else {
                        l--;
                        r++;
                }

                int idx = bs(ldis, l);
                for (int i = L; i < idx; ++i) {
                        st.insert(ldis[i][1]);
                }
                L = max(L, idx);
                idx = bs(rdis, r);
                for (int i = R; i < idx; ++i) {
                        st.insert(rdis[i][1]);
                }
                R = max(R, idx);

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
