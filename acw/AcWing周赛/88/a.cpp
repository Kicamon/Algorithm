//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

bool check(int u)
{
	bool vis[10]{};
	while(u)
	{
		if(vis[u % 10])
			return false;
		vis[u % 10] = true;
		u /= 10;
	}
	return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int n;
	cin >> n;
	for(int i = n + 1;i < 20000;++i)
	{
		if(check(i))
		{
			cout << i << endl;
			break;
		}
	}
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
