#include<cstdio>
#include<iostream>
#define ri register int
#define il inline
#define gc getchar()
using namespace std;
const int mm=50;
int id[mm<<1],vis[mm],flag=false,n;
string s[mm];
il void dfs(int x)
{
	if(id[x]!=0) {dfs(x+1);return ;}
	if(x>(n<<1)) 
	{
		for(ri i=1;i<=(n<<1);i++) cout<<s[id[i]]<<endl;
		exit(0);
	}
	for(ri j=n;j>=1;j--)
	{
		if(id[x+j+1]>0 || vis[j] || x+j+1>(n<<1)) continue ; 
		id[x]=id[x+j+1]=j,vis[j]=true;
		dfs(x+1);
		id[x]=id[x+j+1]=0,vis[j]=false;
	}
}
il void file()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
}
int main()
{
	file();
	scanf("%d",&n);
	for(ri i=1;i<=n;i++) cin>>s[i];
	dfs(1);
	return 0;
}
/*
3
Rose
Carnation
Tulipa
*/
