#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=2e6+100;
int sum[mx],fa[mx],l[mx],r[mx];
int n;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void query(int x,int y)
{
	int xx=find(x),yy=find(y);
	fa[xx]=yy;
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	int lk,rk;string s;
	n=fread(),lk=fread(),rk=fread();
	cin>>s;
	int p1=0,p2=0;
	for(int i=0;i<n;i++)
	{
		sum[i+1]=sum[i]+(s[i]=='a');
		fa[i+1]=i+1; 
	}
//	for(int i=0;i<=n;i++)
//	cout<<sum[i]<<' ';cout<<endl;
	for(int i=1;i<=n;i++)
	{
		while(sum[p1]-sum[i-1]<lk&p1<=n)
		p1++;
		while(sum[p2]-sum[i-1]<=rk&&p2<=n)
		p2++;
		if(sum[p1]-sum[i-1]>lk||p1>n)
		p1--;
		if(sum[p2]-sum[i-1]>rk||p2>n)
		p2--;
		if(sum[p1]-sum[i-1]==lk)
		l[i]=p1;
		if(sum[p2]-sum[i-1]==rk)
		r[i]=p2;
		if(l[i]!=0) query(i,l[i]);
		if(l[i]<=r[i-1]&&l[i]!=0)
		{
			for(int j=r[i-1]+1;j<=r[i];j++)
			query(j,r[i-1]);
		}
		else if(l[i]!=0)
		for(int j=l[i];j<=r[i];j++)
		query(i,j);
	}
//	for(int i=1;i<=n;i++)
//	cout<<l[i]<<' '<<r[i]<<endl;
	int q=fread();
	while(q--)
	{
		int x=fread(),y=fread();
		if(find(x)==find(y))
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	return 0;
}


