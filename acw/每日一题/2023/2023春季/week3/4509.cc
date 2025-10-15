#include <bits/stdc++.h>
using namespace std;

int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        long double res = 0;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                res += a[i];
        }
        res /= n;
        long double cnt = 0;
        for (int i = 0; i < n; ++i)
                cnt += (a[i] - res) * (a[i] - res);
        cnt = sqrt(cnt / n);
        for (int i = 0; i < n; ++i)
                printf("%LF\n", (a[i] - res) / cnt);

        return 0;
}
