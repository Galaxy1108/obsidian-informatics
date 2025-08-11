#include <bits/stdc++.h>
using namespace std;
int H,W;
int a[1000010],b[1000010],x,y;
double f[1000010],g[1000010],rm;
long long ans;
int stk[1000010],top;
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>H>>W;
	for(int i=1;i<=H;i++) cin>>a[i];
	for(int i=1;i<=W;i++) cin>>b[i];
		
	for(int i=1;i<=H;i++)
	{
		while(top>=2&&1ll*(a[i]-a[stk[top-1]])*(stk[top]-stk[top-1])<=1ll*(a[stk[top]]-a[stk[top-1]])*(i-stk[top-1])) top--;
		stk[++top]=i;
	}

	for(int i=1;i<top;i++)
	{
		rm=1.0*(a[stk[i+1]]-a[stk[i]])/(stk[i+1]-stk[i]);
		for(int j=stk[i];j<stk[i+1];j++)
			f[j]=rm;
	}

	top=0;

	for(int i=1;i<=W;i++)
	{
		while(top>=2&&1ll*(b[i]-b[stk[top-1]])*(stk[top]-stk[top-1])<=1ll*(b[stk[top]]-b[stk[top-1]])*(i-stk[top-1])) top--;
		stk[++top]=i;
	}

	for(int i=1;i<top;i++)
	{
		rm=1.0*(b[stk[i+1]]-b[stk[i]])/(stk[i+1]-stk[i]);
		for(int j=stk[i];j<stk[i+1];j++)
			g[j]=rm;
	}

	x=y=1;
	while(x<H&&y<W)
	{
		if(f[x]<g[y]) ans+=b[y],x++;
		else ans+=a[x],y++;
	}
	while(x<H) ans+=b[y],x++;
	while(y<W) ans+=a[x],y++;
	printf("%lld\n",ans);
	return 0;
}