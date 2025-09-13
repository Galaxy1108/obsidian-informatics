#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
int k,T,n;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>k>>T;
	while(T--)
	{
		cin>>n;
		if(k>n/2) cout<<n<<' '<<1<<endl;
	}
	return 0;
}
