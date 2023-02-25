//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int x,y,c;
	for(int i = 1;i <= 5;++i)
		for(int j = 1;j <= 5;++j)
		{
			cin >> c;
			if(c)
				x = i,y = j;
		}
	cout << abs(3 - x) + abs(3 - y) << endl;

    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
