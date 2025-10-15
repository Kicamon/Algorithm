#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;

int main() {
        int n;
        cin >> n;
        long long res = 0, cnt;
        cin >> cnt;
        for (int i = 1, c; i < n; ++i) {
                cin >> c;
                res += cnt * c;
                cnt += c;
        }
        cout << res << endl;
        return 0;
}
