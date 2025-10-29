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
int pos[200005],a[200005],L[200005],R[200005],n,m,maxn,minn=9999999;
inline bool check()
{
	//for(int i=1;i<=n;++i)cout<<pos[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=m;++i)
	{
		bool flag=false;
		for(int j=1;j<=n;++j)if(pos[j]<=R[i]&&pos[j]>=L[i]){flag=true;break;}
		if(!flag)return false;
	}
	return true;
}
void dsf(int k,int val)
{
	if(k==n+1)
	{
		cout<<val<<endl;
		if(check())minn=min(minn,val);
		return;
	}
	for(int i=1;i<=maxn;++i)
	{
		pos[k]=i;
		dsf(k+1,val+abs(a[k]-i));
	}
}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int j=1;j<=m;++j){L[j]=read();R[j]=read();maxn=max(maxn,R[j]);}
	dsf(1,0);
	printf("%d",minn);
	return 0;
}/*
4 11 2 6 14 18 0 3 4 5 11 15 3 5 10 13 16 16 1 4 8 12 17 19 7 13 14 19*/
