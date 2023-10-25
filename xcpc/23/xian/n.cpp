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
#include <numeric>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
#define int long long

string py[5];

string get(int &i, string &s, int ec) {
    string res;
    i++;
    while (s[i] != ec) {
        res += s[i++];
    }
    return res;
}

vector<int> get(string &s) {
    vector<int> re;
    queue<string> q;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ',') {
            cnt++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            q.push(get(i, s, ','));
            if (cnt == 2) {
                q.push(get(i, s, ','));
            }
            q.push(get(i, s, ')'));
        }
    }
    re.push_back(0);
    cnt = 0;
    while (!q.empty()) {
        string t = q.front();
        q.pop();
        if (t[0] != '-' && (t[0] < '0' || t[0] > '9')) {
            re[0] = 1;
        } else {
            int res = 0;
            if (t[0] == '-') {
                for (int i = 1; i < t.size(); ++i) {
                    res = res * 10 + (t[i] - '0');
                }
                res = -res;
                re.push_back(res);
            } else {
                for (int i = 0; i < t.size(); ++i) {
                    res = res * 10 + (t[i] - '0');
                }
                re.push_back(res);
            }
            cnt += !re[0];
        }
    }
    if (re[0]) {
        re.push_back(cnt);
    }
    return re;
}

vector<int> get(int l, int r, int ra) {
    vector<int> res;
    if (ra < 0) {
        if (l > r) {
            for (int i = l; i > r; i += ra) {
                res.push_back(i);
            }
        }
    } else {
        if (l < r) {
            for (int i = l; i < r; i += ra) {
                res.push_back(i);
            }
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; ++i) {
        getline(cin, py[i]);
    }
    vector<int> ele[2];
    ele[0] = get(py[1]);
    ele[1] = get(py[2]);
    vector<int> ele1 = get(ele[0][1], ele[0][2], ele[0].size() == 4 ? ele[0][3] : 1);
    vector<int> ele2;
    int res = 0;
    if (ele[1][0] == 0) {
        ele2 = get(ele[1][1], ele[1][2], ele[1].size() == 4 ? ele[1][3] : 1);
        if (!ele2.empty()) {
            res += accumulate(all(ele2), 0);
        }
        res *= ele1.size();
    } else {
        if (ele[1].back() == 0) {
            for (int x : ele1) {
                ele2 = get(x, ele[1][1], ele[1].size() == 4 ? ele[1][2] : 1);
                res += accumulate(all(ele2), 0);
            }
        } else if (ele[1].back() == 1) {
            for (int x : ele1) {
                ele2 = get(ele[1][1], x, ele[1].size() == 4 ? ele[1][2] : 1);
                res += accumulate(all(ele2), 0);
            }
        } else {
            for (int x : ele1) {
                ele2 = get(ele[1][1], ele[1][2], x);
                res += accumulate(all(ele2), 0);
            }
        }
    }
    cout << res << endl;

    return 0;
}
