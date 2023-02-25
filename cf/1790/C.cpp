//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

const int N = 110;

int e[N * N],ne[N * N],h[N * N],idx;
int root;
int num[N];

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void output()
{
	queue<int> q;
	q.push(root);
	while(q.size())
	{
		int t = q.front();
		cout << t << ' ';
		q.pop();
		for(int i = h[t];~i;i = ne[i])
		{
			int j = e[i];
			if(num[j] == 1)
				q.push(j);
			else 
				num[j]--;
		}
	}
}

void solve()
{
	memset(h,-1,sizeof h);
	memset(num,0,sizeof num);
	idx = 0;
	int n;
	cin >> n;
	for(int i = 0,c;i < n;++i)
	{
		cin >> c;
		if(num[c] == 0)
			root = c;
		for(int j = 2,k;j < n;++j)
		{
			cin >> k;
			add(c,k);
			num[k]++;
			c = k;
		}
	}
	output();
	cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int t;
	cin >> t;
	while(t--)
		solve();
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
