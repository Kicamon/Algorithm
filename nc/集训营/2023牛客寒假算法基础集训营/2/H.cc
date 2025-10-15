//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 1e5;

void solve() {
        vint num(N + 1, 0);
        vint res(N + 1, 0);
        vint sum(N + 1, 0);
        int n;
        cin >> n;
        for (int i = 0, c; i < n; ++i) {
                cin >> c;
                res[num[c]] -= num[c];
                sum[num[c]]--;
                num[c]++;
                res[num[c]] += num[c];
                sum[num[c]]++;
        }
        for (int i = 1; i <= n; ++i) {
                sum[i] += sum[i - 1];
                res[i] += res[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
                int k = res[i];
                if (i != 1)
                        k += (sum[n] - sum[i]) * (i - 1);
                cout << k << endl;
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int t;
        cin >> t;
        while (t--)
                solve();

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
