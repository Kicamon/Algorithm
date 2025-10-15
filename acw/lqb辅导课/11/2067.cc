#include <bits/stdc++.h>
using namespace std;

int n, m;
int w[20][20];

int main() {
        cin >> n >> m;
        if (n % 2 == 0 && m % 2 == 0) {
                cout << 0 << endl;
                return 0;
        }
        n = (n + 1) >> 1, m = (m + 1) >> 1;
        w[1][0] = 1;
        for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                        w[i][j] = w[i - 1][j] + w[i][j - 1];
        cout << w[n][m] << endl;
        return 0;
}
