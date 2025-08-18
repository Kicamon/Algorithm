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
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define endl '\n'
#define int long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int N = 3e6;

int tree[N << 2], tree_len;

void build(int u, int l, int r) {
        if (l == r) {
                return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void pushdown(int u) {
        tree[u << 1] = max(tree[u << 1], tree[u]);
        tree[u << 1 | 1] = max(tree[u << 1 | 1], tree[u]);
        tree[u] = 0;
}

void modify(int x, int val, int u, int l, int r) {
        if (l == x) {
                tree[u] = max(tree[u], val);
                return;
        }
        int mid = (l + r) >> 1;
        pushdown(u);
        if (x <= mid) {
                tree[u << 1 | 1] = max(tree[u << 1 | 1], val);
                modify(x, val, u << 1, l, mid);
        } else {
                modify(x, val, u << 1 | 1, mid + 1, r);
        }
}

int query(int x, int u = 1, int l = 1, int r = tree_len) {
        if (l == r) {
                return tree[u];
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        if (x <= mid) {
                return query(x, u << 1, l, mid);
        }
        return query(x, u << 1 | 1, mid + 1, r);
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<array<int, 2> > a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i][0] >> a[i][1];
                tree_len = max(tree_len, a[i][1]);
        }
        build(1, 1, tree_len);
        sort(all(a));
        for (auto x : a) {
                int temp = x[0] == 1 ? 0 : query(x[0] - 1);
                modify(x[1], temp + x[1] - x[0] + 1, 1, 1, tree_len);
        }
        cout << query(tree_len) << endl;

        return 0;
}
