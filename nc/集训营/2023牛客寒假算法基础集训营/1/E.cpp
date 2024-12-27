// 未解决
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back

void solve()
{
	int xa,ya,xb,yb,xc,yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	double xd,yd,xe,ye,xf,yf;
	cin >> xd >> yd >> xe >> ye >> xf >> yf;
	double a = abs(xa - xb) * abs(ya - yb),b = abs(xb - xc) * abs(yb - yc);
	double c = abs(xd - xe) * abs(yd - ye),d = abs(xe - xf) * abs(ye - yf);
	bool f = false;
	if(a == c)
	{
		int num[2]{};
		num[0] += xc > xa,num[0] += xc > xb,num[0] += yc > ya,num[0] += yc > yb;
		num[1] += xf > xd,num[1] += xf > xe,num[1] += yf > yd,num[1] += yf > ye;
		if(num[0] == num[1])
			f |= true;
	}
	if(a == d)
	{
		int num[2]{};
		num[0] += xc > xa,num[0] += xc > xb,num[0] += yc > ya,num[0] += yc > yb;
		num[1] += xd > xe,num[1] += xd > xf,num[1] += yd > ye,num[1] += yd > yf;
		if(num[0] == num[1])
			f |= true;
	}
cout << (f ? "NO" : "YES") << endl;
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
