#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register
const int N=84+10;
int n;
string s[N];
int wk[N];
bool flg=0;
inline void dfs(int stp)
{
	if(flg)return ;
	if(stp<=0)
	{
		for(re int i=1; i<=n*2; i++)
		{
			if(!wk[i])return ;
			cout<<s[wk[i]]<<endl;
		}
		exit(0);
		flg=1;
		return ;
	}
	if(flg)return ;
	for(re int i=1; i<=n*2 && i+stp+1<=n*2 ; i++)
	{
		if(wk[i]||wk[i+stp+1])continue;
		wk[i]=stp;
		wk[i+stp+1]=stp;
		dfs(stp-1);
		wk[i]=0;
		wk[i+stp+1]=0;
		if(flg)return ;
	}
}
signed main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	n=qread();
	for(re int i=1; i<=n; i++)
	{
		cin>>s[i];
	}
	dfs(n);
	return 0;
}
/*
3
Rose
Carnation
Tulipa

*/
