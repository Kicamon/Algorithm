//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define ing long long

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n, m;
        cin >> n >> m;
        vint v(n + 1);
        for (int i = 1; i <= n; ++i)
                cin >> v[i];
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q[n + 1];
        vint num(n + 1, 0);
        while (m--) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                while (!q[b].empty()) {
                        array<int, 2> t = q[b].top();
                        //			cout << t[0] << ' ' << a << endl;
                        if (t[0] <= a) {
                                num[b] -= t[1];
                                q[b].pop();
                        } else
                                break;
                }
                if (d + num[b] <= v[b]) {
                        q[b].push({ a + c, d });
                        num[b] += d;
                        cout << v[b] - num[b] << endl;
                } else
                        cout << -1 << endl;
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
