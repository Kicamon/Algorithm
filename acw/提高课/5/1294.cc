#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

vector<int> primes;

void prime(int n) {
        vector<bool> vis(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
                if (!vis[i])
                        primes.push_back(i);
                for (int j : primes) {
                        if (i * j > n)
                                break;
                        vis[i * j] = true;
                        if (i % j == 0)
                                break;
                }
        }
}

int main() {
        int n;
        cin >> n;
        prime(n);
        ll res = 1;
        for (int p : primes) {
                int num = 0;
                for (int i = n; i; i /= p)
                        num += i / p;
                res = (res * (num * 2 + 1)) % mod;
        }
        cout << res << endl;
        return 0;
}
