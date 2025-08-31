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
#include <vector>
#include <string>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 1e5 + 1, M = 1e9;

ll stn(string s) {
        ll res = 0, temp = 1;
        reverse(all(s));
        for (int i = 0; i < (int)s.size(); ++i, temp *= 10) {
                res += (s[i] - '0') * temp;
        }
        return res;
}

bool check(string s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
                if (s[l++] != s[r--]) {
                        return false;
                }
        }
        return true;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        set<int> st;
        for (int i = 1; i < N; ++i) {
                string s = to_string(i), ts = string(s.rbegin(), s.rend());
                if (check(s)) {
                        st.insert(i);
                }
                ll num = stn(s + ts);
                if (num < M && check(s + ts)) {
                        st.insert(num);
                }
                if (i < 10) {
                        continue;
                }
                ts = string(ts.begin() + 1, ts.end());
                num = stn(s + ts);
                if (num < M && check(s + ts)) {
                        st.insert(num);
                }
        }
        vector<int> primes;
        vector<bool> vis(N);
        vis[1] = true;
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
        vector<int> ans;
        for (int x : st) {
                if (x < N && !vis[x]) {
                        ans.push_back(x);
                } else {
                        bool flag = true;
                        for (int i : primes) {
                                if (i > x) {
                                        break;
                                }
                                if (x % i == 0) {
                                        flag = false;
                                        break;
                                }
                        }
                        if (flag) {
                                ans.push_back(x);
                        }
                }
        }

        int a, b;
        cin >> a >> b;
        for (int x : ans) {
                if (x > b) {
                        break;
                }
                if (a <= x) {
                        cout << x << endl;
                }
        }

        return 0;
}
