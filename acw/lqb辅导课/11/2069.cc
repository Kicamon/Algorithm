#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4 + 10;

int n, m;

template <class T> struct DDS {
        int pa[N], num[N];
        int size;
        void init(int x) {
                size = x;
                for (int i = 1; i <= size; ++i)
                        pa[i] = i;
        }
        int find(int x) {
                if (pa[x] == x || pa[pa[x]] == pa[x])
                        return pa[x];
                int p = find(pa[x]);
                num[x] += num[pa[x]];
                pa[x] = p;
                return p;
        }
};

DDS<int> c;

int main() {
        cin >> n >> m;
        c.init(n);
        while (m--) {
                int op, a, b;
                cin >> op >> a >> b;
                if (op == 1) {
                        a = c.find(a), b = c.find(b);
                        if (a != b) {
                                c.num[a] -= c.num[b];
                                c.pa[a] = b;
                        }
                } else
                        c.num[c.find(a)] += b;
        }
        for (int i = 1; i <= n; ++i)
                if (i == c.find(i))
                        cout << c.num[i] << ' ';
                else
                        cout << c.num[i] + c.num[c.find(i)] << ' ';
        cout << endl;
        return 0;
}
