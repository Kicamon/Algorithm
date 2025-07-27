#include <bits/stdc++.h>
#define ios                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define lowbit(x) ((x) & -(x))
#define pb push_back
#define SZ(v) ((int)v.size())
#define PI acos(-1)
#define x first
#define y second
#define mem(a, b) memset((a), (b), sizeof(a))
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-6;
const int MAX = 2e5 + 10;
const ll mod = 1e9 + 7;
/********************************* std-head *********************************/
int cnt[2000010], n, x[3010], y[2010], vis[3010][3010];
int dis(int i, int j)
{
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
int main()
{
    ios;
    int n;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> x[i] >> y[i];
        vis[x[i] + 1500][y[i] + 1500] = 1;
    }
    ll ans = 0, line = 0;
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if (i == j)
                continue;
            ans += cnt[dis(i, j)]; // 枚举优化关键，先累加在统计记录相同距离数据的数量
            cnt[dis(i, j)]++;
            if (vis[2 * x[i] - x[j] + 1500][2 * y[i] - y[j] + 1500] == 1)
                line++; // 找到与x[j]y[j]共线的点，中点为x[i]y[i]
        }
        rep(j, 1, n)
        {
            if (i == j)
                continue;
            cnt[dis(i, j)] = 0;
        }
    }
    cout << ans - line / 2 << endl;
}
