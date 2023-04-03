#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e6 + 10;
#define LL long long

int n, m, mod;
int e[M], ne[M], h[N], hs[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int Size[N];
int id[N], id_idx;
int f[N], g[N];

void add(int *h, int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (!id[j])
            low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        ++id_idx;
        int y;
        do
        {
            y = stk[top--];
            id[y] = id_idx;
            Size[id_idx]++;
        } while (y != u);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    scanf("%d%d%d", &n, &m, &mod);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(h, a, b);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    unordered_set<LL> H;
    for (int i = 1; i <= n; i++)
        for (int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            LL hash = a * 1000000ll + b;
            if (a != b && !H.count(hash))
            {
                add(hs, a, b);
                H.insert(hash);
            }
        }

    for (int i = id_idx; i; i--)
    {
        if (!f[i])
        {
            f[i] = Size[i];
            g[i] = 1;
        }
        for (int j = hs[i]; ~j; j = ne[j])
        {
            int k = e[j];
            if (f[k] < f[i] + Size[k])
            {
                f[k] = f[i] + Size[k];
                g[k] = g[i];
            }
            else if (f[k] == f[i] + Size[k])
                g[k] = (g[k] + g[i]) % mod;
        }
    }

    int max_val = 0, num = 0;
    for (int i = 0; i <= id_idx; i++)
    {
        if (f[i] > max_val)
        {
            max_val = f[i];
            num = g[i];
        }
        else if (f[i] == max_val)
            num = (num + g[i]) % mod;
    }

    cout << max_val << endl << num << endl;

    return 0;
}
