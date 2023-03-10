# 代码模板整理

## 基本代码模板

```c++
/*
[[ ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷ ]],
[[ ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇ ]],
[[ ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽ ]],
[[ ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕ ]],
[[ ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕ ]],
[[ ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕ ]],
[[ ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄ ]],
[[ ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕ ]],
[[ ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿ ]],
[[ ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ]],
[[ ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟ ]],
[[ ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠ ]],
[[ ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙ ]],
[[ ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣ ]],
*/
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
#define Debug(x) cout << #x << ':' << x << endl
int input = 1;

void solve()
{

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // clock_t start, finish;
    // start = clock();

    int t = 1;
    if (input)
        cin >> t;
    while (t--)
        solve();

    // finish = clock();
    // cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

    return 0;
}
```



## 效率优化

### 快读

`cin优化`

```c++
ios::sync_with_stdio(false);
cin.tie(0);
```

`非负整数快读`

```c++
int read()
{
    int f = 1, k = 0;
    char c = getchar();
    // 非数字
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    // 数字
    while (c >= '0' && c <= '9')
    {
        k = k * 10 + c - '0';
        c = getchar();
    }
    return f * k;
}
```

`整数快读`

```c++
int read()
{
    int f = 1, k = 0;
    char c = getchar(); // 读入一个字符
    // 非数字
    while (c < '0' || c > '9')
    {                  // 读到空格后
        if (c == '-')  // 读到负数
            f = -1;    // 保留负号
        c = getchar(); // 两个功能：读取负号后面的数字或者读入空格等。
    }
    // 数字
    while (c >= '0' && c <= '9')
    {
        k = k * 10 + c - '0';
        c = getchar(); // 一位一位读入数字
    }
    return f * k;
}
```



### O2优化

```c++
#pragma GCC optimize(2)
```



### 代码时间

```c++
#include <time.h>

int main()
{
    clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    /*
	 你的代码
	
	*/
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;
}
```



## 基础算法

### 高精度

#### 高精度加法

```c++
vector<int> add(vector<int> a, vector<int> b)
{
    if (a.size() < b.size())
        return add(b, a);
    vector<int> c;

    int t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
        {
            t += a[i];
            if (i < b.size())
                t += b[i];
        }
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}
```



#### 高精度减法

```c++
vector<int> sub(vector<int> a, vector<int> b)
{
    vector<int>c;
    int t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        int now = a[i] - t;
        if (i < b.size()) now -= b[i];
        c.push_back((now + 10) % 10);
        if (now < 0) t = 1;
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
```



#### 高精度乘法

##### 一、高精度乘低精度

```c++
vector<int> mul(vector<int> a, int b)
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
            t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}
```

##### 二、高精度乘高精度

```c++
vector<int> mul(vector<int> a, vector<int> b)
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        int t = 0;
        vector<int> n;
        for (int j = 0; j < i; j++)
            n.push_back(0); // 列竖式中要往前移一位，这里通过在数的后边加0来实现，由于数是倒过来
        for (int j = 0; j < b.size() || t; j++) // 的，就在它的左边加0。
        {
            if (j < b.size())
                t += a[i] * b[j];
            n.push_back(t % 10);
            t /= 10;
        }
        ans = add(ans, n); // add为高精度加法
    }
    return ans;
}
```



#### 高精度除法

```c++
vector<int> div(vector<int> A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r = r % b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
```



### 二分

#### 大于等于的第一个数

```c++
int l = 0, r = len;
while (l < r)
{
    int mid = l + r >> 1;
    if (a[mid] < x)
        l = mid + 1;
    else
        r = mid;
}
```

#### 大于的第一个数

```c++
int l = 0, r = len;
while (l < r)
{
    int mid = l + r >> 1;
    if (a[mid] <= x)
        l = mid + 1;
    else
        r = mid;
}
```

#### 小于等于的第一个数

```c++
int l = 0, r = len;
while (l < r)
{
    int mid = l + r + 1 >> 1;
    if (a[mid] <= x)
        l = mid;
    else
        r = mid - 1;
}
```

#### 小于的第一个数

