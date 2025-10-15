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

int n, m;
struct node {
        int size, l, r;
} tr[N << 2];

void build(int u, int l, int r) {
        tr[u] = { r - l + 1, 0, 0 };
        if (l == r) {
                return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void pushup(int u) {
        node &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
        root.l = l.l == l.size ? l.size + r.l : l.l;
        root.r = r.r == r.size ? r.size + l.r : r.r;
}

void modify(int u, int x, int k, int l, int r) {
        if (l == r) {
                tr[u].l = tr[u].r = k;
                return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) {
                modify(u << 1, x, k, l, mid);
        } else {
                modify(u << 1 | 1, x, k, mid + 1, r);
        }
        pushup(u);
}

int query(int u, int x, int l, int r) {
        if (l == x) {
                return tr[u].l;
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (x <= mid) {
                res += query(u << 1, x, l, mid);
                if (res == mid - x + 1) {
                        res += tr[u << 1 | 1].l;
                }
                return res;
        } else {
                return query(u << 1 | 1, x, mid + 1, r);
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m;
        build(1, 1, n);
        while (m--) {
                int opt, x;
                cin >> opt >> x;
                if (opt == 1) {
                        modify(1, x, 1, 1, n);
                } else if (opt == 2) {
                        modify(1, x, 0, 1, n);
                } else {
                        cout << query(1, x, 1, n) << endl;
                }
        }

        return 0;
}
