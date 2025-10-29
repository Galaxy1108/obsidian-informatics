#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,k=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')k=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*k;
}
int ans,n,mod,a[205],b[205],tree[205];
inline int lowbit(int x){return x&(-x);}
inline void update(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}
inline int query(int x)
{
	int res=0;
	while(x)
	{
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=read(),mod=read();
	for(int i=1;i<=n;++i)a[i]=i;
	do
	{
		for(int i=1;i<=n;++i)b[i]=a[i];
		int temp=0;
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;++i)
		{
			update(a[i],1);
			temp+=i-query(a[i]);
		}
		while(next_permutation(b+1,b+n+1))
		{
			int temp1=0;
			memset(tree,0,sizeof(tree));
			for(int i=1;i<=n;++i)
			{
				update(b[i],1);
				temp1+=i-query(b[i]);
				if(temp1>=temp)break;
			}
			if(temp1<temp)++ans;
		}
	}while(next_permutation(a+1,a+n+1));
	printf("%d",ans); 
	return 0;
}