```c++
int l = 0, r = len;
while (l < r)
{
    int mid = l + r + 1 >> 1;
    if (a[mid] < x)
        l = mid;
    else
        r = mid - 1;
}
```



## 动态规划

### 线性DP

#### 最长公共子序列

`模板`

```c++
for(int i = 1;i <= n;++i)
{
    for(int j = 1;j <= n;++j)
    {
        f[i][j] = max(f[i - 1][j],f[i][j - 1]);
        if(a[i] == b[j])
            f[i][j] = f[i - 1][j - 1] + 1;
    }
}
```



#### 最长上升子序列

`模板1：朴素`

```c++
vector<int> f(n);
for(int i = 0;i < n;++i)
{
    cin >> a[i];
    f[i] = 1;
    for(int j = 0;j < i;++j)
        if(a[j] < a[i])
            f[i] = max(f[i],f[j] + 1);
}
```

`模板2：优化`

```c++
vector<int> f(n + 1,0);
int len = 0;
for(int i = 0;i < n;++i)
{
    cin >> a[i];
    int l = 0,r = len;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(f[mid] < a[i])
            l = mid;
        else
            r = mid - 1;
    }
    f[r + 1] = a[i];
    len = max(r + 1,len);
}
```



#### 最长公共上升子序列

`模板1：朴素`

```c++
for(int i = 1;i <= n;++i)
{
    for(int j = 1;j <= n;++j)
    {
        f[i][j] = f[i - 1][j];
        if(a[i] == b[j])
        {
            int maxl = 1;
            for(int k = 1;k < j;++k)
            {
                if(a[i] > b[k])
                    maxl = max(maxl,f[i - 1][k] + 1);
            }
            f[i][j] = max(maxl,f[i][j]);
        }
    }
}
```

`模板2：优化`

```c++
for(int i = 1;i <= n;++i)
{
    int maxl = 1;
    for(int j = 1;j <= n;++j)
    {
        f[i][j] = f[i - 1][j];
        if(a[i] == b[j])
            f[i][j] = max(f[i][j],maxl);
        if(b[j] < a[i])
            maxl = max(maxl,f[i - 1][j] + 1);
    }
}
```



### 背包

#### 01背包

`模板1：朴素`

```c++
for(int i = 1;i <= n;++i)
    for(int j = 1;j <= m;++j)
    {
        f[i][j] = f[i - 1][j];
        if(j >= s[i])
	        f[i][j] = max(f[i - 1][j],f[i - 1][j - s[i]] + v[i]);
    }
```

`模板2：优化`

```c++
for(int i = 0;i < n;++i)
    for(int j = m;j >= s[i];--j)
        f[j] = max(f[j],f[j - s[i]] + v[i]);
```



#### 完全背包

`模板`

```c++
for(int i = 0;i < n;i++)
    for(int j = v[i];j <= m;j++)
        dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
```



#### 多重背包

`模板1：朴素`

```c++
for(int i = 0;i < n;i++)
{
    scnaf("%d%d%d",&v,&w,&s);//输入体积价值和数量
    for(int j = m;j >= v;j--)
        for(int p = 1;p <= s && j >= p * v;p++)
            f[j] = max(f[j],f[j - p * v] + p * w);
}
```

`模板2：优化`

```c++
vector<<array<int,2>>good;

void dp()
{
    for(int i = 0;i < n;i++)
    {
        int v,w,s;
        cin >> v >> w >> s;
        
        for(int j = 1;j <= s;s -= j,j *= 2)
            good.push_back({j * v,j * w});
        if(s)good.push_back({s * v,s * w});
    }
    
    for(auto g : good)
    {
        for(int i = m;i >= g.v;i--)
            f[i] = max(f[i],f[i - g[0]] + g[1]);
    }
}
```



#### 分组背包

```c++
for(int i = 0;i < n;i++)
{
    int s;
    cin >> s;
    for(int j = 0;j < s;j++)cin >> v[j] >> w[j];
    
    for(int j = m;j > 0;j--)
        for(int p = 0;p < s;p++)
            f[j] = max(f[j],f[j- v[p]] + w[p]);
}
```



