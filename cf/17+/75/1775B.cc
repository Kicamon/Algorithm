// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 2e5 + 10;

map<int, int> num;

void solve() {
        int n;
        cin >> n;
        num.clear();
        vector<int> a[n];
        for (int i = 0, k; i < n; ++i) {
                cin >> k;
                for (int j = 0, c; j < k; ++j) {
                        cin >> c;
                        a[i].pb(c);
                        num[c]++;
                }
        }
        for (int i = 0; i < n; ++i) {
                bool f = true;
                for (auto x : a[i]) {
                        if (num[x] <= 1) {
                                f = false;
                                break;
                        }
                }
                if (f) {
                        puts("YES");
                        return;
                }
        }
        puts("NO");
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
