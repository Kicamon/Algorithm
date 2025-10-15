#include <bits/stdc++.h>
using namespace std;

int f[50];

int main() {
        f[1] = f[2] = 1;
        int n;
        cin >> n;
        for (int i = 3; i < n; ++i)
                f[i] = f[i - 1] + f[i - 2];
        for (int i = 0; i < n; ++i)
                cout << f[i] << ' ';
        cout << endl;
        return 0;
}
