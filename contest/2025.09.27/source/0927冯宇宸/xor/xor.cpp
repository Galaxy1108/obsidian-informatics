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
int n,i,j,l,r,ans,amax;
int a[N][17],lg[N],s[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++)
		a[i][0]=read(),
		s[i]=s[i-1]^a[i][0];
	lg[1]=0;
	for(i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(j=1;j<=lg[n];j++)
		for(i=1;i+(1<<j)-1<=n;i++)
			a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]);
	ans=n;
	for(l=1;l<n;l++)
	{
		for(r=l+1;r<=n;r++)
		{
			int k=lg[r-l+1];
			int amax=max(a[l][k],a[r-(1<<k)+1][k]);
			int t=s[r]^s[l];
			if(t<=amax) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
