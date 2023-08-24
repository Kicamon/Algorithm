nclude <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	int res = 0;
	for(int i = 0; i < n;++i)
		cin >> a[i],res += a[i];
	vector<bool> f(res + 1,0);
	f[0]= true;
	int ans = 0x3f3f3f3f;
	for(int i = 0;i < n;++i)
		for(int j = res;~j;--j)
			if(f[j])
			{
				f[j + a[i]] = true;
				if(j + a[i] >= x)
					ans = min(ans,j + a[i]);
			}
	cout << ans << endl;
	return 0;
}
