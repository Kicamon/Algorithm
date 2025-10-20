/*
       ┌─────┐
       │ ... │
       └──┬──┘
    ┌───┐ │ ┌───────┐
    │ 5 │ │ │ n - 1 │
    └───┤ │ ├───────┘
        ├─┴─┤
        │ 2 │
        ├───┤
    ┌───┤   ├───┐
    │ 1 │   │ 3 │
    ├───┘   └───┤
┌───┤           ├───┐
│ n │           │ 4 │
└───┘           └───┘

当n>=5时，采取上图的连接方式，其中'...'表示∀ i ∈ [5,n)，都与2连接，可得：

1. 上半部分的值：
       ┌─────┐
       │ ... │
       └──┬──┘
    ┌───┐ │ ┌───────┐
    │ 5 │ │ │ n - 1 │
    └───┤ │ ├───────┘
        ├─┴─┤
        │ 2 │
        └───┘
(n - 1 + 5) / 2 * (n - 1 - 4) * 2 = n^2 - n - 20

2. 下半部分的值：
        ┌───┐
        │ 2 │
        ├───┤
    ┌───┤   ├───┐
    │ 1 │   │ 3 │
    ├───┘   └───┤
┌───┤           ├───┐
│ n │           │ 4 │
└───┘           └───┘
n + 2 + 2 * 3 + 3 * 4 = n + 20


上半部分的值+上半部分的值 = n + 20 + n^2 - n - 20 = n^2，为完全平方数
*/
/* #pragma GCC optimize(2) */
#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

void solve() {
        int n;
        cin >> n;
        if (n == 2) {
                cout << -1 << endl;
                return;
        }
        if (n == 3) {
                cout << "1 3\n2 3\n";
                return;
        }
        if (n == 4) {
                cout << "1 2\n1 3\n1 4\n";
                return;
        }
        cout << "1 2\n2 3\n3 4\n";
        cout << 1 << ' ' << n << endl;
        for (int i = 5; i < n; ++i) {
                cout << 2 << ' ' << i << endl;
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0;
}
