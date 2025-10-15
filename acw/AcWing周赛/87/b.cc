//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n, m;
        cin >> n >> m;
        vint a(n);
        for (int i = 0; i < n; ++i)
                cin >> a[i];

        auto check = [&](int mid) {
                vint b = a;
                sort(b.begin(), b.begin() + mid + 1);
                int res = m;
                for (int i = mid; i >= 0; i -= 2)
                        res -= b[i];
                return res >= 0;
        };

        int l = 0, r = n;
        while (l < r) {
                int mid = l + r + 1 >> 1;
                if (check(mid - 1))
                        l = mid;
                else
                        r = mid - 1;
        }
        cout << l << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
