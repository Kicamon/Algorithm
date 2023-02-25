// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 1e9;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int a,b;
	cin >> a >> b;
	if(a != 1 && b >= 31)
		cout << -1 << endl;
	else if(a == 1)
		cout << 1 << endl;
	else
	{
		ll k = a;
		for(int i = 1;i < b;++i)
		{
			k *= a;
			if(k > N)
			{
				cout << -1 << endl;
				return 0;
			}
		}
		cout << k << endl;
	}
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
