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
        string s, t;
        cin >> s;
        int ans = n + 1;
        for (int k = 1; k <= 26; ++k) {
                if (n % k)
                        continue;
                vint num(26, 0);
                for (int i = 0; i < n; ++i)
                        num[s[i] - 'a']++;
                int p[26]{};
                iota(p, p + 26, 0);
                sort(p, p + 26, [&](int i, int j) {
                        return abs(num[i] - n / k) - num[i] < abs(num[j] - n / k) - num[j];
                });
                int res = 0;
                vector<bool> vis(26, 0);
                for (int i = 0; i < k; ++i) {
                        vis[p[i]] = true;
                        res += abs(num[p[i]] - n / k);
                }
                for (int i = k; i < 26; ++i)
                        res += num[p[i]];
                res /= 2;
                if (res >= ans)
                        continue;
                t = s;
                for (auto &ch : t) {
                        int x = ch - 'a';
                        int need = vis[x] ? n / k : 0;
                        if (need < num[x]) {
                                for (int i = 0; i < k; ++i) {
                                        if (num[p[i]] < n / k) {
                                                ch = p[i] + 'a';
                                                num[p[i]]++;
                                                num[x]--;
                                                break;
                                        }
                                }
                        }
                }
                ans = res;
        }
        cout << ans << endl << t << endl;
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
