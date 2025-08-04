#include <cstdio>
#include <cstring>
const int MAXN = 1010;
const int MAXM = 210;
const int mod = (int)(1e9) + 7;
long long dp[2][MAXM][MAXM][2];
char a[MAXN], b[MAXM];
int n, m, p;
bool val = 1;

void f() {
        dp[0][0][0][0] = dp[1][0][0][0] = 1;
        int val = 1;
        for (int i = 1; i <= n; ++i, val ^= 1) {
                for (int j = 1; j <= m; ++j) {
                        for (int k = 1; k <= p; ++k) {
                                if (a[i] == b[j]) {
                                        dp[val][j][k][0] =
                                                (dp[val ^ 1][j][k][0] + dp[val ^ 1][j][k][1]) % mod;
                                        dp[val][j][k][1] = (dp[val ^ 1][j - 1][k][1] +
                                                            dp[val ^ 1][j - 1][k - 1][1] +
                                                            dp[val ^ 1][j - 1][k - 1][0]) %
                                                           mod;
                                } else {
                                        dp[val][j][k][0] =
                                                (dp[val ^ 1][j][k][0] + dp[val ^ 1][j][k][1]) % mod;
                                        dp[val][j][k][1] = 0;
                                }
                        }
                }
        }
}

int main() {
        scanf("%d%d%d", &n, &m, &p);
        scanf("%s%s", a + 1, b + 1);
        f();
        printf("%lld\n", (dp[n & 1][m][p][0] + dp[n & 1][m][p][1]) % mod);
        return 0;
}
