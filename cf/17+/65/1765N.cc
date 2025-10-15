#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 5e5 + 10;

int nex[N][10];

void solve() {
        string s;
        int k;
        cin >> s >> k;
        int n = s.size();
        for (int i = 0; i < 10; ++i)
                nex[n][i] = n;
        for (int i = n - 1; ~i; --i) {
                for (int j = 0; j < 10; ++j)
                        nex[i][j] = nex[i + 1][j];
                int w = s[i] - '0';
                nex[i][w] = i;
        }

        k = n - k;
        int pos = 0;
        string ans;
        for (int i = 0; i < k; ++i)
                for (int j = (i == 0); j < 10; ++j)
                        if (nex[pos][j] + k - i <= n) {
                                ans.pb(j + '0');
                                pos = nex[pos][j] + 1;
                                break;
                        }
        cout << ans << endl;
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
