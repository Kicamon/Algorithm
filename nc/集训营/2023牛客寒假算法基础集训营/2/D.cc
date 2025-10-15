//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 2e5 + 10;
#define int long long

int e[N], ne[N], h[N], idx;
int a[N];
int num[N];

void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u) {
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
                int t = q.front();
                q.pop();
                num[t] = a[idx++];
                for (int i = h[t]; ~i; i = ne[i])
                        q.push(e[i]);
        }
}

int ans = 0;

int dfs(int u) {
        int res = num[u];
        for (int i = h[u]; ~i; i = ne[i])
                res += dfs(e[i]);
        ans += res;
        return res;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        memset(h, -1, sizeof h);
        int n;
        cin >> n;
        for (int i = 2, x; i <= n; ++i) {
                cin >> x;
                add(x, i);
        }
        for (int i = 0; i < n; ++i)
                cin >> a[i];
        sort(a, a + n);
        idx = 0;
        bfs(1);
        dfs(1);
        /*
	for(int i = 1;i <= n;++i)
		cout << num[i] << endl;
	*/
        cout << ans << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
