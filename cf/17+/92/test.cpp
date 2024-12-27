#include<iostream>
#include<cstring>
using namespace std;
using LL = long long;
const int maxn = 2e5 + 5;
int a[maxn], pos[maxn];

int main(){

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) 
			cin >> a[i], pos[a[i]] = i;

		if (n & 1){
			int l = pos[n / 2 + 1], r = pos[n / 2 + 1];
			int t1 = n / 2, t2 = n / 2 + 2;
			int ans = n / 2;
			while(t1 >= 1){
				if (pos[t1] < l && pos[t2] > r){
					l = pos[t1], r = pos[t2];
					ans--;
					t1--, t2++;
				}
				else break;
			}
			cout << ans << '\n';
		}
		else{
			int t1 = n / 2, t2 = n / 2 + 1;
			if (pos[t1] > pos[t2]){
				cout << n / 2 << '\n';
				continue;
			}
			int l = pos[t1], r = pos[t2];
			t1--, t2++;
			int ans = n / 2 - 1;
			while(t1 >= 1){
				if (pos[t1] < l && pos[t2] > r){
					l = pos[t1], r = pos[t2];
					ans--;
					t1--, t2++;
				}
				else break;
			}
			cout << ans << '\n';
		}
	}
}
