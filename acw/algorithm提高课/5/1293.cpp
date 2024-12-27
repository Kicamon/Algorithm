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
	prime(n + 1);
	vector<int> ans(n + 2,1);
	int res = 1;
	for(int i : primes)
		for(int j = 2;i * j <= n + 1;++j)
			ans[i * j] = max(ans[i * j],ans[i] + 1),res = max(res,ans[i * j]);
	cout << res << endl;
	for(int i = 2; i <= n + 1;++i)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}
