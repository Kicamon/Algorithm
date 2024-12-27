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
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

ll get_num(string str) {
        ll num = 0;
        while (str.size()) {
                int idx = str.find("mul(");
                if (idx == -1) {
                        break;
                }
                str = str.substr(idx);
                string tn;
                int tnum[2] = { 0, 0 };
                int p = 0;
                for (int i = 4; i < (int)str.size(); i++) {
                        if (str[i] >= '0' && str[i] <= '9') {
                                tn += str[i];
                        } else if (str[i] == ',') {
                                tnum[0] = stoi(tn);
                                tn = "";
                        } else if (str[i] == ')') {
                                tnum[1] = stoi(tn);
                                num += tnum[0] * tnum[1];
                                p = i;
                                break;
                        } else {
                                p = i;
                                break;
                        }
                }
                str = str.substr(p);
        }
        return num;
}

ll get_ans(string &str) {
        ll num = 0;
        int idx, eidx = str.find("don't()");
        if (eidx == -1) {
                return get_num(str);
        }
        string s = str.substr(0, eidx);
        num = get_num(s);
        str = str.substr(eidx);

        while (true) {
                idx = str.find("do()");
                if (idx == -1) {
                        break;
                }
                str = str.substr(idx);
                eidx = str.find("don't()");
                if (eidx == -1) {
                        num += get_num(str);
                        break;
                }
                s = str.substr(0, eidx);
                num += get_num(s);
                str = str.substr(eidx + 1);
        }

        return num;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        ll ans = 0;
        ifstream fp("input.txt");
        if (!fp.is_open()) {
                return 1;
        }
        string str;
        string s;
        while (getline(fp, str)) {
                s += str;
        }
        ans = get_ans(s);
        cout << ans << endl;

        return 0;
}
