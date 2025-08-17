#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+100;
const int mod=1e9+9;
int n,m,q;
int root[mx];
long long sum[5100][5100];
//struct tree
//{
//	int ls,rs;
//	long long num;
//	int l,r;
//}t[80*mx];
//long long cnt=0;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*w;
 } 
//int build(int p,int l,int r)
//{
//	p=++cnt;
//	t[p].num=0;
//	t[p].l=l,t[p].r=r;
//	if(l==r)
//	{
//		return p;
//	}
//	int mid=(l+r)/2;
//	t[p].ls=build(p,l,mid);
//	t[p].rs=build(p,mid+1,r);
//	return p;
//}
//void update(long long p)
//{
//	t[p].num=t[t[p].ls].num%mod+t[t[p].rs].num%mod;
//	t[p].num%=mod;
//}
////void pushdown(long long p)
////{
////	if(t[p].lazy>0)
////	{
////		t[t[p].ls].lazy+=t[p].lazy;
////		t[t[p].rs].lazy+=t[p].lazy;
////		t[t[p].ls].num+=(t[t[p].ls].r-t[t[p].ls].l+1)*t[p].lazy;
////		t[t[p].rs].num+=(t[t[p].rs].r-t[t[p].rs].l+1)*t[p].lazy;
////		t[p].lazy=0;
////	}
////	return ;
////}
//int bnew(int p)
//{
//	cnt++;
//	t[cnt]=t[p];
//	return cnt;
//}
//int add(int p,int l,int r,int k)
//{
//	k%=mod;
//	int old=p;
//	p=bnew(p);
//	if(t[p].l==t[p].r)
//	{
//		t[p].num+=k;
//		t[p].num%=mod; 
//		return p;
//	}
////	pushdown(old);
////	p=bnew(p);
//	int mid=(t[p].l+t[p].r)/2;
//	if(l<=mid) t[p].ls=add(t[p].ls,l,r,k);
//	if(r>mid) t[p].rs=add(t[p].rs,l,r,k);
//	update(p);
//	return p;
//}
//long long ask(long long p,long long l,long long r)
//{
//	if(t[p].l>=l&&t[p].r<=r)
//	return t[p].num;
//	long long ans=0;
//	int mid=(t[p].l+t[p].r)/2;
//	if(l<=mid) ans+=ask(t[p].ls,l,r);
//	ans%=mod;
//	if(r>mid) ans+=ask(t[p].rs,l,r);
//	ans%=mod;
//	return ans; 
//}
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	n=fread(),m=fread(),q=fread();
//	root[0]=build(0,1,n);
	for(int i=1;i<=m;i++)
	{
		int l=fread(),r=fread(),x=fread();
		x%=mod;
//		root[i]=add(root[i-1],l,r,x);
		for(int j=1;j<=n;j++)
		{
			if(j>=l&&j<=r)
			sum[i][j]+=x;
			sum[i][j]+=((sum[i-1][j]-sum[i-2][j]+mod)%mod-sum[i-1][j-1]+mod)%mod+sum[i-2][j-1];
			sum[i][j]%=mod;
			sum[i][j]+=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mod)%mod;
			sum[i][j]%=mod;
		}
//		cout<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		int u=fread(),d=fread(),l=fread(),r=fread();
		long long ans=0;
//		for(int j=u;j<=d;j++)
//		{
//			ans+=ask(root[j],l,r);
//			ans%=mod;
//		}
		ans=(((sum[d][r]-sum[u-1][r]+mod)%mod-sum[d][l-1]+mod)%mod+sum[u-1][l-1])%mod;
		cout<<ans<<endl;
	}
	return 0;
}
