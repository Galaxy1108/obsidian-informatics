#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    char c=getchar();
    int x=0;
    bool f=0;
    while(c<'0'||c>'9')
    {
    	if(c=='-') f=1;
    	c=getchar();
	}
	while(c>='0'&&c<='9')
    {
    	x=x*10+c-'0';
    	c=getchar();
	}
    return (f?-x:x);
}
int a[500005],t,n,m,x,y,z,cnt1,cnt2;
bool cmp(int xx,int yy)
{
	return xx>yy;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//cin>>t;
	//scanf("%lld",&t); 
	t=read();
	while(t--)
	{
		//scanf("%lld%lld",&n,&m); 
		n=read();
		m=read();
		for(int i = 1; i <= n; i++) a[i]=0;
		for(int i = 1; i <= m; i++)
		{
			//scanf("%lld%lld%lld",&x,&y,&z); 
			x=read();
			y=read();
			z=read();
			a[x]+=z;
			a[y]+=z;
		}
		sort(a+1,a+n+1,cmp);
		cnt1=0;
		cnt2=0;
		for(int i = 1; i <= n; i++)
		{
			if(i&1) cnt1+=a[i];
			else cnt2+=a[i];
		}
		printf("%lld\n",(cnt1-cnt2)/2);
	}
	return 0;
}
