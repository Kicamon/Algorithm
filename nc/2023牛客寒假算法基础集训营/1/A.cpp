// #pragma GCC optimize(2)
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

	int n;
	cin >> n;
	while(n--)
	{
		int num[2]{0,0};
		char s[11];
		cin >> s;
		bool f = true;
		for(int i = 0;i < 10;++i)
		{
			if(s[i] == '1')
				num[i % 2]++;
			if(i & 1)
			{
				if(num[1] - num[0] > 10 - i >> 1 || num[0] - num[1] > 10 - i - 1 >> 1)
				{
					cout << i + 1 << endl;
					f = false;
					break;
				}
			}
			else 
			{
				if(num[0] - num[1] > 10 - i >> 1 || num[1] - num[0] > 10 - i - 1 >> 1)
				{
					cout << i + 1 << endl;
					f = false;
					break;
				}
			}
		}
		if(f)
			cout << -1 << endl;
	}

	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