## 数据结构

### 并查集

#### 基本模板

```c++
template <class T> struct DDS
{
    int pa[N], num[N];
    int size;
    void init(int x)
    {
        size = x;
        for (int i = 1; i <= size; ++i)
            pa[i] = i;
    }
    int find(int x)
    {
        if (pa[x] != x)
            pa[x] = find(pa[x]);
        return pa[x];
    }
};
```



#### 路径和模板

```c++
template <class T> struct DDS
{
    int pa[N], num[N];
    int size;
    void init(int x)
    {
        size = x;
        for (int i = 1; i <= size; ++i)
            pa[i] = i;
    }
    int find(int x)
    {
        if (pa[x] == x || pa[pa[x]] == pa[x])
            return pa[x];
        int p = find(pa[x]);
        num[x] += num[pa[x]];
        pa[x] = p;
        return p;
    }
};
```



### 树状数组

#### 基本模板

```c++
template <class T> struct BIT
{
    int size;
    vector<T> c;
    BIT(int n) : c(n + 1)
    {
        size = n;
    };
    void resize(int x)
    {
        size = x;
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void modify(int x, T d = 1)
    {
        assert(x != 0);
        for (int i = x; i <= size; i += lowbit(i))
            c[i] = c[i] + d;
    }

    T query(int x)
    {
        assert(x <= size);
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            res = res + c[i];
        return res;
    }
};
```



#### 树状数组二分

```c++
template <class T> struct BIT
{
    int size,blen = 0;
    T c[N];
    void resize(int x)
    {
        size = x;
        while(x)
        {
        	x >>= 1;
        	blen++;
        }
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void modify(int x, T d)
    {
        assert(x != 0);
        for (int i = x; i <= size; i += lowbit(i))
            c[i] = c[i] + d;
    }

	int query(T x)
    {
        int res = 0;
        for (int i = blen; ~i; --i)
            if (res + (1 << i) <= size && c[res + (1 << i)] <= x)
            {
                res += (1 << i);
                x -= c[res];
            }
        return res;
    }
};
```



### 线段树

#### 基本模板

```c++
// 线段树的信息
const int N = 2e5 + 10, mod = 1e9 + 7;
int a[N];
struct info // 存储线段树的值
{
    int size;
    int num;
};

struct tag // 存储线段树的懒标记
{
    int add;
    int mul;
};

struct Node // 线段树
{
    info val;
    tag lazy;
} tr[N << 2];
int st_size; // 线段树的总区间大小

// 线段树的具体操作
info operator+(const info &l, const info &r) // pushup的操作
{
    info c;
    c.size = l.size + r.size;
    c.num = (1ll * l.num + r.num) % mod;
    return c;
}

info operator+(const info &v, const tag &t) // pushdown时，对子节点info的操作
{
    info c;
    c.size = v.size;
    c.num = (1ll * v.num * t.mul + 1ll * v.size * t.add) % mod;
    return c;
}

tag operator+(const tag &ts, const tag &tp) // pushdown时，对子节点tag的操作
{
    tag c;
    c.add = (1ll * ts.add * tp.mul + tp.add) % mod;
    c.mul = 1ll * ts.mul * tp.mul % mod;
    return c;
}

void pushup(int u)
{
    tr[u].val = tr[u << 1].val + tr[u << 1 | 1].val;
}

void pushdown(int u)
{
    Node &t = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
    l.val = l.val + t.lazy, l.lazy = l.lazy + t.lazy;
    r.val = r.val + t.lazy, r.lazy = r.lazy + t.lazy;
    t.lazy = {0, 1};
}

void build(int u = 1, int l = 1, int r = st_size)
{
    if (l == r)
    {
        tr[u] = {r - l + 1, a[l], 0, 1};
        return;
    }
    tr[u] = {r - l + 1, 0, 0, 1};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, tag c, int pl = 1, int pr = st_size)
{
    if (l <= pl && pr <= r)
    {
        tr[u].val = tr[u].val + c;
        tr[u].lazy = tr[u].lazy + c;
        return;
    }
    pushdown(u);
    int mid = pl + pr >> 1;
    if (l <= mid)
        modify(u << 1, l, r, c, pl, mid);
    if (r > mid)
        modify(u << 1 | 1, l, r, c, mid + 1, pr);
    pushup(u);
}

int query(int u, int l, int r, int pl = 1, int pr = st_size)
{
    if (l <= pl && pr <= r)
        return tr[u].val.num;
    int mid = pl + pr >> 1;
    pushdown(u);
    int res = 0;
    if (l <= mid)
        res = (1ll * res + query(u << 1, l, r, pl, mid)) % mod;
    if (r > mid)
        res = (1ll * res + query(u << 1 | 1, l, r, mid + 1, pr)) % mod;
    return res;
}
```



