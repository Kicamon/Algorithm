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
	vector<int> num(3,0);
	for(int i = 0,c;i < n;++i)
	{
		cin >> c;
		num[i % 3] += c;
	}
	int idx = 0;
	for(int i = 1;i < 3;++i)
		if(num[idx] < num[i])
			idx = i;
	if(idx == 0)
		puts("chest");
	else if(idx == 1)
		puts("biceps");
	else
		puts("back");

	//finish = clock();
	//cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;

	return 0;
}
