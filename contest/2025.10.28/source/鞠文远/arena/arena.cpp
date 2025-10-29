#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,x,anslt,ary[N],nary[N];
bool pd()
{
	for(int i=1;i<=n;i++)nary[i]=ary[i];
	int al=n;
	while(al>1)
	{
		int cal=al;
		for(int i=1;i<=n;i++)
		{
			if(nary[i]<=0)continue;
			nary[i]-=(cal-1);
			if(nary[i]<=0)al--;;
		}
	}
	return (!al);
}
void dfs(int pos)
{
	if(pos==n+1)
	{
		anslt+=pd();
		return;
	}
	for(int i=1;i<=x;i++)
	{
		ary[pos]=i;
		dfs(pos+1);
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>x;
	dfs(1);
	cout<<anslt;
	
	return 0;
} 
