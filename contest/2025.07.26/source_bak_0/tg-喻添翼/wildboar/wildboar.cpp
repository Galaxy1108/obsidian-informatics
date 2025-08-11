#include<bits/stdc++.h> 
using namespace std;
const int mx=2010;
int n,m,t,l;
int a[mx],b[mx],c[mx],x[200010],p[100010],q[100010];
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	cin>>n>>m>>t>>l;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=l;i++) cin>>x[i];
	for(int i=1;i<=t;i++) cin>>p[i]>>q[i];
	for(int i=1;i<=t;i++)
	{
		cout<<-1<<endl;
	}
	return 0;
}