### Splay

#### 基本模板

```c++
template <class T> struct Splay
{
    struct Node
    {
        int s[2], p; // 存储子节点和父节点
        int v;       // 节点的编号
        int size;    // 子树的大小
        bool flag;   // 懒标记

        void init(int _v, int _p)
        {
            v = _v, p = _p;
            size = 1;
        }
    } tr[N];
    int root, idx; // 根节点和节点下标
    int size;      // 序列的大小

    void pushup(int u)
    {
        tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
    }

    void pushdown(int u)
    {
        if (tr[u].flag)
        {
            // 执行操作
            swap(tr[u].s[0], tr[u].s[1]);
            // 对懒标记的操作
            tr[tr[u].s[0]].flag ^= 1;
            tr[tr[u].s[1]].flag ^= 1;
            tr[u].flag = 0;
        }
    }

    void rotate(int x) // 旋转操作，两种旋转在一个函数中完成
    {
        int y = tr[x].p, z = tr[y].p; // 找出当前节点x的父节点y和y的父节点z
        int k = tr[y].s[1] == x;      // k=1时，x为y的右儿子，k=0时，x为y的左儿子
        tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
        tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
        tr[x].s[k ^ 1] = y, tr[y].p = x;
        pushup(y), pushup(x);
    }

    void splay(int x, int k) // 将x转到k的下面，当k为0时，即将x转到根节点
    {
        while (tr[x].p != k)
        {
            int y = tr[x].p, z = tr[y].p;
            if (z != k)
                if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y)) // xyz呈折线关系，转两次x
                    rotate(x);
                else
                    rotate(y); // xyz呈直线关系，先转y在转x
            rotate(x);
        }
        if (!k) // k为0时，x转到根节点，则更新根节点
            root = x;
    }

    void insert(int v)
    {
        int u = root, p = 0;
        while (u)
            p = u, u = tr[u].s[v > tr[u].v]; // 更新父节点，判断往左走还是往右走
        u = ++idx;                           // 给插入的点分配下标
        if (p)                               // 更新父节点的子节点
            tr[p].s[v > tr[p].v] = u;
        tr[u].init(v, p); // 初始化新建点的信息
        splay(u, 0);      // 将当前点旋转到根节点
    }

    int get_k(int k) // 寻找中序遍历中的第k个数
    {
        int u = root;
        while (true)
        {
            pushdown(u);
            if (tr[tr[u].s[0]].size >= k) // 在左子树
                u = tr[u].s[0];
            else if (tr[tr[u].s[0]].size + 1 == k) // 是当前节点
                return u;
            else // 在右子树
                k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
        }
        return -1;
    }

    void output(int u) // 输出该splay
    {
        pushdown(u);    // 先pushdown
        if (tr[u].s[0]) // 如果存在左儿子就往左递归
            output(tr[u].s[0]);
        if (tr[u].v >= 1 && tr[u].v <= size) // 如果当前节点不是哨兵，就直接输出
            cout << tr[u].v << ' ';
        if (tr[u].s[1]) // 如果存在右儿子就往右递归
            output(tr[u].s[1]);
    }

    void init(int n)
    {
        size = n;
        for (int i = 0; i <= size + 1; ++i) // 插入0和size + 1两个哨兵
            insert(i);
    }

    // 具体的操作，根据实际情况改写
    void op(int l, int r)
    {
        l = get_k(l), r = get_k(r + 2);
        splay(l, 0), splay(r, l);
        tr[tr[r].s[0]].flag ^= 1;
    }
};
```



