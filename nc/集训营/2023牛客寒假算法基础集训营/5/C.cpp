//#pragma GCC optimize(2)
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
    
	string a,b;
	cin >> a >> b;
	int flag = 0;
	if(a.size() < b.size())
	{
		swap(a,b);
		flag = 1;
	}

	if(a == b)
		cout << "=\n";
	else if(a.size() == b.size())
		cout << "!\n";
	else 
	{
		int l1 = 0;
		for(int i = 1;i < a.size();++i)
			if(a[i] == a[0])
				l1 = i;
			else break;
		int l2 = -1;
		for(int i = 0;i < b.size();++i)
			if(b[i] == a[0])
				l2 = i;
			else break;
		int len1 = a.size() - l1 - 1;
		int len2 = b.size() - l2 - 1;
		if(len1 > len2)
		{
			if(flag)
				cout << "<\n";
			else 
				cout << ">\n";
		}
		else if(len1 == len2)
		{
			for(int i = l1 + 1, j = l2 + 1;i < a.size() && j < b.size();++i,++j)
			{
				if(a[i] == b[j])
					continue;
				if(b[j] == a[0])
				{
					if(flag)
						cout << "<\n";
					else 
						cout << ">\n";
					return 0;
				}
				else 
				{
					cout << "!\n";
					return 0;
				}
			}
			cout << "!\n";
		}
		else 
			cout << "!\n";
	}
    //finish = clock();
    //cout <<endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<endl;
    
    return 0;
}
