#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
int ls[N],rs[N],l[N],r[N],c[N],a[N],mx[N],mn[N];
void dfs(int x)
{
	l[x]=x;r[x]=x;mx[x]=a[x];mn[x]=a[x];
	if(ls[x])
	{
		dfs(ls[x]);
		l[x]=l[ls[x]];
		mx[x]=max(mx[x],mx[ls[x]]);
		mn[x]=min(mn[x],mn[ls[x]]);
	}
	if(rs[x])
	{
		dfs(rs[x]);
		r[x]=r[rs[x]];
		mx[x]=max(mx[x],mx[rs[x]]);
		mn[x]=min(mn[x],mn[rs[x]]);
	}
	//cout<<x<<' '<<ls[x]<<' '<<rs[x]<<' '<<l[x]<<' '<<r[x]<<'\n';
}
void print(__int128 x)
{
	if(!x)return;
	print(x/10);
	cout<<(int)(x%10);
}
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int top=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int mn=0;
		while(top&&a[c[top]]>=a[i])
		{
			mn=c[top];
			top--;
		}
		ls[i]=mn;
		rs[c[top]]=i;
		c[++top]=i;
		//cout<<mn<<'\n';
	}
	int t=1;
	for(int i=1;i<=n;i++)
		if(a[i]<a[t])t=i;
	dfs(t);
	//for(int i=1;i<=n;i++)cout<<mn[i]<<' '<<mx[i]<<' '<<l[i]<<' '<<r[i]<<'\n';
	__int128 ans=0;
	for(int i=1;i<=n;i++)
		if((__int128)mn[i]*mx[i]*(r[i]-l[i]+1)>ans)
			ans=(__int128)mn[i]*mx[i]*(r[i]-l[i]+1);
	print(ans);cout<<'\n';
	return 0;
}
