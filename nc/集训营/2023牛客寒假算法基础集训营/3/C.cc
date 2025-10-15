//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int n;
        cin >> n;

        auto output = [&](int x, int y) {
                int cnt = 2;
                for (int i = x; i <= y; ++i)
                        if (cnt > 0) {
                                cout << i + 2 << ' ';
                                cnt--;
                                if (cnt == 0)
                                        cnt = -2;
                        } else {
                                cout << i - 2 << ' ';
                                cnt++;
                                if (cnt == 0)
                                        cnt = 2;
                        }
        };

        if (n <= 3)
                cout << -1;
        else if (n % 4 == 0)
                output(1, n);
        else if (n % 4 == 1) {
                cout << "4 5 1 2 3 ";
                output(6, n);
        } else if (n % 4 == 2) {
                cout << "4 5 6 1 2 3 ";
                output(7, n);
        } else if (n % 4 == 3) {
                if (n == 7)
                        cout << -1;
                else {
                        cout << "4 5 6 1 2 3 ";
                        output(7, n - 5);
                        cout << n - 1 << ' ' << n << ' ' << n - 4 << ' ' << n - 3 << ' ' << n - 2;
                }
        }

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
