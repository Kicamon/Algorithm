//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define int long long

signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //clock_t start, finish;
        //start = clock();

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = a + d - b, y = b - c + a;
        if ((x + c) & 1 || (d + y) & 1)
                cout << "No Answer!" << endl;
        else
                cout << (x + c >> 1) << ' ' << (y + d >> 1) << endl;

        //finish = clock();
        //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

        return 0;
}
