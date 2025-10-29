#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
#define mn 200010
#define ll long long
#define FOR(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
int n;
int a[mn];
int b[mn];
bool f[1000][1000];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("walk.in","r",stdin);
	//freopen("walk.out","w",stdout);
	n=read();
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			if(i==j)continue;
			f[1][j]=1;
			if(i<j)
			dfs(1,j,);
			f[1][j]=0;
		}
	}
	return 0;
}
/*
5
4 -5 9 -2 1
*/
