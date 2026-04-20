#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e7 + 10;
#define ll long long

template <class T> struct Prime2 {
        int primes[50010], _primes[N];
        int cnt, _cnt;
        bool vis[N];

        void prime(int n) {
                for (int i = 2; i <= n; ++i) {
                        if (!vis[i])
                                primes[cnt++] = i;
                        for (int j = 0; primes[j] * i <= n; ++j) {
                                vis[(ll)i * primes[j]] = true;
                                if (i % primes[j] == 0)
                                        break;
                        }
                }
        }

        Prime2() {
                prime(50000);
        }

        void init(int l, int r) {
                memset(vis, 0, sizeof vis);
                memcpy(_primes, primes, sizeof primes);
                _cnt = cnt;
                for (int i = 0; i < _cnt; ++i) {
                        ll p = _primes[i];
                        for (ll j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p)
                                vis[j - l] = true;
                }

                _cnt = 0;
                for (int i = 0; i <= r - l; ++i) {
                        if (!vis[i] && i + l >= 2)
                                _primes[_cnt++] = i + l;
                }
        }
};

int main() {
        Prime2<int> c;
        int l, r;
        while (cin >> l >> r) {
                c.init(l, r);
                if (c._cnt < 2)
                        printf("There are no adjacent primes.\n");
                else {
                        int minp = 0, maxp = 0;
                        for (int i = 0; i + 1 < c._cnt; ++i) {
                                int d = c._primes[i + 1] - c._primes[i];
                                if (d < c._primes[minp + 1] - c._primes[minp])
                                        minp = i;
                                if (d > c._primes[maxp + 1] - c._primes[maxp])
                                        maxp = i;
                        }
                        printf("%d,%d are closest, %d,%d are most distant.\n", c._primes[minp],
                               c._primes[minp + 1], c._primes[maxp], c._primes[maxp + 1]);
                }
        }
        return 0;
}
