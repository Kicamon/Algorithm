#include <iostream>
#include <math.h>
using namespace std;
const int N = 2e5;

int num[N + 10];

int main() {
        int n, m, k;
        cin >> n >> m >> k;
        int res = 0;
        for (int i = 0, a, b; i < n; ++i) {
                cin >> a >> b;
                res = max(a, res);
                num[max(1, a - b + 1)]++, num[a + 1]--;
        }
        for (int i = 1; i <= N; ++i)
                num[i] += num[i - 1];
        while (m--) {
                int q;
                cin >> q;
                if (q + k <= N)
                        cout << num[q + k] << endl;
                else
                        cout << 0 << endl;
                ;
        }

        return 0;
}
