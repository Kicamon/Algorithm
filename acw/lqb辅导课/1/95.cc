#include <bits/stdc++.h>
#include <cstring>
#include <string.h>
using namespace std;

char s[6][6], res[6][6];
int mx[5] = { -1, 1, 0, 0, 0 }, my[5] = { 0, 0, 0, -1, 1 };

void change(int x, int y) {
        for (int i = 0; i < 5; ++i) {
                int X = x + mx[i], Y = y + my[i];
                if (X < 0 || X >= 5 || Y < 0 || Y >= 5)
                        continue;
                if (s[X][Y] == '0')
                        s[X][Y] = '1';
                else
                        s[X][Y] = '0';
        }
}

void solve() {
        for (int i = 0; i < 5; ++i)
                cin >> s[i];
        int ans = 10;
        for (int i = 0; i < (1 << 5); ++i) {
                int cnt = 0;
                memcpy(res, s, sizeof s);
                for (int j = 0; j < 5; ++j)
                        if (i >> j & 1)
                                change(0, j), cnt++;
                for (int j = 0; j < 4; ++j)
                        for (int k = 0; k < 5; ++k)
                                if (s[j][k] == '0') {
                                        change(j + 1, k);
                                        cnt++;
                                }

                bool f = true;
                for (int j = 0; j < 5; ++j)
                        if (s[4][j] == '0') {
                                f = false;
                                break;
                        }

                if (f)
                        ans = min(ans, cnt);
                memcpy(s, res, sizeof(s));
        }
        if (ans <= 6)
                cout << ans << endl;
        else
                cout << -1 << endl;
}

int main() {
        int t;
        cin >> t;
        while (t--)
                solve();
        return 0;
}
