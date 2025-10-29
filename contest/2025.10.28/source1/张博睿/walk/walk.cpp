#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register

const int N=2e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int n;
int a[N];
int tmp[N];
int pre[N],suf[N];
int out=inf;

//inline void dfs(int pos,int res)
//{
////	cout<<res<<endl;
//	if(pos<0||pos>n)return ;
//	if(res>out)return ;
//	out=min(out,res);
//	if(pos-1>=0)
//	{
//		a[pos]--;
//		if(a[pos]<=0)dfs(pos-1,res+1);
//		else dfs(pos-1,res-1);
//		a[pos]++;
//	}
//	if(pos+1<=n)
//	{
//		a[pos+1]--;
//		if(a[pos+1]<=0)dfs(pos+1,res+1);
//		else dfs(pos+1,res-1);
//		a[pos+1]++;
//	}
//}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=qread();
	for(re int i=1; i<=n; i++) a[i]=qread() , tmp[i]=a[i];
//	if(n<=5)
//	{
//		int sum=0;
//		for(re int i=1;i<=n;i++)sum+=a[i];
//		for(re int i=0;i<=n;i++)
//		{
//			for(re int i=1;i<=n;i++)a[i]=tmp[i];
//			dfs(i,sum);
//		}
//		cout<<out<<endl;
//	}
//	else
//	{
	for(re int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i] ;
	for(re int i=n; i>=1; i--) suf[i] = suf[i+1] + a[i] ;

	int ans=inf;
	for(re int i=n; i>=0; i--)
	{
		int res=-1;
		for(re int j=i; j>=1; j--)
		{
			if(a[j]%2==1)res++;
			ans=min(ans, res + suf[i+1] + pre[j-1]  );
		}
		ans=min(ans,res+suf[i+1]);
	}
	cout<<ans<<endl;
//	}
	return 0;
}
/*
4
1
0
2
3
*/

