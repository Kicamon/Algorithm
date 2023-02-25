//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <valarray>
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
	string s;
	cin >> s;
	cout << s[0];
	for(int i = 1;i < n;++i)
	{
		if(s[i] == 'a' && s[i - 1] == 'n')
			cout << 'y';
		cout << s[i];
	}
	cout << endl;
    
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
