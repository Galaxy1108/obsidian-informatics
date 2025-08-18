#include <bits/stdc++.h>
using namespace std;

int n,ans=1e9;
int a[105],b[105],c[105];

void dfs(int p,int lst,int ca,int cb,int cc,int st)
{
	if(p>n)
	{
		p=n;
		ca+=a[p]-a[lst];
		cb+=b[p]-b[lst];
		cc+=c[p]-c[lst];
		if(ca)st++;
		if(cb)st++;
		if(cc)st++;
		ans=min(ans,st);
		return ;
	}
	ca+=a[p]-a[lst];
	cb+=b[p]-b[lst];
	cc+=c[p]-c[lst];
	if(ca)dfs(p+ca,p,0,cb,cc,st+1);//·Åa 
	if(cb)dfs(p+cb,p,ca,0,cc,st+1);
	if(cc)dfs(p+cc,p,ca,cb,0,st+1);
	
}


int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='A')a[i]++;
		else if(x=='B')b[i]++;
		else c[i]++;
		a[i]+=a[i-1];
		b[i]+=b[i-1];
		c[i]+=c[i-1];
	}
	dfs(10,0,0,0,0,0);
	cout<<ans;
	return 0;
}