## 图论

### 拓扑排序

```c++
struct Topsort
{
    int n, m;
    int e[N], ne[N], h[N], idx;
    int into[N];
    int q[N];

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool topsort()
    {
        int hh = 0, tt = 0;
        for (int i = 1; i <= n; ++i)
            if (!into[i])
                q[tt++] = i;
        while (hh < tt)
        {
            int t = q[hh++];
            for (int i = h[t]; ~i; i = ne[i])
            {
                int j = e[i];
                into[j]--;
                if (!into[j])
                    q[tt++] = j;
            }
        }
        if (tt == n)
            return true;
        return false;
    }

    void init(int a, int b)
    {
        memset(h, -1, sizeof h);
        n = a, m = b;
        while (m--)
        {
            cin >> a >> b;
            add(a, b);
            into[b]++;
        }
        bool f = topsort();
    }
};
```



### Dijkstra

```c++
int e[M], ne[M], w[M], h[N], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[N];
bool vis[N];

int dijkstra(int start, int end)
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, start});
    while (!q.empty())
    {
        array<int, 2> t = q.top();
        q.pop();

        if (vis[t[1]])
            continue;
        vis[t[1]] = true;

        for (int i = h[t[1]]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t[1]] + w[i])
            {
                dist[j] = dist[t[1]] + w[i];
                q.push({dist[j], j});
            }
        }
    }

    if (dist[end] == 0x3f3f3f3f)
        return -1;
    return dist[end];
}
```



### SPFA

```c++
int e[M], ne[M], w[M], h[N], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool vis[N];
int dist[N];
int spfa(int start, int end)
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }

    return dist[end];
}
```



#### SPFA求负权回路

```c++
int e[M], ne[M], w[M], h[N], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool vis[N];
int dist[N], cnt[N];
bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
        vis[i] = true;
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }

    return false;
}
```



### Floyd

```c++
struct Floyd
{
    const int inf = 0x3f3f3f3f;
    int g[N][N];
    int size;
    Floyd(int n)
    {
        size = n;
        for (int i = 1; i <= size; ++i)
            for (int j = 1; j <= size; ++j)
                if (i == j)
                    g[i][j] = 0;
                else
                    g[i][j] = inf;
    }

    void change(int a, int b, int c)
    {
        g[a][b] = min(g[a][b], c);
    }

    void floyd()
    {
        for (int k = 1; k <= size; ++k)
            for (int i = 1; i <= size; ++i)
                for (int j = 1; j <= size; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
};
```



### Kruskal

```c++
struct Kruskal
{
    struct node
    {
        int a, b, c;
        bool operator<(const node &v)
        {
            return c < v.c;
        }
    };
    vector<int> p;
    vector<node> s;
    int size_n, size_m;

    Kruskal(int n, int m) : p(n + 1), s(m)
    {
        size_n = n, size_m = m;
        for (int i = 1; i <= n; ++i)
            p[i] = i;
    };
    int find(int x)
    {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    void Kruskal_int()
    {
        int a, b, c;
        for (int i = 0; i < size_m; ++i)
        {
            cin >> a >> b >> c;
            s[i] = {a, b, c};
        }
    }

    void Kruskal_get()
    {
        sort(all(s));
        int res = 0, cnt = 0;
        for (int i = 0; i < size_m; ++i)
        {
            int a = s[i].a, b = s[i].b, c = s[i].c;

            a = find(a), b = find(b);
            if (a != b)
            {
                p[a] = b;
                res += c;
                cnt++;
            }
        }
        if (cnt < size_n - 1)
            cout << "impossible" << endl;
        else
            cout << res << endl;
    }
};
```



### 二分图

#### 染色法

