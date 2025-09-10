#include <iostream>
using namespace std;
int n;
int st[2010],en[2010];
int ans=0x3f3f3f3f;
int ren[5];
int jdz(int a,int b)
{
	return (a>b?a-b:b-a);
}
void dfs(int nxt,int fl,int room,int val)
{
	if(nxt>n && !room) return ans=min(ans,val),void();
	if(room<4 && nxt<=n)
	{
		ren[room+1]=nxt;
		dfs(nxt+1,st[nxt],room+1,val+jdz(fl,st[nxt])+1);
		ren[room+1]=0;
	}
	for(int i=1;i<=room;++i)
	{
		int temp=ren[i];
		for(int j=i+1;j<=4;++j) ren[j-1]=ren[j];
		ren[4]=0;
		dfs(nxt,en[ren[i]],room-1,val+jdz(fl,en[ren[i]])+1);
		for(int j=4;j>i;--j) ren[j]=ren[j-1];
		ren[i]=temp;
	}
}
int read()
{
	int s=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s;
}
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) st[i]=read(),en[i]=read();
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}
