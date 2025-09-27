#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+5;
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
int n,k,m,i,j;
int a[N],cnt[31];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	n=read();k=read();m=read();
	for(i=1;i<=n;i++) a[i]=read();
	while(m--)
	{
		int op;
		op=read();
		if(op==1)
		{
			int p,v;
			p=read();v=read();
			a[p]=v;
		}
		else
		{
			memset(cnt,0,sizeof(cnt));
			int l=1,r=1,sum=0,ans=INT_MAX;
			while(l<=r&&r<=n)
			{
				int u=a[r];
				++cnt[u];
				if(cnt[u]==1) ++sum;
				while(sum==k)
				{
					ans=min(ans,r-l+1);
					if(--cnt[a[l++]]==0)
						--sum;
				}
				++r;
			}
			if(ans==INT_MAX) printf("-1\n");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
