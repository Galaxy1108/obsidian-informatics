#include<bits/stdc++.h>
using namespace std;
int a,b,ans[100005],now[100005],nowp,ansp=100000,dlim;
bool flg;
int gcd(int x,int y)
{
	return (y==0?x:gcd(y,x%y));
}
void dfs(int nowd,int na,int nb,int lst)
{
	if(nowd>dlim)
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
	if(nb>na*1000000) return;
	nowp++;
	for(int nxt = max(lst+1,(nb+na-1)/na); (dlim-d+1)*b<a*nxt; nxt++)
	{
		now[nowp]=nxt;
		dfs(nowd+1,a*nxt-b,b*nxt,nxt);
	}
	return;
}
int main()
{
	cin>>a>>b;
	for(dlim = 1; dlim <= 1000; dlim++)
	{
		dfs(1,a,b,1);
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
