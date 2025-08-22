#include <bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN];
int vis[MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n=fread(),seed=fread();
	if(seed==0)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) a[i][j]=fread();
	}
	else
	gen(n,seed);
	for(int i=1;i<=n;i++)
	a[i][n+2]=123131234;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int minn=n+2;
			for(int k=1;k<=n+1;k++)
			{
				int now=i+j-1;
				if(now>n) now-=n;
				if(vis[k]==0&&a[now][k]<a[now][minn])
				minn=k;
			}
			vis[minn]=1;
		}
		for(int j=1;j<=n+1;j++)
		{
			if(vis[j]==0) cout<<j<<' ';
			vis[j]=0;
		}
//		cout<<endl;
	}
}
