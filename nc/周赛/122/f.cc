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
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()
const int inf = 0x3f3f3f3f;

class SGT {
    private:
        vector<int> a, node;

    public:
        SGT(const vector<int> &t, int n) {
                a = t;
                node.resize(n << 2);
                build(1, 1, n);
        }

        void build(int u, int l, int r) {
                if (l == r) {
                        node[u] = l;
                        return;
                }
                int mid = (l + r) >> 1;
                build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
                int tl = node[u << 1], tr = node[u << 1 | 1];
                node[u] = a[tl] < a[tr] ? tr : tl;
        }

        int query(int u, int l, int r, int L, int R) {
                if (L <= l && r <= R) {
                        return node[u];
                }
                int mid = (l + r) >> 1;
                if (R <= mid) {
                        return query(u << 1, l, mid, L, R);
                }
                if (mid < L) {
                        return query(u << 1 | 1, mid + 1, r, L, R);
                }
                int tl = query(u << 1, l, mid, L, R), tr = query(u << 1 | 1, mid + 1, r, L, R);
                return a[tl] < a[tr] ? tr : tl;
        }
};

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        a[0] = -inf;
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
        }

        SGT st(a, n);

        for (int i = 1; i <= n; ++i) {
                int t = st.query(1, 1, n, i, min(i + k, n));
                if (k && a[t] < a[i - 1]) {
                        t = i - 1;
                        k--;
                } else {
                        k -= t - i;
                }
                cout << a[t] << ' ';
                while (i < t) {
                        cout << a[t] << ' ';
                        a[i++] = a[t];
                }
                a[i] = a[t];
        }
        cout << '\n';
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
