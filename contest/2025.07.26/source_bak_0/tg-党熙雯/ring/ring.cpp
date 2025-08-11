#include<bits/stdc++.h>
#define int long long      
using namespace std;
//int d[52][52];//差分数组
int a[52][52];//原数组
int an[110];
//int l[52][52];//前缀和数组 
//int r[52][52];//后缀和数组 滚 
int len[52];//表示第i个数列的长度  
int ss[110];
int n;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
int getanswer()
{
	int ans=0;
//	cout<<endl;
	int sum=0;
//	for(int i=1;i<=n;i++) cout<<an[i]<<' ';
//	cout<<endl;
	for(int i=1;i<n;i++)
	{
		sum=0;
		for(int j=an[i];j<=len[i];j++)
		ss[j-an[i]+1]=a[i][j];
		for(int j=1;j<=an[i+1]-1;j++)
		ss[len[i]-an[i]+j+1]=a[i+1][j];
		sort(ss+1,ss+len[i]-an[i]+an[i+1]+1);
//		for(int j=1;j<=len[i]-an[i]+an[i+1];j++)
//		cout<<ss[j]<<' ';
//		cout<<endl;
		for(int j=1;j<=len[i]-an[i]+an[i+1];j++)
		{
//			cout<<ss[i]<<' '<<ss[i-1]<<endl;
			sum+=(ss[j]-ss[j-1])*(ss[j]-ss[j-1]);
		}
		sum+=(2000000-ss[len[i]-an[i]+an[i+1]])*(2000000-ss[len[i]-an[i]+an[i+1]]);
//		cout<<sum<<'\n';
		ans+=sum;
	}
//	cout<<ans<<endl;
	return ans;
}
int ans1=1e18,sum=0;
void dfs(int k)
{
	if(k==n)
	{
		an[n]=an[1];
		ans1=min(ans1,getanswer());
		return ;
	}
	for(int i=1;i<=len[k];i++)
	{
		an[k]=i;
		dfs(k+1);
	}
}
signed main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=fread();
	for(int i=1;i<=n;i++)
	{
		len[i]=fread();
		for(int j=1;j<=len[i];j++)
		{
			a[i][j]=fread();
		}
	}
	n++;
	for(int i=1;i<=len[1];i++)
	a[n][i]=a[1][i];
	len[n]=len[1];
	dfs(1);
	cout<<ans1;
	return 0;
}

