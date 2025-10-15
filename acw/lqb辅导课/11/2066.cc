#include <bits/stdc++.h>
using namespace std;

int main() {
        string s;
        cin >> s;
        for (int i = 0; i < (int)s.size(); ++i) {
                if ('0' <= s[i] && s[i] <= '9') {
                        int t = s[i] - '1';
                        while (t--)
                                cout << s[i - 1];
                } else
                        cout << s[i];
        }
        cout << endl;
        return 0;
}
