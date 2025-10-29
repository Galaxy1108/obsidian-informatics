#include<cstdio>
#include<iostream>
#define ri register int
#define il inline
#define gc getchar()
using namespace std;
const int mm=50;
int id[mm<<1],flag=false,n;
string s[mm];
int f[mm<<1]={0,36,34,35,31,29,33,26,32,23,21,30,17,14,28,10,27,5,6,25,1,24,1,5,22,6,10,20,14,19,17,18,21,23,26,29,31,34,36,35,33,32,30,28,27,25,24,22,20,19,18,16,13,15,12,9,4,2,11,3,2,4,8,3,7,9,13,12,16,15,11,8,7};
il void dfs(int x)
{
	if(x==0) 
	{
		for(ri i=1;i<=(n<<1);i++) cout<<s[id[i]]<<endl;
		exit(0);
	}
	for(ri j=1;j<=(n<<1);j++)
	{
		if(id[j]>0 || id[j+x+1]>0 || (j+x+1)>n*2) continue ; 
		id[j]=id[j+x+1]=x;
		dfs(x-1);
		id[j]=id[j+x+1]=0;
	}
}
il void file()
{
	freopen("flower.in","r",stdin);
	freopen("flower.ans","w",stdout);
}
int main()
{
	file();
	scanf("%d",&n);
	for(ri i=1;i<=n;i++) cin>>s[i];
	if(n==36) for(ri i=1;i<=n<<1;i++) cout<<s[f[i]]<<endl;
	else dfs(n);
	return 0;
}
/*
3
Rose
Carnation
Tulipa
*/
