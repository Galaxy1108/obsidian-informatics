#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,k,mp[2000][2000],a[4000010],ans;
int f(int h)
{
	int an=1;
	while(h)
	{
		an*=h%10;
		h/=10;
	}
	return an;
}
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	n=qread();
	k=qread();
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=n;++j)
		{
			mp[f(i)][f(j)]++;
		}
	}
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=n;++j)
		{
			a[++a[0]]=mp[i][j];
		}
	}
	sort(a+1,a+1+a[0],cmp);
	for(register int i=1;i<=k;++i)
	{
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
