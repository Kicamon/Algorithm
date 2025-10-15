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
const int N = 3e5 + 10, M = 9e6 + 10;

int tr[M][2], idx;
int pot[N];

void insert(int x) {
        vector<int> bit(30, 0);
        int cnt = 0;
        while (x) {
                bit[cnt++] = x % 2;
                x /= 2;
        }
        reverse(bit.begin(), bit.end());
        cnt = 0;
        for (int i : bit) {
                if (!tr[cnt][i]) {
                        tr[cnt][i] = ++idx;
                }
                cnt = tr[cnt][i];
        }
        pot[cnt]++;
}

void remove(int x) {
        vector<int> bit(30, 0);
        int cnt = 0;
        while (x) {
                bit[cnt++] = x % 2;
                x /= 2;
        }
        reverse(bit.begin(), bit.end());
        cnt = 0;
        for (int i : bit) {
                if (!tr[cnt][i ^ 1]) {
                        tr[cnt][i] = 0;
                        return;
                }
                cnt = tr[cnt][i];
        }
}

int query(int u, int num) {
        int l = tr[u][0], r = tr[u][1];
        if (pot[l] >= 2 || pot[r] >= 2) {
                return 0;
        }
        if (pot[l] || pot[r]) {
                return 1;
        }
        int res = INT_MAX;
        if (l) {
                l = min(res, query(l, num - 1));
        }
        if (r) {
                r = min(res, query(r, num - 1));
        }
        return res;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        int op;
        while (n--) {
                cin >> op;
                if (op == 1) {
                        int x;
                        cin >> x;
                        insert(x);
                } else if (op == 2) {
                        int x;
                        cin >> x;
                        remove(x);
                } else {
                        cout << query(0, 30) << endl;
                }
        }

        return 0;
}
