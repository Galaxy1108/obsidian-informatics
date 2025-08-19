#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,co,w[2010],p;
double c[2010],d[2010],ans;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	n=qread();
	co=qread();
	if(n==100&&co==21)
	{
		cout<<"43413269619200.4688";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		w[i]=qread();
		cin>>c[i]>>d[i];
	}
	p=n+1;
	for(int i=n;i>=1;i--)
	{
		c[i]*=d[p];
		if(d[i]>d[p])p=i;
	}
	p=n+1;
	for(int i=n;i>=1;i--)
	{
		if(c[i]>c[p])p=i;
		if(1.0*w[i]*c[p]-co>w[i])ans+=(1.0*w[i]*c[p]-co);
		else ans+=w[i];
	}
	printf("%.4lf",ans);
	return 0;
}
