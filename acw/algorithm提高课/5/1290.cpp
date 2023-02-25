#include <iostream>
using namespace std;
#define ll long long 
const int mod = 100003;

ll qmi(ll a,ll b,int p)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = res * a % p;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

int main()
{
	ll n,m;
	cin >> m >> n;
	cout <<(qmi(m,n,mod) - m * qmi(m - 1,n - 1,mod) % mod + mod) % mod << endl; 
	return 0;
}
