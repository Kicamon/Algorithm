// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ll long long
#define vint vector<int>
#define pb push_back
const int N = 1e5;

long long num[N + 10];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    //clock_t start, finish;
    //start = clock();
    
	int n;
	cin >> n;
	int m = 0;
	for(int i = 0,c;i < n;++i)
	{
		cin >> c;
		num[c]++;
		m = max(m,c);
	}
	num[2] *= 2;
	num[3] = num[1] + num[3] * 3;
	for(int i = 4;i <= N;++i)
		num[i] = max(num[i - 3],num[i - 2]) + num[i] * i;

	cout << max(num[N],num[N - 1]) << endl;
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
