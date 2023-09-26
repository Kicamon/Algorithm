#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i] = c[i - 1] * a[i];
    }
    vector<int> b(n);
    b[0] = m % c[1] / c[0];
    for (int i = 1; i < n; ++i) {
        b[i] = (m % c[i + 1] - m % c[i]) / c[i];
    }
    for (int i = 0; i < n; ++i)
        cout << b[i] << ' ';
    cout << endl;
    return 0;
}
