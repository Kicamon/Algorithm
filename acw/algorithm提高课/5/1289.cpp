#include <iostream>
using namespace std;
#define ll long long
const int mod = 200907;

int qmi(int a,int b,int p)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll)res * a % p;
		b >>= 1;
		a = (ll) a * a % p;
	}
	return res;
}

void solve()
{
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	if(b - a == c - b)
	{
		int t = b - a;
		cout << ((ll)a + (ll)t * (k - 1) % mod) % mod << endl; 
	}
	else 
	{
		int t = b / a;
		cout << (ll)a * qmi(t,k - 1,mod) % mod << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
