#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	while(n)
	{
		cout << n << ' ';
		n >>= 1;
	}
	cout << endl;
	return 0;
}
