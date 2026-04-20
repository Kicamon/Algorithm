//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 50010;

vint primes;
array<int, 2> factor[N];
int idx, cnt;
int num[N];

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

template <typename T> T gcd(T a, T b) {
        return b ? gcd(b, a % b) : a;
}

void dfs(int u, int p) {
        if (u > cnt) {
                num[idx++] = p;
                return;
        }
        for (int i = 0; i <= factor[u][1]; ++i) {
                dfs(u + 1, p);
                p *= factor[u][0];
        }
}

void solve() {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int t = d;
        cnt = 0;
        for (int i : primes) {
                if (i * i > t)
                        break;
                if (t % i == 0) {
                        int s = 0;
                        while (t % i == 0)
                                s++, t /= i;
                        factor[++cnt] = { i, s };
                }
        }
        if (t > 1)
                factor[++cnt] = { t, 1 };
        idx = 0;
        dfs(1, 1);
        int res = 0;
        for (int i = 0; i < idx; ++i) {
                int x = num[i];
                if (gcd(x, a) == b && (ll)x * c / gcd(x, c) == d)
                        res++;
        }
        cout << res << endl;
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
