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
//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 2e5 + 10;
int input = 1;
#define int long long

int a[N];

struct node
{
	int lazy;
} tr[N << 2];

template <class T> struct ST
{
    void pushdown(int u)
    { 
		node &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
		l.lazy += root.lazy,r.lazy += root.lazy;
		root.lazy = 0;
    }

    void build(int u, int l, int r)
    {
        if (l == r)
        {
            tr[u] = {0};
            return;
        }
        tr[u] = {0};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int l, int r, int pl, int pr)
    {
        if (l <= pl && pr <= r)
        {
			tr[u].lazy++;		
            return;
        }
        pushdown(u);
        int mid = pl + pr >> 1;
        if (l <= mid)
            modify(u << 1, l, r, pl, mid);
        if (r > mid)
            modify(u << 1 | 1, l, r, mid + 1, pr);
    }

	T query(int u,int x,int l,int r)
	{
		if(l == r)
		{
			int t = tr[u].lazy;
			tr[u].lazy = 0;
			return t;
		}
		pushdown(u);
		int mid = l + r >> 1;
		if(x <= mid)
			return query(u << 1, x, l, mid);
		else return query(u << 1 | 1,x,mid + 1,r);
	}
};

int change(int x)
{
	int res = 0;
	while(x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

void solve()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	ST<int> s;
	s.build(1, 1, n);
	while(m--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int l,r;
			cin >> l >> r;
			s.modify(1, l, r, 1, n);
		}
		else 
		{
			int x;
			cin >> x;
			int t = s.query(1,x,1,n);
			for(int i = 0;i < t;++i)
			{
				if(a[x] < 10)
					break;
				a[x] = change(a[x]);
			}
			cout << a[x] << endl;
		}
	}
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int t = 1;
	if(input)
		cin >> t;
	while(t--)
		solve();
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
