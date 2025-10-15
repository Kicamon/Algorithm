//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <cstring>
#include <math.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int N = 1e5 + 10;

struct Topsort {
        int n, m;
        int e[N], ne[N], h[N], idx;
        int into[N];
        int q[N];

        void add(int a, int b) {
                e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        }

        bool topsort() {
                int hh = 0, tt = 0;
                for (int i = 1; i <= n; ++i)
                        if (!into[i])
                                q[tt++] = i;
                while (hh < tt) {
                        int t = q[hh++];
                        for (int i = h[t]; ~i; i = ne[i]) {
                                int j = e[i];
                                into[j]--;
                                if (!into[j])
                                        q[tt++] = j;
                        }
                }
                if (tt == n)
                        return true;
                return false;
        }

        void init(int a, int b) {
                memset(h, -1, sizeof h);
                n = a, m = b;
                while (m--) {
                        cin >> a >> b;
                        add(a, b);
                        into[b]++;
                }
                bool f = topsort();
        }
};

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n, m;
        cin >> n >> m;
        Topsort s;
        s.init(n, m);

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
