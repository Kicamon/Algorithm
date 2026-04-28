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
//#pragma GCC optimize(2)
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
const int N = 2e5 + 10, inf = 0x3f3f3f3f;

int num[N];

template <class T> struct ST {
        struct node {
                int size;
                int val;
                int num, ln, rn;
        } tr[N << 2];

        void pushup(int u) {
                node &f = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
                f.ln = min(l.ln, r.ln), f.rn = max(l.rn, r.rn);
                f.num = l.num + r.num;
                f.val = l.val + r.val;
                if (l.rn && r.ln != inf) {
                        int t = r.ln - l.rn - 1;
                        if (r.val >= t)
                                f.num += t * (t + 1) >> 1;
                        else
                                f.num += t *
                }
        }

        void pushdown(int u) {
                node &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
                l.mul = (ll)l.mul * root.mul, l.add = ((ll)l.add * root.mul + root.add);
                l.num = ((ll)l.num * root.mul + (ll)root.add * l.size);
                r.mul = (ll)r.mul * root.mul, r.add = ((ll)r.add * root.mul + root.add);
                r.num = ((ll)r.num * root.mul + (ll)root.add * r.size);
                root.add = 0, root.mul = 1;
        }

        void build(int u, int l, int r) {
                if (l == r) {
                        tr[u] = { r - l + 1, a[l], 1, 0 };
                        return;
                }
                tr[u] = { r - l + 1, 0, 1, 0 };
                int mid = l + r >> 1;
                build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
                pushup(u);
        }

        void modify(int u, int l, int r, int pl, int pr, int add, int mul) {
                if (l <= pl && pr <= r) {
                        tr[u].mul = (ll)tr[u].mul * mul;
                        tr[u].add = ((ll)tr[u].add * mul + add);
                        tr[u].num = ((ll)tr[u].num * mul + (ll)add * tr[u].size);
                        return;
                }
                pushdown(u);
                int mid = pl + pr >> 1;
                if (l <= mid)
                        modify(u << 1, l, r, pl, mid, add, mul);
                if (r > mid)
                        modify(u << 1 | 1, l, r, mid + 1, pr, add, mul);
                pushup(u);
        }

        T query(int u, int l, int r, int pl, int pr) {
                if (l <= pl && pr <= r)
                        return tr[u].num;
                int mid = pl + pr >> 1;
                pushdown(u);
                T res = 0;
                if (l <= mid)
                        res = ((ll)res + query(u << 1, l, r, pl, mid));
                if (r > mid)
                        res = ((ll)res + query(u << 1 | 1, l, r, mid + 1, pr));
                return res;
        }
};

void solve() {
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int t = 1;
        if (input)
                cin >> t;
        while (t--)
                solve();

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
