//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 5e4;

vint primes;
void prime(int n) {
        vector<bool> vis(n + 1);
        vis[0] = vis[1] = 1;
        for (int i = 2; i <= n; i++) {
                if (!vis[i])
                        primes.push_back(i);
                for (int j = 0; primes[j] * i <= n; j++) {
                        vis[primes[j] * i] = 1;
                        if (i % primes[j] == 0)
                                break;
                }
        }
}

vector<array<int, 2>> res;
int n, m1, m2;

int check(ll p) {
        ll cnt = n;
        int l = 0, r = n + 1;
        while (l < r) {
                int mid = l + r >> 1;
                if (cnt * mid < p)
                        l = mid + 1;
                else
                        r = mid;
        }

        if (l != 0 && l != n + 1)
                return l;
        return 0;
}

ll ans = 0;
int ans_num = 0;

/*
存在的问题：
筛出的因子不存在于乘法表中
利用哥德巴赫猜想？
*/

void dfs(int u, ll p) {
        if (u == res.size()) {
                int k = check(p);
                if (k) {
                        cout << p << endl;
                        ans_num++;
                        ans ^= k;
                }
                return;
        }
        for (int i = 0; i <= res[u][1]; ++i) {
                dfs(u + 1, p);
                p *= res[u][0];
        }
}

void solve() {
        res.clear();
        ans = ans_num = 0;
        cin >> n >> m1 >> m2;
        for (int i : primes) {
                if (i * i > max(m1, m2))
                        break;
                if (i * i <= m1) {
                        if (m1 % i == 0) {
                                res.push_back({ i, 0 });
                                while (m1 % i == 0) {
                                        res[res.size() - 1][1]++;
                                        m1 /= i;
                                }
                        }
                }
                if (i * i <= m2) {
                        if (m2 % i == 0) {
                                if (res.back()[0] != i)
                                        res.push_back({ i, 0 });
                                while (m2 % i == 0) {
                                        res[res.size() - 1][1]++;
                                        m2 /= i;
                                }
                        }
                }
        }
        if (m1 > 1)
                res.push_back({ m1, 1 });
        if (m2 > 1) {
                if (m2 == m1)
                        res[res.size() - 1][1]++;
                else
                        res.push_back({ m2, 1 });
        }
        dfs(0, 1ll);
        cout << ans_num << ' ' << ans << endl;
        cout << endl;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        prime(N);

        int t;
        cin >> t;
        while (t--)
                solve();

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
