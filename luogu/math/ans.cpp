#include <bits/stdc++.h>
#define int long long
using namespace std;
char ch[20][20]; // 读入的地图
const int mod = 1000000000;
int n, m, cnt, ans = 1, id[20][20], A[100][100];
// A 是拉普拉斯矩阵，id 是地图中的格子的编号
void add(int x, int y) {
    A[x][y]--;
    A[y][x]--;
    A[x][x]++;
    A[y][y]++;
}
// 对于一个边，修改拉普拉斯矩阵
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ch[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ch[i][j] == '.')
                id[i][j] = ++cnt;
    // 将地图中的格子进行编号
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (ch[i][j] == '.' && ch[i + 1][j] == '.')
                add(id[i][j], id[i + 1][j]);
            if (ch[i][j] == '.' && ch[i][j + 1] == '.')
                add(id[i][j], id[i][j + 1]);
            // 只加向下的边和向右的边，防止重复
        }
    cnt--; // 去掉拉普拉斯矩阵的最后一行一列
    for (int i = 1; i < cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            while (A[j][i]) {
                int l = A[i][i] / A[j][i];
                // 这里不能直接取模，要先计算商
                for (int k = 1; k <= cnt; k++) {
                    A[i][k] = (A[i][k] - A[j][k] * l % mod + mod) % mod;
                }
                for (int k = 1; k <= cnt; k++)
                    swap(A[i][k], A[j][k]);
                ans *= -1;
                // 每次交换两行，将答案取相反数
            }
        }
    }
    for (int i = 1; i <= cnt; i++)
        ans = (ans * A[i][i] % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}