```c++
int color[N];
int e[M],ne[M],h[N],idx;

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool dfs(int u,int c)
{
	color[u] = c;
	for(int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		if(!color[j])
		{
		    if(!dfs(j,3 - c))
		        return 0;
		}
		else if(color[j] == c) 
			return false;
	}
	return true;
}
```



#### 匈牙利算法

```c++
int e[M],ne[M],h[N],idx;

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int metch[N];
bool vis[N];

bool Hungarian(int u)
{
	for(int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		if(!vis[j])
		{
			vis[j] = true;
			if(!metch[j] || Hungarian(metch[j]))
			{
				metch[j] = u;
				return true;
			}
		}
	}
	return false;
}
```





## 数学

### 质数

#### 埃式筛

```c++
void Prime(int n)
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            for (int j = i + i; j <= n; j += i)
                vis[j] = 1;
        }
    }
}
```



#### 欧拉筛

```c++
void prime(int n)
{
    vector<bool> vis(n + 1, 0);
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            primes.push_back(i);
        for (int j = 0; primes[j] * i <= n; j++)
        {
            vis[primes[j] * i] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}
```



#### 二次筛法

```c++
template <class T> struct Prime2
{
    int primes[50010], _primes[N];
    int cnt, _cnt;
    bool vis[N];

    void prime(int n)
    {
        for (int i = 2; i <= n; ++i)
        {
            if (!vis[i])
                primes[cnt++] = i;
            for (int j = 0; primes[j] * i <= n; ++j)
            {
                vis[(ll)i * primes[j]] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }

    Prime2()
    {
        prime(50000);
    }

    void init(int l, int r) // 筛取l~r范围内的质数
    {
        memset(vis, 0, sizeof vis);
        memcpy(_primes, primes, sizeof primes);
        _cnt = cnt;
        for (int i = 0; i < _cnt; ++i)
        {
            ll p = _primes[i];
            for (ll j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p)
                vis[j - l] = true;
        }

        _cnt = 0;
        for (int i = 0; i <= r - l; ++i)
        {
            if (!vis[i] && i + l >= 2)
                _primes[_cnt++] = i + l;
        }
    }
};
```



### 约数

#### 试除法求约数

```c++
for (int i = 1; i * i <= n; ++i)
    if (n % i == 0)
    {
        num.push_back(i);
        if(n / i != i)
            num.push_back(num / i);
    }
```



#### 约数个数

```c++
map<int, int> primes;
cin >> num;
for (int i = 2; i * i <= num; ++i)
{
    while (num % i == 0)
    {
        num /= i;
        primes[i]++;
    }
}
if (num > 1)
    primes[num]++;

ll res = 1;
for (auto p : primes)
    res = res * (p.se + 1) % mod;
```



#### 约数之和

```c++
map<int, int> primes;
cin >> num;
for (int i = 2; i * i <= num; ++i)
{
    while (num % i == 0)
    {
        num /= i;
        primes[i]++;
    }
}
if (num > 1)
    primes[num]++;

ll res = 1;
for (auto p : primes)
{
    ll t = 1;
    int a = p.first, b = p.second;
    while (b--)
        t = (t * a + 1) % mod;
    res = res * t % mod;
}
```



#### 最大公约数

```c++
template <typename T> T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}
```



### 欧拉函数

#### 欧拉函数

```c++
int get_uler(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}
```



#### 筛法求欧拉函数

```c++
template <class T> struct Get_uler
{
    vector<int> primes;
    int phi[N];
    bool vis[N];

    void get_uler(int n)
    {
        phi[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (!vis[i])
            {
                phi[i] = i - 1;
                primes.push_back(i);
            }
            for (int j = 0; primes[j] * i <= n; ++j)
            {
                int t = primes[j] * i;
                vis[t] = true;
                if (i % primes[j] == 0)
                {
                    phi[t] = primes[j] * phi[i];
                    break;
                }
                phi[t] = phi[i] * (primes[j] - 1);
            }
        }
    }
};
```



### 快速幂

#### 普通快速幂

