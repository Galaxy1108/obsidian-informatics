#include<bits/stdc++.h>
using namespace std;

int n,a[100010],k,m;
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int op,p,v;
		cin>>op;
		if(op==1) cin>>p>>v;
		if(op==2) cout<<-1<<endl;
	}
	return 0;
}
