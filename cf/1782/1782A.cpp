#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
	int w,d,h;
	cin >> w >> d >> h;
	int x,y,a,b;
	cin >> x >> y >> a >> b;
	cout << abs(a - x) + abs(b - y) + h + 2 * min({a,w - a,b,d - b,x,w - x,y,d - y}) << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