```c++
template <typename T> T qmi(long long a, long long b, T p)
{
    T res = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            res = (long long)res * a % p;
        b >>= 1;
        a = (long long)a * a % p;
    }
    return res;
}
```



#### 大指数快速幂

```c++
template <class T> struct BIG_QMI
{
    T qmi(long long a, long long b, T p)
    {
        T res = 1;
        a %= p;
        while (b)
        {
            if (b & 1)
                res = (long long)res * a % p;
            b >>= 1;
            a = (long long)a * a % p;
        }
        return res;
    }

    void get_pow(int a, string b, int p)
    {
        T ans = 1;
        for (int i = (int)b.size() - 1; ~i; --i)
        {
            ans = ans * qmi(a, b[i] - '0', p) % p;
            a = qmi(a, 10, p);
        }
        cout << ans << endl;
    }
};
```



#### 快速幂求逆元

```c++
qmi (a, b - 2, p);
```



### 拓展欧几里得算法

#### 拓展欧几里得算法

```c++
template <typename T> T exgcd(T a, T b, T &x, T &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    T d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```



### 中国剩余定理

#### 中国剩余定理

```c++
template <class T = long long> struct CRT
{
    T exgcd(T a, T b, T &x, T &y)
    {
        if (!b)
        {
            x = 1, y = 0;
            return a;
        }

        T d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }

    long long crt(int n, long long *a, long long *m)
    {
        bool flag = true;
        for (int i = 1; i < n; ++i)
        {
            long long k1, k2;
            long long d = exgcd(a[i - 1], a[i], k1, k2);
            if ((m[i] - m[i - 1]) % d)
            {
                flag = false;
                break;
            }
            k1 *= (m[i] - m[i - 1]) / d;
            long long t = a[i] / d;
            k1 = (k1 % t + t) % t;
            m[i] = a[i - 1] * k1 + m[i - 1];
            a[i] = abs(a[i - 1] / d * a[i]);
        }
        if (flag)
            return (m[n - 1] % a[n - 1] + a[n - 1]) % a[n - 1];
        else
            return -1LL;
    }
};
```



### 高斯消元

#### 高斯消元解线性方程

```c++
template <class T = int> struct Gauzz
{
    const double eps = 1e-6;
    double a[N][N];
    int size;
    void resize(int n)
    {
        size = n;
    }
    T gauzz()
    {
        int c, r;
        for (c = 0, r = 0; c < size; c++)
        {
            int t = r;
            for (int i = r; i < size; i++)
                if (fabs(a[i][c]) > fabs(a[t][c]))
                    t = i;
            if (fabs(a[t][c]) < eps)
                continue;

            for (int i = c; i <= size; i++)
                swap(a[t][i], a[r][i]);
            for (int i = size; i >= c; --i)
                a[r][i] /= a[r][c];
            for (int i = r + 1; i < size; i++)
                if (fabs(a[i][c]) > eps)
                    for (int j = size; j >= c; --j)
                        a[i][j] -= a[r][j] * a[i][c];
            r++;
        }
        if (r < size)
        {
            for (int i = r; i < size; i++)
                if (fabs(a[i][size]) > eps)
                    return 2;
            return 1;
        }

        for (int i = size - 1; ~i; --i)
            for (int j = i + 1; j < size; j++)
                a[i][size] -= a[i][j] * a[j][size];

        return 0;
    }

    void get_answer()
    {
        T t = gauzz();
        if (!t)
        {
            for (int i = 0; i < size; ++i)
                if (fabs(a[i][size]) < eps)
                    printf("0.00\n");
                else
                    printf("%.2f\n", a[i][size]);
        }
        else if (t == 1)
            printf("Infinite group solutions\n");
        else
            printf("No solution\n");
    }
};
```



### 组合数

#### 常用

```c++
template <typename T> T C(T a, T b)
{
    T res = 1;
    for (T i = a, j = 1; j <= b; --i, ++j)
        res = res * i / j;
    return res;
}
```



#### int范围内数字较小时

$\C_{M}^{N} $ = $\C_{M - 1}^{N}$ + $\C_{M - 1}^{N-1}$

