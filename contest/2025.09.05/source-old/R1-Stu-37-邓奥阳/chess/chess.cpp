#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int mod=9999973;
int n,m;
int r[101],c[101];
//long long f[101][101][3][3],g[101][101][3][3],ans[101][101][3][3];
int an1;

int an;
int qm(int a){return a>=mod?a%mod:a;}
void dfs(int x)
{
	if(x>n){an=qm(an+1);return;}
	dfs(x+1);
	for(int i=1;i<=m;++i)
		if(r[i]<2)++r[i],dfs(x+1),--r[i];
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			if(r[i]<2&&r[j]<2)++r[i],++r[j],dfs(x+1),--r[i],--r[j];
}

/*
int dp(int i,int j,int k,int l)
{
	if(i>n||j>m||i<k||j<l)return 1;
	if(k==2||l==2)return 1;
	if(i==n&&j==m)return 2;
	if(f[i][j][k][l])return f[i][j][k][l];
	return f[i][j][k][l]=dp(i+1,j,0,l+1)+dp(i+1,j,0,l)+dp(i,j+1,k+1,0)+dp(i,j+1,k,0); 
}
*/

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m)n^=m^=n^=m;
	dfs(1);printf("%d\n",an);
	return 0;
}
