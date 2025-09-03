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
#include <iterator>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 1e5 + 10, M = 1e8;

string nts(ll u) {
        string num;
        while (u) {
                num += u % 10 + '0';
                u /= 10;
        }
        reverse(all(num));
        return num;
}

ll stn(string s) {
        ll num = 0;
        for (char c : s) {
                num = num * 10 + int(c - '0');
        }
        return num;
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

        set<ll> st;
        for (int i = 1; i < N; ++i) {
                string num = nts(i);
                if (check(num)) {
                        st.insert(i);
                }
                string temp = string(num.rbegin() + 1, num.rend());
                if (stn(num + temp) > M) {
                        continue;
                }
                st.insert(stn(num + temp));
                temp = string(num.rbegin(), num.rend());
                if (stn(num + temp) > M) {
                        continue;
                }
                st.insert(stn(num + temp));
        }

        vector<int> prime;
        vector<bool> vis(N);
        vis[0] = vis[1] = 1;
        for (int i = 2; i < N; ++i) {
                if (!vis[i]) {
                        prime.push_back(i);
                }
                for (int j : prime) {
                        if (1ll * i * j >= N) {
                                break;
                        }
                        vis[i * j] = true;
                        if (i % j == 0) {
                                break;
                        }
                }
        }
        vector<ll> ans;
        for (ll x : st) {
                if (x < N && !vis[x]) {
                        ans.push_back(x);
                } else {
                        bool flag = true;
                        for (int i : prime) {
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

        ll a, b;
        cin >> a >> b;
        for (ll x : ans) {
                if (a <= x && x <= b) {
                        cout << x << endl;
                }
        }

        return 0;
}
