#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    multiset<int> a, ans;
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            if (!a.empty()) {
                auto nxt = a.upper_bound(x), pos = (nxt == a.begin() ? nxt : prev(nxt));
                if (nxt != a.begin()) {
                    ans.extract(*pos ^ *nxt);
                    ans.insert(*pos ^ x);
                }
                if (nxt != a.end()) {
                    ans.insert(x ^ *nxt);
                }
            }
            a.insert(x);
        } else if (op == 2) {
            int x;
            cin >> x;
            auto pos = a.lower_bound(x), prv = (pos == a.begin() ? pos : prev(pos)), nxt = next(pos);
            if (pos != a.begin()) {
                ans.extract(*prv ^ *pos);
            }
            if (nxt != a.end())
                ans.extract(*pos ^ *nxt);
            if (pos != a.begin() && nxt != a.end())
                ans.insert(*prv ^ *nxt);
            a.extract(x);
        } else {
            cout << *ans.begin() << '\n';
        }
    }

    return 0;
}