```c++
void init(int n)
{
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= i;j++)
            if(!f[i][j])
                f[i][j] = 1;
    		else 
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}
```



#### int范围内数字较大时

```c++
template <class T> struct C
{
    T qmi(T a, T b, T p)
    {
        T res = 1;
        while (b)
        {
            if (b & 1)
                res = (ll)res * a % p;
            b >>= 1;
            a = (ll)a * a % p;
        }
        return res;
    }

    T fct[N], infct[N];

    void init()
    {
        fct[0] = infct[0] = 1;
        for (int i = 1; i < N; ++i)
        {
            fct[i] = (ll)fct[i - 1] * i % mod;
            infct[i] = (ll)infct[i - 1] * qmi(i, mod - 2, mod) % mod;
        }
    }

    void get(T a, T b) // a为底
    {
        printf("%d\n", (ll)fct[a] * infct[b] % mod * infct[a - b] % mod);
    }
};
```



#### long long范围内

```c++
template <class T> struct Lucass
{
    T qmi(T a, T b, T p)
    {
        T res = 1;
        while (b)
        {
            if (b & 1)
                res = (ll)res * a % p;
            b >>= 1;
            a = (ll)a * a % p;
        }
        return res;
    }

    int C(int a, int b, int p)
    {
        if (b > a)
            return 0;
        int ans = 1;
        for (int i = 1, j = a; i <= b; ++i, --j)
        {
            ans = (ll)ans * j % p;
            ans = (ll)ans * qmi(i, p - 2, p) % p;
        }
        return ans;
    }

    int lucass(ll a, ll b, int p)
    {
        if (a < p && b < p)
            return C(a, b, p);
        return (ll)C(a % p, b % p, p) * lucass(a / p, b / p, p) % p;
    }
};
```



#### 高精度组合数

```c++
template <class T> struct C
{
    vector<int> primes;
    int num[N];

    void prime(int n)
    {
        vector<bool> vis(n + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            if (!vis[i])
                primes.push_back(i);
            for (int j : primes)
            {
                if (j * i > n)
                    break;
                vis[j * i] = true;
                if (i % j == 0)
                    break;
            }
        }
    }

    int get(T num, int p)
    {
        int res = 0;
        while (num)
        {
            res += num / p;
            num /= p;
        }
        return res;
    }

    vector<int> mul(vector<int> a, int b)
    {
        vector<int> ans;
        int t = 0;
        for (int i = 0; i < a.size() || t; i++)
        {
            if (i < a.size())
                t += a[i] * b;
            ans.push_back(t % 10);
            t /= 10;
        }
        return ans;
    }

    void get_answer(T a, T b)
    {
        prime(a);
        for (int i = 0; i < primes.size(); ++i)
        {
            int p = primes[i];
            num[i] = get(a, p) - get(b, p) - get(a - b, p);
        }

        vector<int> ans;
        ans.push_back(1);

        for (int i = 0; i < (int)primes.size(); ++i)
            for (int j = 0; j < num[i]; ++j)
                ans = mul(ans, primes[i]);

        for (int i = (int)ans.size() - 1; ~i; --i)
            cout << ans[i];
        cout << endl;
    }
};
```



#### 卡特兰数

> 卡特兰数的定义：$\C_{2n}^{n} - C_{2n}^{n-1} = \frac{C_{2n}^{n}}{n+1}$



### 容斥原理

#### 容斥原理

例题：[能被整除的数](https://www.acwing.com/problem/content/892/)

```c++
#include<iostream>
using namespace std;
typedef long long ll;

int n,m;
int p[20];

int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++)cin >> p[i];
    
    int ans = 0;
    for(int i = 1;i < 1 << m;i++)
    {
        int t = 1,s = 0;
        for(int j = 0;j < m;j++)
        {
            if(i >> j & 1)
            {
                if((ll)t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                t *= p[j];
                s++;
            }
        }
        if(t != -1)
        {
            if(s % 2)ans += n / t;
            else ans -= n / t;
        }
    }
    
    cout << ans << endl;
    return 0;
}
```
