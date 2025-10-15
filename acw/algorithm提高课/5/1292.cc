#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
vector<bool> vis(1e6 + 1, 0);
void prime(int n) {
        for (int i = 2; i <= n; ++i) {
                if (!vis[i])
                        primes.push_back(i);
                for (int j : primes) {
                        if (i * j >= n)
                                break;
                        vis[i * j] = true;
                        if (i % j == 0)
                                break;
                }
        }
}

int main() {
        prime(1e6);
        int n;
        while (cin >> n && n) {
                for (int i : primes) {
                        if (!vis[n - i]) {
                                printf("%d = %d + %d\n", n, i, n - i);
                                break;
                        }
                }
        }
        return 0;
}
