#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,ans[100005],now[100005],nowp,ansp=100000,dlim;
bool flg;
int gcd(int x,int y)
{
	return (y==0?x:gcd(y,x%y));
}
void dfs(int nowd,int na,int nb,int lst)
{
	if(nowd==0)
	{
		if(na==0)
		{
			if(nowp<ansp||now[nowp]<ans[ansp])
			{
				for(int i = 1; i <= nowp; i++) ans[i]=now[i];
				ansp=nowp;
			}
			flg=1;
		}
		return;
	}
	int nowg=gcd(na,nb);
	na/=nowg;
	nb/=nowg;
	if(nb>na*10000000) return;
	nowp++;
	for(int nxt = max(lst+1,(nb+na-1)/na); nowd*nb>=na*nxt; nxt++)
	{
		now[nowp]=nxt;
		dfs(nowd-1,na*nxt-nb,nb*nxt,nxt);
	}
	nowp--;
	return;
}
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>a>>b;
	for(dlim = 1; dlim <= 1000; dlim++)
	{
		dfs(dlim,a,b,1);
		if(flg)
		{
			cout<<ansp<<endl;
			for(int j = 1; j <= ansp; j++)
			{
				cout<<ans[j]<<" ";
			}
			return 0;
		}
	}
}
