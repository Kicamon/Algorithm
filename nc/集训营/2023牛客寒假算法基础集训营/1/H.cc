// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

void solve() {
        int n;
        cin >> n;
        int num[2]{};
        char s[5];
        for (int i = 1; i < n * n; ++i) {
                cin >> s;
                for (int j = 0; j < 4; ++j)
                        if (s[j] == '1')
                                num[0]++;
                        else if (s[j] == '2')
                                num[1]++;
        }
        cout << 10 + num[0] - num[1] << endl;
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
