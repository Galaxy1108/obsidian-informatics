#include<bits/stdc++.h>
using namespace std;
const int mm=2e5+5;
int n,ans=mm,sum,cnt;
int a[mm],b[mm];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void find()
{
	int Sum=0;
	for(int i=1;i<=n;i++) 
	{
		Sum=Sum+abs(b[i]);
	}
	ans=min(ans,Sum);
	if(ans==0) return ;
}
void dfs(int i)
{
	if(ans==0) return ;
	if(cnt>=sum) find();
	else
	{
		i++;
		cnt++;
		b[i]--;
		dfs(i);
		b[i]++;
		cnt--;
		i--;
		
		i--;
		cnt++;
		b[i+1]--;
		dfs(i);
		b[i+1]++;
		cnt--;
		i++;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i],sum+=a[i];
	for(int i=1;i<=n;i++) dfs(i);
	cout<<ans<<endl;
	return 0;
}
