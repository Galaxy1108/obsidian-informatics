#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register

const int N=2e5+10;
int n,m;
int a[N];
int l[N],r[N];
int ll[N],rr[N],aa[N];
int node[N*3];
int tot;


signed main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=qread(),m=qread();
	for(re int i=1;i<=n;i++)
	{
		a[i]=qread();
		node[++tot]=a[i];
	}
	for(re int i=1;i<=m;i++)
	{
		l[i]=qread();r[i]=qread();
		node[++tot]=l[i];
		node[++tot]=r[i];
	}
	stable_sort(node+1,node+1+tot);
	for(re int i=1;i<=n;i++)
	{
		aa[i]=lower_bound(node+1,node+1+tot,a[i])-node;
	}
	for(re int i=1;i<=m;i++)
	{
		ll[i]=lower_bound(node+1,node+1+tot,l[i])-node;
		rr[i]=lower_bound(node+1,node+1+tot,r[i])-node;
	}
	int ans=0;
	for(re int i=1;i<=m;i++)
	{
		ans+=min(abs( l[i]-node[ll[i]-1] ), abs( node[rr[i]+1]-r[i] ));
	}
	cout<<ans<<endl;
	return 0;
}
