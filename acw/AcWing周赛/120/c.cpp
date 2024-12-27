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
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 2e5 + 10;
const int mod = 1e9 + 10;

int ss[26], sb[26];
int ts[26], tb[26];

template <class T> struct C
{
    T qmi(T a, T b, T p) {
        T res = 1;
        while (b) {
            if (b & 1)
                res = (ll)res * a % p;
            b >>= 1;
            a = (ll)a * a % p;
        }
        return res;
    }

    T fct[N], infct[N];

    void init() {
        fct[0] = infct[0] = 1;
        for (int i = 1; i < N; ++i) {
            fct[i] = (ll)fct[i - 1] * i % mod;
            infct[i] = (ll)infct[i - 1] * qmi(i, mod - 2, mod) % mod;
        }
    }

    int get(T a, T b) // a为底
    {
        return (fct[a] * infct[b] % mod * infct[a - b] % mod);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    C<int> c;
    string s, t;
    cin >> s >> t;
    sort(all(s)), sort(all(t));
    for (int i = 0; i < s.size(); ++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            ss[s[i] - 'a']++;
        } else {
            sb[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < t.size(); ++i) {
        if ('a' <= t[i] && t[i] <= 'z') {
            ts[t[i] - 'a']--;
        } else {
            tb[t[i] - 'A']--;
        }
    }
    int res = 0, cnt = 0;
    bool f = true, F = true;
    for (int i = 0; i < 26; ++i) {
        if (f && ss[i] <= ts[i]) {
            res += c.get(ts[i], ss[i]);
        } else {
            res = 0;
            f = false;
        }
        if (f && sb[i] <= tb[i]) {
            res += c.get(ts[i], ss[i]);
        } else {
            res = 0;
            f = false;
        }
        if (ss[i] + sb[i] <= ts[i] + tb[i]) {
            cnt += c.get(ts[i] + tb[i], ss[i] + sb[i]);
        } else {
            cnt = 0;
            F = false;
        }
    }
    cout << res << ' ' << cnt << endl;

    return 0;
}
