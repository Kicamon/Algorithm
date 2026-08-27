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
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class BIT {
    private:
        vector<int> a;
        int n;

    public:
        BIT(int _n) {
                n = _n;
                a.resize(n + 1);
        }

        int lowbit(int x) {
                return x & -x;
        }

        void modify(int x, int d) {
                for (int i = x; i <= n; i += lowbit(i)) {
                        a[i] += d;
                }
        }

        int query(int x) {
                int res = 0;
                for (int i = x; i; i -= lowbit(i)) {
                        res += a[i];
                }
                return res;
        }
};

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        BIT bit(n);
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        for (int i = 2; i < n; ++i) {
                bit.modify(i, a[i] - a[i - 1] < a[i + 1] - a[i]);
        }
        int op, p, x, l, r;
        while (q--) {
                cin >> op;
                if (op == 1) {
                        cin >> p >> x;
                        if (p == 1 || p == n) {
                                a[p] = x;
                                continue;
                        }
                        if (p >= 2) {
                                bit.modify(p - 1, (a[p - 1] - a[p - 2] < x - a[p - 1])
                                                      - (a[p - 1] - a[p - 2] < a[p] - a[p - 1]));
                        }
                        bit.modify(p, (x - a[p - 1] < a[p + 1] - x)
                                          - (a[p] - a[p - 1] < a[p + 1] - a[p]));
                        if (p <= n - 2) {
                                bit.modify(p + 1, (a[p + 1] - x < a[p + 2] - a[p + 1])
                                                      - (a[p + 1] - a[p] < a[p + 2] - a[p + 1]));
                        }
                        a[p] = x;
                } else {
                        cin >> l >> r;
                        cout << bit.query(r - 1) - bit.query(l) << '\n';
                }
        }

        return 0;
}
