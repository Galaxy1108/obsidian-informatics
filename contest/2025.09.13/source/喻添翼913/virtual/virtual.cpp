#include<bits/stdc++.h> 
using namespace std;
const int mx=2e6+10;
int n,lk,rk,q;
char ch[mx];
int fa[mx],siz[mx],sum[mx];
inline int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void add(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	sum[0]=0;
	cin>>n>>lk>>rk;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i];
		sum[i]=sum[i-1]+(ch[i]=='a' ? 1:0);
	} 
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	
	for(int i=1;i<=n;i++)
	{
		int p1,p2;
		p1=lower_bound(sum+i,sum+1+n,sum[i-1]+lk)-sum;
		p2=upper_bound(sum+i,sum+1+n,sum[i-1]+rk)-sum-1;
		for(int j=p1;j<=p2;j++) add(i,j);
	}
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b)) cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
	return 0;
}

