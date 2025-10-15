//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define ai2 array<int, 2>

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n;
        cin >> n;
        priority_queue<ai2, vector<ai2>, greater<ai2>> a, b;
        vector<ai2> x(n), y(n);
        for (int i = 0; i < n; ++i)
                cin >> x[i][0] >> x[i][1];
        for (int i = 0; i < n; ++i)
                cin >> y[i][0] >> y[i][1];
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
                a.push(x[i]), b.push(y[i]);
                while (!a.empty() && a.top()[0] <= l + 1) {
                        if (a.top()[1] > l)
                                l = a.top()[1];
                        a.pop();
                }
                while (!b.empty() && b.top()[0] <= r + 1) {
                        if (b.top()[1] > r)
                                r = b.top()[1];
                        b.pop();
                }
                if (l > r)
                        cout << "sa_win!" << endl;
                else if (l == r)
                        cout << "win_win!" << endl;
                else
                        cout << "ya_win!" << endl;
                cout << abs(l - r) << endl;
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
