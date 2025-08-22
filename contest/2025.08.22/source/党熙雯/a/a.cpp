#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int n,m,p;
int a[11000000];
int ans1;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2) ans*=a,ans%=p;
		a*=a,a%=p;
		b/=2;
	}
	return ans;
}
int inv(int x,int mod)
{
	return ksm(x,mod-2);
}
void dfs(int k,int l,int r)
{
//	cout<<l<<' '<<r<<endl;
	if(k==n)
	{
		ans1++,ans1%=p;
		return ;
	}
	for(int ll=1;ll<=l;ll++)
	{
		for(int rr=l;rr<=m;rr++)
		{
			dfs(k+1,ll,rr);
		}
	}
	for(int ll=l+1;ll<=r;ll++)
	{
		for(int rr=ll;rr<=m;rr++)
		dfs(k+1,ll,rr);
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=fread(),m=fread(),p=fread();
	if(min(m,n)==1)
	{
		if(m==1)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<((m+1)%p*m%p*inv(2,p))%p;
			return 0;
		}
	}
	else if(n<=3)
	{
		int x=1,y=1;
		a[1]=m;
		for(int i=2;i<=(m+1)*m/2;i++)
		{
			if(y+1>m) y=x+1,x++;
			else y++;
			if(y>m) break;
			int r=(m-y),l=(x-1),mid=(y-x+1);
	//		cout<<x<<' '<<y<<endl;
			a[i]=l*(mid+r)+mid*(mid+1)/2+mid*r;
			cout<<a[i]<<endl;
		}
		int ans=0;
		for(int i=1;i<=(m+1)*m/2;i++)
		{
			ans+=ksm(a[i],n-1)%p;
			ans%=p;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		dfs(1,1,1);
		int x=1,y=1;
		for(int i=2;i<=(m+1)*m/2;i++)
		{
			if(y+1>m) y=x+1,x++;
			else y++;
			if(y>m) break;
			dfs(1,x,y);
		}
		cout<<ans1;
	}
}

