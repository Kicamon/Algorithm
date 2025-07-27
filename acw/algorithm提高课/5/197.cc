#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;

void prime(int n)
{
	vector<bool> vis(n + 1,0);
	for(int i = 2;i <= n;++i)
	{
		if(!vis[i])
			primes.push_back(i);
		for(int j : primes)
		{
			if(i * j > n)
				break;
			vis[i * j] = true;
			if(i % j == 0)
				break;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	prime(n);

	for(int p : primes)
	{
		int num = 0;
		for(int i = n;i;i /= p)
			num += i / p;
		cout << p << ' ' << num << endl;
	}
	return 0;
}
