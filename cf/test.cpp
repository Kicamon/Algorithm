#include <bits/stdc++.h>

using namespace std;
#define int long long
bool f(int x)
{
    int o = sqrt(x);
    return (o * o == x || (o - 1) * (o - 1) == x || (o + 1) * (o + 1) == x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> xs;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int diff = a[i] - a[j];
                for (int d = 1; d * d <= diff; ++d)
                {
                    if (diff % d == 0)
                    {
                        int u = (d + diff / d) / 2;
                        xs.push_back(u * u - a[i]);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int j = sqrt(a[i]);
            ++j;
            xs.push_back(j * j - a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int res = 0;
        for (int x : xs)
        {
            if (x >= 0)
            {
                int answ = 0;
                for (int i = 0; i < n; ++i)
                {
                    answ += f(a[i] + x);
                }
                res = max(res, answ);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
