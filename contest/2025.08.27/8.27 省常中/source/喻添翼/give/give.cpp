#include<bits/stdc++.h>
using namespace std;
const int mx=210;
int a[mx];
int T,m,s,n;
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>m>>s>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1) 
		{
			if(m*a[1]==s) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else cout<<1<<endl;
	}
	return 0;
} 
