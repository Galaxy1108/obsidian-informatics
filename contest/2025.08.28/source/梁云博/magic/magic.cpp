#include <bits/stdc++.h>
#define N 250005 
#define ls p<<1
#define rs p<<1|1 
#define mid (l+r>>1)
#define ll long long
#define INF -1e18
#define P 998244353
using namespace std;
int n,m;
ll at[N<<2],mt[N<<2],ct[N<<2],a[N<<2],b[N<<2],c[N<<2];
ll A[N],B[N],C[N],op[N],L[N],R[N],v[N];
void up(int p) 
{
	a[p]=(a[ls]+a[rs])%P;
	b[p]=(b[ls]+b[rs])%P;
	c[p]=(c[ls]+c[rs])%P;
}
void build(int p,int l,int r)
{
	mt[p]=1;
	ct[p]=INF;
	if(l==r)
	{
		a[p]=A[l]%P;
		b[p]=B[l]%P;
		c[p]=C[l]%P;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	up(p);
}

void down(int p,int l,int r)//考虑只有加法，加法和覆盖的重叠，加法乘法的重叠 
{
	if((at[p]==0 && mt[p]==1 && ct[p]==INF) || l==r)return;
	if(mt[p]!=1)
	{
		//下传mt
		mt[ls]=(mt[ls]*mt[p])%P;
		mt[rs]=(mt[rs]*mt[p])%P;
		b[ls]=(b[ls]*mt[p])%P;
		b[rs]=(b[rs]*mt[p])%P;
	}
	if(ct[p]!=INF)//有覆盖标记 
	{
		ct[ls]=ct[rs]=ct[p]%P;
		c[ls]=ct[p]*(mid-l+1)%P;
		c[rs]=ct[p]*(r-mid)%P;
	}
	if(at[p])//只有加法标记
	{
		at[ls]=(at[ls]+at[p])%P;
		a[ls]=(a[ls]+(mid-l+1)*at[p]%P)%P; 
		at[rs]=(at[rs]+at[p])%P;
		a[rs]=(a[rs]+(r-mid)*at[p]%P)%P; 
	}
	ct[p]=INF;
	at[p]=0;
	mt[p]=1;
}

void add(int p,int l,int r,int ul,int ur,ll k)//只用于a 
{
	
	if(ul<=l && r<=ur)
	{
		at[p]=(at[p]+k)%P;
		a[p]=(a[p]+(r-l+1)*k%P)%P;
		return ;
	}
	down(p,l,r); 
	if(mid>=ul)add(ls,l,mid,ul,ur,k);
	if(mid+1<=ur)add(rs,mid+1,r,ul,ur,k);
	up(p);
}
void mul(int p,int l,int r,int ul,int ur,ll k)
{
	if(ul<=l && r<=ur)
	{
		mt[p]=(mt[p]*k)%P;
		b[p]=(b[p]*k)%P;
		return ;
	}
	down(p,l,r);
	if(mid>=ul)mul(ls,l,mid,ul,ur,k);
	if(mid+1<=ur)mul(rs,mid+1,r,ul,ur,k);
	up(p);
}
void cov(int p,int l,int r,int ul,int ur,ll k)
{
	if(ul<=l && r<=ur)
	{
		ct[p]=k;
		c[p]=(r-l+1)*k%P;
		return ;
	}
	down(p,l,r);
	if(mid>=ul)cov(ls,l,mid,ul,ur,k);
	if(mid+1<=ur)cov(rs,mid+1,r,ul,ur,k);
	up(p);
}
ll query(int p,int l,int r,int ql,int qr,ll x[])
{
	if(ql<=l && r<=qr)return x[p];
	down(p,l,r);
	ll res=0;
	if(mid>=ql)res=(res+query(ls,l,mid,ql,qr,x))%P;
	if(mid+1<=qr)res=(res+query(rs,mid+1,r,ql,qr,x))%P;
	return res;
}



int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>A[i]>>B[i]>>C[i];
	build(1,1,n);
	cin>>m;
	int flg3=1,flg2=1;
	for(int i=1;i<=m;i++)
	{
		cin>>op[i]>>L[i]>>R[i];
		if(op[i]<4)flg2=0;
		else
		{
			flg3=0;
			if(op[i]!=7)cin>>v[i];
		}
	}
	if(flg3)return 0;
	if(m<=1000 && n<=1000)//两个都是n^2 
	{
		//baoli
		for(int i=1;i<=m;i++)
		{
			if(op[i]==1)for(int j=L[i];j<=R[i];j++)A[j]=(A[j]+B[j])%P;
			else if(op[i]==2)for(int j=L[i];j<=R[i];j++)B[j]=(B[j]+C[j])%P;
			else if(op[i]==3)for(int j=L[i];j<=R[i];j++)C[j]=(C[j]+A[j])%P;
			else if(op[i]==4)for(int j=L[i];j<=R[i];j++)A[j]=(A[j]+v[i])%P;
			else if(op[i]==5)for(int j=L[i];j<=R[i];j++)B[j]=(B[j]%P)*(v[i]%P)%P;
			else if(op[i]==6)for(int j=L[i];j<=R[i];j++)C[j]=v[i]%P;
			else if(op[i]==7)
			{
				int sum=0;
				for(int j=L[i];j<=R[i];j++)sum+=A[j],sum%=P;
				cout<<sum<<" ";
				sum=0;
				for(int j=L[i];j<=R[i];j++)sum+=B[j],sum%=P;
				cout<<sum<<" ";
				sum=0;
				for(int j=L[i];j<=R[i];j++)sum+=C[j],sum%=P;
				cout<<sum<<"\n";
			}
			
		}
	}
	else if(flg2)
	{
		for(int i=1;i<=m;i++)
		{
			if(op[i]==4)add(1,1,n,L[i],R[i],v[i]);
			else if(op[i]==5)mul(1,1,n,L[i],R[i],v[i]);
			else if(op[i]==6)cov(1,1,n,L[i],R[i],v[i]);
			else if(op[i]==7)cout<<query(1,1,n,L[i],R[i],a)<<" "<<query(1,1,n,L[i],R[i],b)<<" "<<query(1,1,n,L[i],R[i],c)<<"\n";
		}
	}
	else cout<<"myyakioi\n";
	return 0;
} 
//小于ai的加一大于ai的减一
//区间修改//不对QWQ 
