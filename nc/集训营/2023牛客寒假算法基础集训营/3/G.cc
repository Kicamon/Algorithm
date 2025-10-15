//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int N = 20;
int num[N], idx;

template <typename T> ll qmi(ll a, ll b, T p) {
        T res = 1;
        a %= p;
        while (b) {
                if (b & 1)
                        res = (ll)res * a % p;
                b >>= 1;
                a = (ll)a * a % p;
        }
        return res;
}

char ans[N];
bool f = false;

void dfs(int u, ll res) {
        if (f)
                return;
        if (u == idx) {
                if (res == num[idx]) {
                        f = true;
                        cout << num[0];
                        for (int i = 1; i < idx; ++i)
                                cout << ans[i] << num[i];
                        cout << '=' << num[idx] << endl;
                }
                return;
        }
        ans[u] = '+';
        dfs(u + 1, res + num[u]);
        ans[u] = '-';
        dfs(u + 1, res - num[u]);
        if (res > 0 && num[u]) {
                ans[u] = '#';
                dfs(u + 1, qmi(res, res, num[u]));
        }
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        string s;
        cin >> s;
        int cnt = 0;
        for (char x : s) {
                if ('0' <= x && x <= '9')
                        cnt = cnt * 10 + (x - '0');
                else {
                        num[idx++] = cnt;
                        cnt = 0;
                }
        }
        num[idx] = cnt;
        dfs(1, (ll)num[0]);
        if (!f)
                cout << -1 << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
