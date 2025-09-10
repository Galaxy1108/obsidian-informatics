#include<bits/stdc++.h>
#define eps 1e-12
using namespace std;
const int N=1005;
double f[N][N];
double dfs(int n,int m)
{
	if(!n)return 0;
	if(f[n][m]>0)return f[n][m];
	double ans=(double)n/(n+m);
	//if(m>0)ans+=(double)m/(n+m)*n/(n+m-1);
	//cout<<ans<<'\n';
//	if(m>=2&&n>0)ans+=dfs(n-1,m-2)*m/(n+m)*n/(n+m-1)*(m-1)/(n+m-2);
//	if(m>=1&&n>1)ans+=dfs(n-2,m-1)*m/(n+m)*n/(n+m-1)*(n-1)/(n+m-2);
	if(m>=3)ans+=dfs(n,m-3)*m/(n+m)*(m-1)/(n+m-1)*(m-2)/(n+m-2);
	if(m>=2&&n>0)ans+=dfs(n-1,m-2)*m/(n+m)*(m-1)/(n+m-1)*n/(n+m-2);
	f[n][m]=ans;
	//cout<<n<<' '<<m<<' '<<ans<<'\n';
	return ans;
}
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	int n,m;
	cin>>n>>m;
	printf("%.9lf",dfs(n,m)+eps);
	return 0;
}
