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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define Debug(x) cout << #x << ':' << x << endl
int input = 1;
const int N = 1e5 + 10;
int n;

struct segment {
        double x, y1, y2;
        int k;
        bool operator<(const segment &t) const {
                return x < t.x;
        }
} seg[N << 1];

struct node {
        int l, r;
        int num;
        double len;
} tr[N << 3];

vector<double> ys;

int find(double y) {
        return lower_bound(all(ys), y) - ys.begin();
}

void pushup(int u) {
        if (tr[u].num)
                tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
        else if (tr[u].l != tr[u].r)
                tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
        else
                tr[u].len = 0;
}

void build(int u, int l, int r) {
        tr[u] = { l, r, 0, 0 };
        if (l == r)
                return;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int k) {
        if (l <= tr[u].l && tr[u].r <= r)
                tr[u].num += k;
        else {
                int mid = tr[u].l + tr[u].r >> 1;
                if (l <= mid)
                        modify(u << 1, l, r, k);
                if (r > mid)
                        modify(u << 1 | 1, l, r, k);
        }
        pushup(u);
}

void solve() {
        ys.clear();
        for (int i = 0, j = 0; i < n; ++i) {
                double x1, y1, x2, y2;
                scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
                seg[j++] = { x1, y1, y2, 1 }, seg[j++] = { x2, y1, y2, -1 };
                ys.pb(y1), ys.pb(y2);
        }
        sort(all(ys));
        ys.erase(unique(all(ys)), ys.end());
        build(1, 0, ys.size() - 2);
        sort(seg, seg + n * 2);
        double res = 0;
        for (int i = 0; i < n * 2; ++i) {
                if (i)
                        res += tr[1].len * (seg[i].x - seg[i - 1].x);
                modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }
        printf("Total explored area: %.2lf\n\n", res);
}

signed main() {
        // clock_t start, finish;
        // start = clock();

        int t = 1;
        while (scanf("%d", &n), n) {
                printf("Test case #%d\n", t++);
                solve();
        }

        // finish = clock();
        // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
