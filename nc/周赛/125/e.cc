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
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;

struct Node {
        ll sum;
        int min, lazy;
        int len;
};

class ST {
    private:
        vector<Node> node;
        vector<int> a;

    public:
        ST(vector<int> _a, int n) {
                a = _a;
                node.resize(n << 2);
                build(1, 1, n);
        }

        void push_up(int u) {
                Node &l = node[u << 1], &r = node[u << 1 | 1];
                node[u].sum = l.sum + r.sum;
                node[u].min = min(l.min, r.min);
        }

        void push_down(int u) {
                Node &l = node[u << 1], &r = node[u << 1 | 1];
                if (node[u].lazy) {
                        l.lazy = l.min = r.lazy = r.min = node[u].lazy;
                        l.sum = node[u].lazy * l.len;
                        r.sum = node[u].lazy * r.len;
                }
                node[u].lazy = 0;
        }

        void build(int u, int l, int r) {
                node[u] = { 0, 0, 0, r - l + 1 };
                if (l == r) {
                        node[u] = { a[l], a[l], 0, 1 };
                        return;
                }
                int mid = (l + r) >> 1;
                build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
                push_up(u);
        }

        int get_min(int u, int l, int r, int L, int R) {
                if (L <= l && r <= R) {
                        return node[u].min;
                }
                push_down(u);
                int mid = (l + r) >> 1;
                int res = inf;
                if (L <= mid) {
                        res = min(res, get_min(u << 1, l, mid, L, R));
                }
                if (mid < R) {
                        res = min(res, get_min(u << 1 | 1, mid + 1, r, L, R));
                }
                push_up(u);
                return res;
        }

        void modify(int u, int l, int r, int L, int R, int x) {
                if (L <= l && r <= R) {
                        node[u].lazy = node[u].min = x;
                        node[u].sum = 1ll * x * (r - l + 1);
                        return;
                }
                push_down(u);
                int mid = (l + r) >> 1;
                if (L <= mid) {
                        modify(u << 1, l, mid, L, R, x);
                }
                if (mid < R) {
                        modify(u << 1 | 1, mid + 1, r, L, R, x);
                }
                push_up(u);
        }

        ll sum() {
                return node[1].sum;
        }
};

void solve() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        ST st(a, n);

        while (q--) {
                int o, x;
                cin >> o;
                if (o == 1) {
                        cin >> x;
                        st.modify(1, 1, n, 1, x, st.get_min(1, 1, n, 1, x));
                } else if (o == 2) {
                        cin >> x;
                        st.modify(1, 1, n, x, n, st.get_min(1, 1, n, x, n));
                } else {
                        cout << st.sum() << '\n';
                }
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
