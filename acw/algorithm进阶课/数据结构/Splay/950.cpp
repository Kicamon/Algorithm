#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;

template <class T> struct Splay {
    struct Node {
        int s[2], p; // 存储子节点和父节点
        int v;       // 节点的编号
        int size;    // 子树的大小

        void init(int _v, int _p) {
            v = _v, p = _p;
            size = 1;
        }
    } tr[N];
    int root, idx; // 根节点和节点下标
    int size;      // 序列的大小
    int minm, delta;
    int L, R;
    int tot;

    void pushup(int u) {
        tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
    }

    void rotate(int x) // 旋转操作，两种旋转在一个函数中完成
    {
        int y = tr[x].p, z = tr[y].p; // 找出当前节点x的父节点y和y的父节点z
        int k = tr[y].s[1] == x; // k=1时，x为y的右儿子，k=0时，x为y的左儿子
        tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
        tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
        tr[x].s[k ^ 1] = y, tr[y].p = x;
        pushup(y), pushup(x);
    }

    void splay(int x, int k) // 将x转到k的下面，当k为0时，即将x转到根节点
    {
        while (tr[x].p != k) {
            int y = tr[x].p, z = tr[y].p;
            if (z != k) {
                if ((tr[y].s[1] == x) ^
                    (tr[z].s[1] == y)) // xyz呈折线关系，转两次x
                    rotate(x);
                else
                    rotate(y); // xyz呈直线关系，先转y在转x
            }
            rotate(x);
        }
        if (!k) // k为0时，x转到根节点，则更新根节点
            root = x;
    }

    int insert(int v) {
        int u = root, p = 0;
        while (u)
            p = u, u = tr[u].s[v > tr[u].v]; // 更新父节点，判断往左走还是往右走
        u = ++idx;                           // 给插入的点分配下标
        if (p)                               // 更新父节点的子节点
            tr[p].s[v > tr[p].v] = u;
        tr[u].init(v, p); // 初始化新建点的信息
        splay(u, 0);      // 将当前点旋转到根节点
        return u;
    }

    int get(int x) {
        int u = root, p = 0;
        while (u) {
            if (tr[u].v >= x)
                p = u, u = tr[u].s[0];
            else
                u = tr[u].s[1];
        }
        return p;
    }

    int get_k(int k) // 寻找中序遍历中的第k个数
    {
        int u = root;
        while (true) {
            if (tr[tr[u].s[0]].size >= k) // 在左子树
                u = tr[u].s[0];
            else if (tr[tr[u].s[0]].size + 1 == k) // 是当前节点
                return u;
            else // 在右子树
                k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
        }
        return -1;
    }

    void init(int n, int m) {
        size = n, minm = m;
        L = insert(-inf), R = insert(inf);
    }

    void opi(int k) {
        if (k >= minm)
            insert(k - delta);
    }

    void opa(int k) {
        delta += k;
    }

    void ops(int k) {
        delta -= k;
        R = get(minm - delta);
        splay(R, 0), splay(L, R);
        tr[L].s[1] = 0;
        pushup(L), pushup(R);
    }

    void opf(int k) {
        if (tr[root].size - 2 < k)
            cout << -1 << endl;
        else
            cout << get_k(tr[root].size - k) + delta << endl;
    }

    void op(char opc, int k) // 具体的操作，根据题目来写，可以多写几个
    {
        if (opc == 'I')
            opi(k), tot++;
        else if (opc == 'A')
            opa(k);
        else if (opc == 'S')
            ops(k);
        else
            opf(k);
    }
};

Splay<int> s;

int main() {
    int n, m;
    cin >> n >> m;
    s.init(n, m);
    while (n--) {
        char op;
        int k;
        cin >> op >> k;
        s.op(op, k);
    }

    cout << s.tot - s.tr[s.root].size + 2 << endl;

    return 0;
}
