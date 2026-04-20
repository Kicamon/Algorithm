//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

template <typename T> T exgcd(T a, T b, T &x, T &y) {
        if (!b) {
                x = 1, y = 0;
                return a;
        }

        T d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        ll a, b, m, n, k;
        cin >> a >> b >> m >> n >> k;
        ll x, y;
        ll d = exgcd(m - n, k, x, y);
        if ((b - a) % d)
                cout << "Impossible" << endl;
        else {
                x *= (b - a) / d;
                ll t = abs(k / d);
                cout << (x % t + t) % t << endl;
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
