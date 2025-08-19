#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=2e3+10;
int n,cost;
double w[N],c[N],d[N],ans,dm[N],cm[N],wt[N];
void dfs(int day,double R,double D)
{
	R+=w[day];
	if(((R+wt[day+1])*cm[day]+D)*dm[day]<ans) return ;
	if(day==n)
	{
		ans=max(ans,max(R,R+D*d[day]-cost));
		return ;
	}
	else if(D&&R)
	{
		if(D*d[day]-cost>0)
		{
			dfs(day+1,R+D*d[day]-cost,0);
			dfs(day+1,0,R*c[day]+D);
		}
		else
		{
			dfs(day+1,0,R*c[day]+D);
		}
	}
	else if(R)
	{
		dfs(day+1,0,D+R*(c[day]));
	}
	else
	{
		if(D*d[day]-cost>0)
		{
			dfs(day+1,R+D*d[day],0);
		}
	}
	dfs(day+1,R,D);
}
signed main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>cost;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i]>>d[i];
	}
	for(int i=n;i>=1;i--) wt[i]=wt[i+1]+w[i],cm[i]=max(cm[i],c[i]),dm[i]max(dm[i+1],d[i]);
	dfs(1,0,0);
	cout<<setprecision(4)<<fixed<<ans;
	return 0;
}
