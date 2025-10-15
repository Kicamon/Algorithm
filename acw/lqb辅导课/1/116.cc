#include <iostream>
#include <array>
#include <vector>
#include <cstring>
using namespace std;

const int N = 20;

char s[5][5];

void change(int x, int y) {
        for (int i = 0; i < 4; ++i) {
                if (s[x][i] == '-')
                        s[x][i] = '+';
                else
                        s[x][i] = '-';
                if (s[i][y] == '-')
                        s[i][y] = '+';
                else
                        s[i][y] = '-';
        }
        if (s[x][y] == '-')
                s[x][y] = '+';
        else
                s[x][y] = '-';
}

bool check() {
        for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                        if (s[i][j] == '+')
                                return false;
        return true;
}

int get(int i, int j) {
        return i * 4 + j;
}

int main() {
        for (int i = 0; i < 4; ++i)
                cin >> s[i];
        vector<array<int, 2>> ans;
        for (int op = 0; op < 1 << 16; ++op) {
                char res[5][5];
                memcpy(res, s, sizeof(s));
                vector<array<int, 2>> cnt;
                for (int i = 0; i < 4; ++i)
                        for (int j = 0; j < 4; ++j)
                                if (op >> get(i, j) & 1) {
                                        change(i, j);
                                        cnt.push_back({ i, j });
                                }

                if (check())
                        ans = cnt;
                memcpy(s, res, sizeof(s));
        }
        cout << ans.size() << endl;
        for (auto x : ans)
                cout << x[0] + 1 << ' ' << x[1] + 1 << endl;
        return 0;
}
