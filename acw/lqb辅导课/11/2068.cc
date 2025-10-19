#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

int num[11][N];

template <typename T> int get_int_len(T x) {
        int len = 1;
        while (x /= 10)
                len++;
        return len;
}

int main() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                ll t = a[i] % m;
                for (int j = 0; j <= 10; ++j) {
                        num[j][t]++;
                        t = t * 10 % m;
                }
        }

        ll res = 0;
        for (int i = 0; i < n; ++i) {
                int len = get_int_len(a[i]);
                ll t = a[i] % m;
                res += num
                    [len]
                    [(m - t)
                     % m]; //(m - t) % m而不是m - t的原因是防止t=0的时候，y是余数不会取到m，下面的同理
                ll r = t;
                while (len--)
                        r = r * 10 % m;
                if (r == (m - t) % m)
                        res--;
        }
        cout << res << endl;

        return 0;
}
