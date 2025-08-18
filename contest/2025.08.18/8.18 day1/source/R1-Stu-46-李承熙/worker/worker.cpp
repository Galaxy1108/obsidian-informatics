#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	int a=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,ans=1e7;
char a[110];
void dfs(int A,int B,int C,int t,int p,int an)
{
	if(p==n+1&&!t)
	{
		ans=min(an,ans);
		return ;
	}
	if(an>ans)return ;
	while(t<10&&p<=n)
	{
		if(a[p]=='A')A++;
		if(a[p]=='B')B++;
		if(a[p]=='C')C++;
		t++;
		p++;
	}
	if(A)dfs(0,B,C,t-A,p,an+1);
	if(B)dfs(A,0,C,t-B,p,an+1);
	if(C)dfs(A,B,0,t-C,p,an+1);
	return ;
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0,1,0);
	cout<<ans;
	return 0;
}
