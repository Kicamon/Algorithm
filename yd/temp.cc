#include <iostream>
#include <random>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

vector<int> f1(int n, int m, int k) {
        vector<int> a;
        int res = 0;
        for (int i = 0, x = -1, idx = 1; i < m; ++i, x = (x + idx) % n, ++idx) {
                a.push_back(idx % n);
                if ((x + idx) % n == k) {
                        res++;
                }
        }
        return a;
}

vector<int> f2(int n, int m, int k) {
        vector<int> a;
        ll res = 0, vis = 0;
        int x = -1, idx = 1;
        while (m--) {
                a.push_back(idx);
                if ((x + idx) % n == k) {
                        res++;
                }
                x = (x + idx) % n;
                idx = (idx + 1) % n;

                if (vis && x == 0 && idx == 2) {
                        res += res * (m - 1) / vis;
                        m = (m - 1) % vis;
                        m++;
                }

                vis++;
        }
        return a;
}

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int flag = true;
        while (flag) {
                random_device seed; //硬件生成随机数种子
                ranlux48 engine(seed()); //利用种子生成随机数引擎
                uniform_int_distribution<> distrib(1, 1e6); //设置随机数范围，并为均匀分布
                int n, m, k;
                m = distrib(engine);
                uniform_int_distribution<> ccc(m * (m - 1) / 2, 1e6);
                n = ccc(engine);
                uniform_int_distribution<> bbb(1, n);
                k = bbb(engine);
                // cin >> n >> m >> k;
                k--;
                auto a = f1(n, m, k), b = f2(n, m, k);
                for (int i = 0; i < a.size(); ++i) {
                        if (a[i] != b[i]) {
                                cout << n << ' ' << m << ' ' << k << endl;
                                flag = false;
                                break;
                        }
                }
        }
        return 0;
}
