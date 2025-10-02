#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
void pt(__int128 x)
{
	if(x<=0)return;
	int nw=(x%10);
	pt(x/10);
	cout<<nw;
}
int n,ary[N],lg[N],lt[N],rt[N],st[N][22];
stack<int>stk;
void init()
{
	lg[0]=lg[1]=0;
	for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++)st[i][0]=ary[i];
	for(int k=1;(1<<k)<=n;k++)
		for(int i=1;i+(1<<k)-1<=n;i++)
			st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
}
int que(int l,int r)
{
	int mx=lg[(r-l+1)];
	return max(st[l][mx],st[r-(1<<mx)+1][mx]);
}
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ary[i];
	init();
	for(int i=1;i<=n;i++)
	{
		while(!stk.empty()&&ary[stk.top()]>ary[i])
		{
			rt[stk.top()]=i-1; 
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty())
	{
		rt[stk.top()]=n;
		stk.pop();
	}
	for(int i=n;i>=1;i--)
	{
		while(!stk.empty()&&ary[stk.top()]>ary[i])
		{
			lt[stk.top()]=i+1;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty())
	{
		lt[stk.top()]=1;
		stk.pop();
	}
	__int128 anslt=0;
	for(int i=1;i<=n;i++)
	{
		__int128 res=((__int128)(rt[i]-lt[i]+1))*((__int128)ary[i])*((__int128)que(lt[i],rt[i]));
		if(res>anslt)anslt=res;
	}
	pt(anslt);
	
	return 0;
} 
