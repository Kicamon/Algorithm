#include <iostream>
using namespace std;
const int mod = 86400000;

#define ll long long

int main()
{
	ll n;
	cin >> n;
	n %= mod;
	n /= 1000;
	int h,m,s;
	s = n % 60;
	n /= 60;
	m = n % 60;
	n /= 60;
	h = n;
	if(h < 10)
		printf("0%d:",h);
	else
		printf("%d:",h);
	if(m < 10)
		printf("0%d:",m);
	else
		printf("%d:",m);
	if(s < 10)
		printf("0%d\n",s);
	else
		printf("%d\n",s);

	return 0;
}
