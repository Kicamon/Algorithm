#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
vector<bool> vis(1e6 + 1, 0);

void prime(int n) {
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res += a[i];
    }
    if (!vis[res]) {
        cout << n - 1 << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (res % (n - i))
            continue;
        int cnt = res / (n - i);
        bool f = true;
        for (int j = 0, k = 0; j < n; ++j) {
            k += a[j];
            if (k == cnt)
                k = 0;
            if (k > cnt) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    prime(1e6);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
