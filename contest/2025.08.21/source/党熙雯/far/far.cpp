#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mod=998244353;
int n,m;
struct pj
{
	int l,r;
}a[1100];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ans[1100];
bitset<60> b;
void dfs(int k,int now)
{
	b=now;
	int flag=0;

	for(int p1=0,p2=m-1;p1<m/2;p1++,p2--)
	{
		if(b[p1]!=b[p2])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		ans[k]++;
		ans[k]%=mod;
//		cout<<k<<endl<<b[0]<<' '<<b[1]<<endl<<b<<endl;
	}
	if(k==n) return ;
	k++;
	for(int i=a[k].l;i<=a[k].r;i++)
	{
		dfs(k,now^i);
	}
	return ;
}
int main()
{
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	n=fread(),m=fread();
	for(int i=1;i<=n;i++)
	a[i].l=fread(),a[i].r=fread();
	dfs(0,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}


