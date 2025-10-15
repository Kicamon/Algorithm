#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
#define ll long long

int num[N], ans[N];

int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                num[a[i]]++;
                m = max(m, a[i]);
        }
        for (int i = 1; i <= m; ++i) {
                for (int j = 1; (ll)i * j <= m; ++j)
                        ans[i * j] += num[i];
        }
        for (auto x : a)
                cout << ans[x] - 1 << endl;

        return 0;
}
