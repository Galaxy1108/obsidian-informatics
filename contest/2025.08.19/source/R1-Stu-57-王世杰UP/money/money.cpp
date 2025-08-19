#include<bits/stdc++.h>
using namespace std;
int n;
double cost,ans;
double w[105],c[105],d[105];
void dfs(int day,double dol,double yuan)
{
	if(day>n)
	{
		ans=max(ans,yuan);
	}
	else
	{
		int s=0;
		if(dol!=0) s=1;
		dfs(day+1,0,yuan+w[day]+dol*d[day]-cost*s);
		dfs(day+1,dol+(yuan+w[day])*c[day],0);
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>cost;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i]>>d[i];
	}
	dfs(1,0.0,0.0);
	printf("%.4lf",ans);
	return 0;
}
