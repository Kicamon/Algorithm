#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int x=n-m;
    if(n<=2||x>=2*(m-1))
        cout<<0<<endl;
    else 
        cout<<m-x/2-2+(x!=0)<<endl;
    return 0;
}
