#include <bits/stdc++.h>
using namespace std;

string a,b;

int main()
{
	cin >> a >> b;
	int res = 0;
	auto change = [&](int i){
		if(a[i] == 'o')
			a[i] = '*';
		else
			a[i] = 'o';
		if(a[i + 1] == 'o')
			a[i + 1] = '*';
		else
			a[i + 1] = 'o';

	};
	for(int i = 0;i < (int)a.size();++i)
	{
		if(a[i] != b[i])
			change(i),res++;
	}
	cout << res << endl;
	return 0;
}
