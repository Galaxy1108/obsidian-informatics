#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
inline ll read()
{
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(ll x)
{
	if(x>'9') write(x/10);
	putchar(x%10+'0');
}
inline int abs(int x){
	return x<=0?-x:x;
}
int n,m,i,j,l,r,ans;
int a[N],b[N];
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	n=read();m=read();
	int t=max(m,n);
	vector<bool> vis(t+1);
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=m;i++) b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(n<m)
	{
		for(i=1;i<=n;i++)
		{
			int s=lower_bound(b+1,b+m+1,a[i])-b;
			if(!vis[s]&&b[s]-a[i]<=ans)
				vis[s]=1;
			else
			{
				int h=s-1;
				while(vis[s]&&s<m) ++s;
				while(vis[h]&&h>0) --h;
				if(vis[s]) ans=max(ans,a[i]-b[h]),vis[h]=1;
				else if(vis[h]) ans=max(ans,b[s]-a[i]),vis[s]=1;
				else
				{
					int d=b[s]-a[i]-(a[i]-b[h]);
					if(d>=0) ans=max(ans,a[i]-b[h]),vis[h]=1;
					if(d<0) ans=max(ans,b[s]-a[i]),vis[s]=1;
				}
			}
		}
	}
	else if(n==m)
	{
		for(i=1;i<=n;i++)
			ans=max(ans,abs(b[i]-a[i]));
	}
	else
	{
		for(i=1;i<=m;i++)
		{
			int s=lower_bound(a+1,a+n+1,b[i])-a;
			if(!vis[s]&&a[s]-b[i]<=ans)
				vis[s]=1;
			else
			{
				int h=s-1;
				while(vis[s]&&s<n) ++s;
				while(vis[h]&&h>0) --h;
				if(vis[s]) ans=max(ans,b[i]-a[h]),vis[h]=1;
				else if(vis[h]) ans=max(ans,a[s]-b[i]),vis[s]=1;
				else
				{
					int d=a[s]-b[i]-(b[i]-a[h]);
					if(d>=0) ans=max(ans,b[i]-a[h]),vis[h]=1;
					if(d<0) ans=max(ans,a[s]-b[i]),vis[s]=1;
				}
			}
		}
	}
	write(ans);
	return 0;
}
